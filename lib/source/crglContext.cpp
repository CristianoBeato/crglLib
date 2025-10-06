/*
===========================================================================================
    This file is part of crglLib OpenGL core c++ framework.

    Copyright (c) 2025 Cristiano B. Santos <cristianobeato_dm@hotmail.com>
    Contributor(s): none yet.

-------------------------------------------------------------------------------------------

 This file is part of the crglLib library and is licensed under the
 MIT License with Attribution Requirement.

 You are free to use, modify, and distribute this file (even commercially),
 as long as you give credit to the original author:

     “Based on crglCore by Cristiano Beato – https://github.com/CristianoBeato”

 For full license terms, see the LICENSE file in the root of this repository.
===============================================================================================
*/

#include "crglPrecompiled.hpp"
#include "crglContext.hpp"

#if 0
#if defined( _WIN32 )
#   include <wingdi.h>
extern PROC wglGetProcAddress( LPCSTR unnamedParam1 );
#else
typedef void ( *__GLXextFuncPtr)(void);
extern __GLXextFuncPtr glXGetProcAddressARB (const GLubyte *);
#endif
#endif

static const char k_INVALID_VERTEX_ARRAY_MSG[76] = "crglContext::BindVertexArray not recived a valid vertex array name as input";
static const char k_INVALID_FRAME_BUFFER_MSG[75] = "crglContext::BindFrameBuffer not recived a valid FrameBuffer name as input";

gl::Context::Context( void )
{
}

gl::Context::~Context( void )
{
    Destroy();
}

void gl::Context::Destroy(void)
{
    Finalize();
}

#if 0
void*   crglContext::GetFunctionPointer( const char* in_name ) const
{
#if defined( _WIN32 )
    return (void*)wglGetProcAddress( (LPCSTR)in_name );
#else
    return (void*)glXGetProcAddressARB( (const GLubyte*)in_name ); 
#endif
}
#else
void* gl::Context::GetFunctionPointer( const char* in_name ) const
{
    return nullptr;
}
#endif

bool gl::Context::Init( void )
{
    LoadFunctions();

    // enable debug
    glEnable( GL_DEBUG_OUTPUT);
    // To lock on error (synchronized debug)
    glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS ); 

    glDebugMessageCallback( DebugOutputCall, this ); // set callback
    glDebugMessageControl( GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE ); // Ativa tudo

    // Get context properties

    // max texture units
    glGetIntegerv( GL_MAX_TEXTURE_IMAGE_UNITS, &m_features.maxTextures );
    glGetIntegerv( GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_features.maxCombined );

    // max buffer bindings 
    glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &m_features.maxUBOBindings );
    glGetIntegerv(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, &m_features.maxSSBOBindings );
    glGetIntegerv(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS, &m_features.maxAtomicBindings );
    glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS, &m_features.maxTFBindings );

    glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &m_features.maxVBOBindings );

    //
    glGetIntegerv( GL_MAX_VERTEX_ATTRIBS, &m_features.maxVertexAttribs );
    
    // create the binding array
    m_state.textures.samplers = static_cast<GLuint*>( std::malloc( sizeof( GLuint ) * m_features.maxCombined ) );
    m_state.textures.textures = static_cast<GLuint*>( std::malloc( sizeof( GLuint ) * m_features.maxCombined ) );
    
    // create the shader buffers binding arrays
    m_state.programs.uniformBuffers = static_cast<GLuint*>( std::malloc( sizeof( GLuint ) * m_features.maxUBOBindings ) );
    m_state.programs.shaderStorageBuffers = static_cast<GLuint*>( std::malloc( sizeof( GLuint ) * m_features.maxUBOBindings ) );

    return true;
}

void gl::Context::Finalize( void )
{
    std::free( m_state.programs.uniformBuffers );
    m_state.programs.uniformBuffers = nullptr;
    
    std::free( m_state.programs.shaderStorageBuffers );
    m_state.programs.shaderStorageBuffers = nullptr;

    std::free( m_state.textures.samplers );
    m_state.textures.samplers = nullptr;
    
    std::free( m_state.textures.textures );
    m_state.textures.textures = nullptr;   
}

