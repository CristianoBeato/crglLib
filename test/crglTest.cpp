
#include "crglTest.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include <exception>

#include <crglCore.hpp>

typedef struct vec2
{
    float x = 0.0f;
    float y = 0.0f;
} vec2;

typedef struct vec3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
} vec3;

typedef struct bvec3
{
    uint8_t x = 0x00;
    uint8_t y = 0x00;
    uint8_t z = 0x00;
} bvec3;

typedef struct crVertexPos
{
    vec3 pos;
    vec2 uv;
} crVertexPos;

typedef struct crVertexColor
{
    bvec3 color;
} crVertexColor;

const GLushort indices[6] = 
{
    0, 1, 2,
    2, 1, 3
};

const crVertexPos positions[8] = 
{
    // non fliped for frame buffer
    // vertex positions         uv coordinate   
    { {  0.75f, -0.75f, 0.0f }, { 1.0f, 0.0f } }, // RT
    { {  0.75f,  0.75f, 0.0f }, { 1.0f, 1.0f } }, // RB
    { { -0.75f, -0.75f, 0.0f }, { 0.0f, 0.0f } }, // LT
    { { -0.75f,  0.75f, 0.0f }, { 0.0f, 1.0f } }, // LB

    // fliped for texture
    { {  0.75f, -0.75f, 0.0f }, { 1.0f, 1.0f } }, // RT
    { {  0.75f,  0.75f, 0.0f }, { 1.0f, 0.0f } }, // RB
    { { -0.75f, -0.75f, 0.0f }, { 0.0f, 1.0f } }, // LT
    { { -0.75f,  0.75f, 0.0f }, { 0.0f, 0.0f } }, // LB
};

const crVertexColor colors[4] = 
{
    { 0xFF, 0x00, 0x00 },    // RT ( full red )
    { 0x00, 0xFF, 0x00 },    // RB ( full green )
    { 0x00, 0x00, 0xFF },    // LT ( full blue )
    { 0xFF, 0x00, 0xFF },     // LB ( full magenta )
};

static void CreateShader( gl::Shader* in_shader, const GLenum in_stage, const char* in_path );
static void CreateImage( gl::Image * image, const char* in_path );