void gl::Context::Clear( void )
{
    if ( m_state.indirectDrawBuffer )
    {
        glBindBuffer( GL_DRAW_INDIRECT_BUFFER, 0 );
        m_state.indirectDrawBuffer = 0;
    }
    
    if ( m_state.programs.uniformBuffers )
    {
        // unbind all buffers 
        std::memset( m_state.programs.uniformBuffers, 0x00, sizeof( GLuint ) *  m_features.maxUBOBindings );
        glBindBuffersBase( GL_UNIFORM_BUFFER, 0,  m_features.maxUBOBindings, m_state.programs.uniformBuffers );        
    }

    if ( m_state.programs.shaderStorageBuffers )
    {
        // unbind all buffers 
        std::memset( m_state.programs.shaderStorageBuffers, 0x00, sizeof( GLuint ) * m_features.maxSSBOBindings );
        glBindBuffersBase( GL_SHADER_STORAGE_BUFFER, 0, m_features.maxSSBOBindings, m_state.programs.shaderStorageBuffers );        
    }
}

void gl::Context::Flush( void )
{
    glFlush();
}

void gl::Context::Finish( void )
{
    glFinish();
}

GLuint gl::Context::BindProgram( const GLuint in_program )
{
    GLuint current = m_state.programs.program;
    
    // disable pipeline 
    if ( m_state.programs.pipeline != 0 )
    {
        glBindProgramPipeline( 0 );
        m_state.programs.pipeline = 0;
    }

    if ( current != in_program )
    {
        // bind the program 
        glUseProgram( in_program );
        m_state.programs.program = in_program;
    }
    
    return current;
}

GLuint gl::Context::BindPipeline(const GLuint in_pipeline)
{
    GLuint current = m_state.programs.program;

    // disble program 
    if ( m_state.programs.program != 0 )
    {
        glUseProgram( 0 );
        m_state.programs.program = 0;
    }

    if ( current != in_pipeline )
    {
        // bind the program 
        glBindProgramPipeline( in_pipeline );
        m_state.programs.pipeline = in_pipeline;
    }

    return current;
}

GLuint gl::Context::BindVertexArray( const GLuint in_vertexArray )
{
    // current bind vertex array
    GLuint current = m_state.vertexArray;

#if !defined( NDEBUG ) // we don't check on releases  
    if ( glIsVertexArray( in_vertexArray ) != GL_TRUE )
    {
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 76, k_INVALID_VERTEX_ARRAY_MSG );
        return current;
    }
#endif // !NDEBUG

    if ( current != in_vertexArray )
    {
        glBindVertexArray( in_vertexArray );
        m_state.vertexArray = in_vertexArray;
    }
    
    return current;
}

GLuint gl::Context::BindFrameBuffer(const GLuint in_framebuffer)
{
// current bind vertex array
    GLuint current = m_state.frameBuffer;

#if !defined( NDEBUG ) // we don't check on releases  
    if ( ( in_framebuffer != 0 ) && ( glIsFramebuffer( in_framebuffer  ) != GL_TRUE ) )
    {
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 75, k_INVALID_FRAME_BUFFER_MSG );
        return current;
    }
#endif // !NDEBUG

    if ( current != in_framebuffer )
    {
        glBindFramebuffer( GL_FRAMEBUFFER, in_framebuffer );
        m_state.frameBuffer = in_framebuffer;
    }
    
    return current;
}

GLuint gl::Context::BindIndirectBuffer( const GLuint in_buffer )
{
    GLuint current = m_state.indirectDrawBuffer;
    if ( current != in_buffer )
    {
        glBindBuffer( GL_DRAW_INDIRECT_BUFFER, in_buffer );
        m_state.indirectDrawBuffer = in_buffer;
    }

    
    
    return current;
}

GLuint gl::Context::BindUniformBuffers(const GLuint *in_buffers, const GLintptr *in_offsets, const GLsizeiptr *in_sizes, const GLuint in_first, const GLsizei in_count )
{
    // todo clamp to the max suported buffers
    std::memcpy( &m_state.programs.uniformBuffers[in_first], in_buffers, sizeof( GLuint ) * in_count );
    glBindBuffersRange( GL_UNIFORM_BUFFER, in_first, in_count, in_buffers, in_offsets, in_sizes );
    return 0; //TODO: change
}

GLuint gl::Context::BindShaderStorageBuffers(const GLuint *in_buffers, const GLintptr *in_offsets, const GLsizeiptr *in_sizes, const GLuint in_first, const GLsizei in_count)
{
    // todo clamp to the max suported buffers
    std::memcpy( &m_state.programs.shaderStorageBuffers[in_first], in_buffers, sizeof( GLuint ) * in_count );
    glBindBuffersRange( GL_SHADER_STORAGE_BUFFER, in_first, in_count, in_buffers, in_offsets, in_sizes );
    return 0; //TODO:
}

GLuint gl::Context::BindTextures(const GLuint *in_textures, const GLuint *in_samplers, const GLuint in_first, const GLuint in_count)
{
    if( ( in_first + in_count ) > static_cast<GLuint>( m_features.maxCombined ) )
    {
        // todo: return a error
        return std::numeric_limits<GLuint>::max();
    }

    std::memcpy( &m_state.textures.textures[in_first], in_textures, sizeof( GLuint ) * in_count );    
    std::memcpy( &m_state.textures.samplers[in_first], in_samplers, sizeof( GLuint ) * in_count );

    glBindTextures( in_first, in_count, in_textures );
    glBindSamplers( in_first, in_count, in_samplers );
    return GLuint();
}

void APIENTRY gl::Context::DebugOutputCall( GLenum in_source, GLenum in_type, GLuint in_id, GLenum in_severity, GLsizei in_length, const GLchar *in_message, const void *in_userParam )
{
    const char * source = nullptr;
    const char * type = nullptr;
    const char * severity = nullptr;
    char message[512];
    const Context *ctx = static_cast<const Context*>( in_userParam );

    switch ( in_source )
    {
    case GL_DEBUG_SOURCE_API:
        source = "Source: API";
        break;

    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        source = "Source: Window System";
        break;

    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        source = "Source Shader Compiler";
        break;

    case GL_DEBUG_SOURCE_THIRD_PARTY:
        source = "Source Third Party";
        break;

    case GL_DEBUG_SOURCE_APPLICATION:
        source = "Source Application";
        break;

    case GL_DEBUG_SOURCE_OTHER:
        source = "Source Other";
        break;
    
    default:
        source = "Source Unknow";
        break;
    }

    switch ( in_type )
    {
    case GL_DEBUG_TYPE_ERROR:
        type = "Type ERROR";
        break;

    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        type = "Type Deprecated Behaviour";
        break;

    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        type = "Type Undefined Behaviour";
        break;

    case GL_DEBUG_TYPE_PORTABILITY:
        type = "Type Portability";
        break;

    case GL_DEBUG_TYPE_PERFORMANCE:
        type = "Type Performance";
        break;

    case GL_DEBUG_TYPE_MARKER:
        type = "Type Marker";
        break;

    case GL_DEBUG_TYPE_PUSH_GROUP:
        type = "Type Push Group";
        break;

    case GL_DEBUG_TYPE_POP_GROUP:
        type = "Type Pop Group";
        break;

    case GL_DEBUG_TYPE_OTHER:
        type = "Type Other";
        break;

    default:
        break;
    }

    switch ( in_severity )
    {
    case GL_DEBUG_SEVERITY_HIGH:
        severity = "High Severity";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        severity = "Medium Severity";
        break;
    case GL_DEBUG_SEVERITY_LOW:
        severity = "Low Severity";
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        severity = "Low Severity";
        break;
    default:
        severity = "Unknow Severity level";
        break;
    }

    std::snprintf( message, 512, "OpenGL Info: %s %s, from %s :\n * %s", type, severity, source, in_message );

    ctx->DebugOuput( message );
}