int main( int argc, char *argv[] )
{
    crApp app = crApp();
    try
    {
        app.Run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    
    return 0;
}

crTestContext::crTestContext( void ) : 
    m_renderWindown( nullptr ), 
    m_renderContext( nullptr )
{
}

crTestContext::~crTestContext( void )
{
}

bool crTestContext::Create( const void* in_windowHandle )
{
    m_renderWindown = (SDL_Window*)in_windowHandle;

    m_renderContext = SDL_GL_CreateContext( m_renderWindown );
    if ( !m_renderContext )
        return false;
    
    Init();

    return true;
}

void crTestContext::Destroy( void )
{
    if ( m_renderContext != nullptr )
    {
        SDL_GL_DestroyContext( m_renderContext );
        m_renderContext = nullptr;
    }
}

bool crTestContext::MakeCurrent( void )
{
    return SDL_GL_MakeCurrent( m_renderWindown, nullptr );
}

bool crTestContext::Release( void )
{
    // make it true
    return SDL_GL_MakeCurrent( m_renderWindown, nullptr );
}

bool crTestContext::SwapBuffers( void )
{
    return SDL_GL_SwapWindow( m_renderWindown );
}

void* crTestContext::GetFunctionPointer( const char* in_name ) const
{
    return (void*)SDL_GL_GetProcAddress( in_name );
}

void crTestContext::DebugOuput( const char* in_message ) const
{
    std::cerr << in_message << std::endl;
}

crApp::crApp( void ) : 
    m_window( nullptr ),
    m_ctx( nullptr ),
    m_program( nullptr ),
    m_vertexArray( nullptr ),
    m_index( nullptr ),
    m_vertexPos( nullptr ),
    m_vertexCol( nullptr ),
    m_framebuffer( nullptr ),
    m_framebufferAttach( nullptr ),
    m_image( nullptr ),
    m_sampler( nullptr )
{
}

crApp::~crApp( void )
{
}

void crApp::Run( void )
{
    try
    {
        InitSDL3();
        InitOpenGL();
        MainLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //
    FinishOpenGL();
    FinishSDL3();
}

void crApp::InitSDL3( void )
{
    // initialize SDL3 library 
    if( !SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) )
        throw std::runtime_error( SDL_GetError() );

    // try load local OpenGL library
    if( !SDL_GL_LoadLibrary( nullptr ) )
        throw std::runtime_error( SDL_GetError() );

    m_window = SDL_CreateWindow( "SDL::GL4.5 Test", 800, 600, SDL_WINDOW_OPENGL );
    if ( !m_window )
    {
        throw std::runtime_error( SDL_GetError() );
    }    
}

void crApp::FinishSDL3( void )
{
    if ( m_window != nullptr )
    {
        SDL_DestroyWindow( m_window );
        m_window = nullptr;
    }
    
    // Releasing the openGL library
    SDL_GL_UnloadLibrary();

    // clear sdl3
    SDL_Quit();
}

void crApp::MainLoop( void )
{
    bool running = true;
    while ( running )
    {
        SDL_Event evt{};
        while ( SDL_PollEvent( &evt ) )
        {
            switch ( evt.type )
            {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            case SDL_EVENT_QUIT:
                running = false;
                break;
            
            default:
                break;
            }
        }
        
        RenderFrame();
    }
    
}

void crApp::RenderFrame(void)
{
    GLuint texture[1]{ 0 };
    GLuint samples[1]{ 0 };

    m_ctx->BindVertexArray( *m_vertexArray );
    m_ctx->BindProgram( *m_program );

    //_________________________________ DRAW TO FRAME BUFFER _________________________________ 

    // bind the frame buffer
    m_ctx->BindFrameBuffer( *m_framebuffer );

    // set the viewport to our frame buffer size
    glViewport(0, 0, 640, 420 ); 

    // Clear our custom frame buffer colot to dark orange
    glClearColor( 0.5f, 0.2f, 0.1, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    // bind texture and samples
    texture[0] = m_image->Handle();
    samples[0] = m_sampler->Handler();
    m_ctx->BindTextures( texture, samples, 0, 1 );

    // draw to the frame buffer 
    //glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0 );
    glDrawElementsBaseVertex( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0, 4 ); // we use a fliped UV vertex now

    //_________________________________ DRAW TO SCREEN _________________________________ 

    // bind back the defalt frame buffer
    m_ctx->BindFrameBuffer( 0 );

    // set the viewport to our screen size
    glViewport(0, 0, 800, 600 ); 

    // clear defalt frame buffer color dark gray
    glClearColor( 0.2f, 0.2f, 0.2, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    texture[0] = m_framebufferAttach->Handle();
    samples[0] = m_sampler->Handler(); // use the same sampler
    m_ctx->BindTextures( texture, samples, 0, 1 );

    // draw 
    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (void*)0 );

    // show to screen 
    m_ctx->SwapBuffers();
}

void crApp::InitOpenGL( void )
{
    m_ctx = new crTestContext();
    if( !m_ctx->Create( m_window ) )
        throw std::runtime_error( "can't create render context!");

    m_vertexArray = new gl::VertexArray();
    
    gl::vertexAttrib_t    vertexAttribs[3] = 
    {
        // element index, buffer binding, num elements, elements types, are normalized, offsets  
        { 0, 0, 3, GL_FLOAT, GL_FALSE, 0  },
        { 1, 0, 2, GL_FLOAT, GL_FALSE, 12 },
        { 2, 1, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0 }
    };

    m_vertexArray->Create( vertexAttribs, 3 );

    // create index buffer 
    m_index = new gl::Buffer();
    m_index->Create( GL_ELEMENT_ARRAY_BUFFER, sizeof( GLushort ) * 6, nullptr, GL_DYNAMIC_STORAGE_BIT );
    m_index->Upload( indices, 0, sizeof( GLushort ) * 6 ); // upload indices to GPU
    
    // create vertex position buffer 
    m_vertexPos = new gl::Buffer();
    m_vertexPos->Create( GL_VERTEX_ARRAY, sizeof( crVertexPos ) * 8, nullptr, GL_DYNAMIC_STORAGE_BIT );
    m_vertexPos->Upload( positions, 0, sizeof( crVertexPos ) * 8 );    // upload vertex buffer

    // create vertex color buffer
    m_vertexCol = new gl::Buffer();
    m_vertexCol->Create( GL_VERTEX_ARRAY, sizeof( crVertexColor ) * 4, nullptr, GL_DYNAMIC_STORAGE_BIT );
    m_vertexCol->Upload( colors, 0, sizeof( crVertexColor ) * 4 );    // upload vertex buffer

    m_vertexArray->BindElementBuffer( *m_index ); // bind element buffer
    
    // bind vertex buffers 
    GLuint      vbuffers[2]{ *m_vertexPos, *m_vertexCol };
    GLintptr    voffsets[2]{ 0, 0 };
    GLsizei     vstrides[2]{ sizeof( crVertexPos ), sizeof( crVertexColor ) };
    m_vertexArray->BindeVertexBuffers( vbuffers, voffsets, vstrides, 0, 2 );

    // Create framebuffer attachament
    gl::Image::dimensions_t dim{};
    dim.width = 640;
    dim.height = 420;
    m_framebufferAttach = new gl::Image();
    m_framebufferAttach->Create( GL_TEXTURE_2D, GL_RGBA8, 1, 0, dim );

    // create framebuffer
    gl::FrameBuffer::attachament_t attch{};
    attch.target = GL_TEXTURE_2D;
    attch.attachament = GL_COLOR_ATTACHMENT0;
    attch.handle = *m_framebufferAttach;
    
    m_framebuffer = new gl::FrameBuffer();
    m_framebuffer->Create();
    m_framebuffer->Attach( &attch, 0, 1 );

    // create and load texture
    m_image = new gl::Image();
    CreateImage( m_image, "image/grid.bmp" );

    m_sampler = new gl::Sampler();
    m_sampler->Create();

    // magnification and minification texture filtering ( trilinear ) 
    m_sampler->Parameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    m_sampler->Parameteri( GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    // texture repeating ( no repeat )
    m_sampler->Parameteri( GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER );
    m_sampler->Parameteri( GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER );

    // Create program
    m_program = new gl::Program();
    
    // Create vertex shader
    gl::Shader* vertex = new gl::Shader();
    CreateShader( vertex, GL_VERTEX_SHADER, "shaders/test_shader.vert" );

    // Create fragment shader
    gl::Shader* fragment = new gl::Shader();
    CreateShader( fragment, GL_FRAGMENT_SHADER, "shaders/test_shader.frag" );

    const gl::Shader* shaders[2] = { vertex, fragment };
    if( !m_program->Create( shaders, 2 ) )
        throw std::runtime_error( "failed to link program!" );

    if ( vertex != nullptr )
    {
        vertex->Destroy();
        delete vertex;
    }
    
    if ( fragment != nullptr )
    {
        fragment->Destroy();
        delete fragment;
    }
}

void crApp::FinishOpenGL( void )
{
    if ( m_program != nullptr )
    {
        m_program->Destroy();
        delete m_program;
    }
    
    if ( m_vertexCol != nullptr )
    {
        m_vertexCol->Destroy();
        delete m_vertexCol;
        m_vertexCol = nullptr;
    }
    
    if ( m_vertexPos != nullptr )
    {
        m_vertexPos->Destroy();
        delete m_vertexPos;
        m_vertexPos = nullptr;
    }

    if( m_sampler != nullptr )
    {
        m_sampler->Destroy();
        delete m_sampler;
        m_sampler = nullptr;
    }
    
    if ( m_image != nullptr )
    {
        m_image->Destroy();
        delete m_image;
    }
    
    if( m_framebuffer != nullptr )
    {
        m_framebuffer->Destroy();
        delete m_framebuffer;
        m_framebuffer = nullptr;
    }

    if ( m_framebufferAttach != nullptr )
    {
        m_framebufferAttach->Destroy();
        delete m_framebufferAttach;
        m_framebufferAttach = nullptr;
    }
    

    if ( m_index != nullptr )
    {
        m_index->Destroy();
        delete m_index;
        m_index = nullptr;
    }

    if ( m_vertexArray != nullptr )
    {
        m_vertexArray->Destroy();
        delete m_vertexArray;
        m_vertexArray = nullptr;
    }
    
    if ( m_ctx != nullptr )
    {
        m_ctx->Destroy();
        delete m_ctx;
        m_ctx = nullptr;
    }
}

void CreateShader( gl::Shader* in_shader, const GLenum in_stage, const char* in_path )
{
    GLint sourceSize = 0;
    GLchar* source = nullptr;
    FILE* sourceFile = fopen( in_path, "r" );
    if ( !sourceFile )
    {
        throw std::runtime_error( "can't read shader" );
    }

    // get the file size 
    fseek( sourceFile, 0, SEEK_END );
    sourceSize = ftell( sourceFile );
    fseek( sourceFile, 0, SEEK_SET );

    source = static_cast<GLchar*>( std::malloc( sourceSize ) );

    // read file 
    fread( source, sizeof( GLchar ), sourceSize, sourceFile );
    // release file 
    fclose( sourceFile );

    in_shader->Create( in_stage, &source, &sourceSize, 1 );

    std::free( source );
    source = nullptr;
}

void CreateImage( gl::Image * image, const char* in_path )
{
    GLenum internalFormat = GL_NONE;
    SDL_Surface* imageSurf = SDL_LoadBMP( in_path );
    if ( !imageSurf )
        throw std::runtime_error( SDL_GetError() );

    switch ( imageSurf->format )
    {
    case SDL_PIXELFORMAT_RGBA4444:
        internalFormat = GL_RGBA4;
        break;
    case SDL_PIXELFORMAT_RGBA5551:
        internalFormat = GL_RGB5_A1;
        break;
    case SDL_PIXELFORMAT_RGB565:
        internalFormat = GL_RGB565;
        break;
    case SDL_PIXELFORMAT_RGB24:
        internalFormat = GL_RGB8;
        break;
    case SDL_PIXELFORMAT_BGR24:
        internalFormat = GL_RGB8;
        break;
    case SDL_PIXELFORMAT_RGBA8888:
        internalFormat = GL_RGBA8UI;
        break;
    
    default:
        throw std::runtime_error( "unsuported image format" );
        break;
    }

    // Create the image
    gl::Image::dimensions_t dim{};
    dim.width = imageSurf->w;
    dim.height = imageSurf->h;
    dim.depth = 0;
    image->Create( GL_TEXTURE_2D, internalFormat, 1, 1, dim );
    
    gl::Image::offsets_t offsets{ 0, 0, 0 };
    
    // upload image
    image->SubImage( 0, offsets, dim, imageSurf->pixels, true );

    SDL_DestroySurface( imageSurf );
}

