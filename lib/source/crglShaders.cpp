
#include "crglPrecompiled.hpp"
#include "crglShaders.hpp"

typedef struct glCoreShader_t 
{
    GLenum stage = 0;
    GLuint shader = 0;    
} glCoreShader_t;

typedef struct glCoreProgram_t 
{
    GLbitfield  stages = 0;
    GLuint      program = 0;   
} glCoreProgram_t;

typedef struct glCorePipeline_t 
{
    GLuint  pipeline = 0;
} glCorePipeline_t;


gl::Shader::Shader( void ) : m_shader( nullptr )
{
}

gl::Shader::~Shader( void )
{
    Destroy();
}

bool gl::Shader::Create( const GLenum in_stage,const GLchar *const* in_sources, const GLint *in_lengths,  const GLsizei in_count )
{
    GLint success = GL_FALSE;
    // make surre that shader is clears
    Destroy();

    m_shader = new glCoreShader_t();
    m_shader->stage = in_stage;

    // create shader object 
    m_shader->shader = glCreateShader( m_shader->stage );
    if ( m_shader->shader == 0 )
        return false;

    // load shader sources on driver compiler 
    glShaderSource( m_shader->shader, in_count, in_sources, in_lengths );

    // compile shader source
    glCompileShader( m_shader->shader );

    // check shader compilation
    glGetShaderiv( m_shader->shader, GL_COMPILE_STATUS, &success);
    if ( success == GL_FALSE )
    {
        glDeleteShader( m_shader->shader ); // Don't leak the shader.
        return false;
    }

    return true;
}

void gl::Shader::Destroy( void )
{
    if ( m_shader == nullptr )
        return;

    if ( m_shader->shader != 0 )
    {
        glDeleteShader( m_shader->shader );
        m_shader->shader = 0;
    }
    
    delete m_shader;
    m_shader = nullptr;
}

void gl::Shader::GetLog( GLint *in_length, GLchar *in_infoLog )
{
    GLint length = 0;
    glGetShaderiv( m_shader->shader, GL_INFO_LOG_LENGTH, &length );

    // just get log size 
    if ( in_length == nullptr )
        *in_length = length;

    if ( in_infoLog && length > 0 )
        glGetShaderInfoLog( m_shader->shader, length, nullptr, in_infoLog );
}

gl::Shader::operator GLuint(void) const
{
    if ( m_shader == nullptr )
        return 0;

    return m_shader->shader;    
}

gl::Program::Program( void ) : m_program( nullptr )
{
}

gl::Program::~Program( void )
{
    Destroy();
}

bool gl::Program::Create( const Shader** in_shaders, const GLsizei in_count )
{
    GLint isLinked = 0;
    // certify that we are using a clean shader 
    Destroy();

    m_program = new glCoreProgram_t();
    m_program->program = glCreateProgram();

    for ( GLsizei i = 0; i < in_count; i++)
    {
        glCoreShader_t* shader = static_cast<glCoreShader_t*>( *in_shaders[i] );

        if (  shader == nullptr ) 
        {
                // TODO: implement a erro
                return false;
        }
            
        glAttachShader( m_program->program, shader->shader );

        switch ( shader->stage )
        {
        case GL_VERTEX_SHADER:
            m_program->stages |= GL_VERTEX_SHADER_BIT;
            break;
        case GL_TESS_CONTROL_SHADER:
            m_program->stages |= GL_TESS_CONTROL_SHADER_BIT;
            break;
        case GL_TESS_EVALUATION_SHADER:
            m_program->stages |= GL_TESS_EVALUATION_SHADER_BIT;
            break;
        case GL_GEOMETRY_SHADER:
            m_program->stages |= GL_GEOMETRY_SHADER_BIT;
            break;
        case GL_FRAGMENT_SHADER:
            m_program->stages |= GL_FRAGMENT_SHADER_BIT;
            break;
        case GL_COMPUTE_SHADER:
            m_program->stages |= GL_COMPUTE_SHADER_BIT;
            break;
#if 0 // TODO: implement mesh shaders ?
        case GL_MESH_SHADER_NV: 
            m_program->stages |= GL_MESH_SHADER_BIT_NV;
            break;
#endif
        default:
            break;
        }
    }

    // Link our shaders in program
    glLinkProgram( m_program->program );
    
    // Always detach shaders after a successful link
    for ( GLsizei i = 0; i < in_count; i++)
    {
        glDetachShader( m_program->program, static_cast<glCoreShader_t*>( *in_shaders[i] )->shader );
    }

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    glGetProgramiv( m_program->program, GL_LINK_STATUS, &isLinked );
    if ( isLinked == GL_FALSE )
    {
	    // We don't need the program anymore.
	    glDeleteProgram( m_program->program );
        return false;   
    }

    return m_program->program != 0;
}

void gl::Program::Destroy( void )
{
    if ( m_program == nullptr )
        return;

    if ( m_program->program != 0 )
    {
        glDeleteProgram( m_program->program );
        m_program->program = 0;
    }
    
    delete m_program;
    m_program = nullptr;
}

void gl::Program::GetLog( GLint *in_length, GLchar *in_infoLog )
{
    GLint length = 0;
    glGetProgramiv( m_program->program, GL_INFO_LOG_LENGTH, &length );

    // just get log size 
    if ( in_length == nullptr )
        *in_length = length;

    if ( in_infoLog && length > 0 )
        glGetProgramInfoLog( m_program->program, length, in_length, in_infoLog );
}

gl::Program::operator GLuint( void ) const
{
    if ( m_program == nullptr )
        return 0;
    
    return m_program->program;
}
 
gl::ProgramPipeline::ProgramPipeline( void ) : m_pipeline( nullptr )
{
}

gl::ProgramPipeline::~ProgramPipeline( void )
{
}

bool gl::ProgramPipeline::Create( void )
{
    Destroy();

    m_pipeline = new glCorePipeline_t();
    glCreateProgramPipelines( 1, &m_pipeline->pipeline );

    return m_pipeline->pipeline != 0;
}

void gl::ProgramPipeline::Destroy( void )
{
    if ( m_pipeline == nullptr )
        return;
    
    if ( m_pipeline->pipeline )
    {
        glDeleteProgramPipelines( 1, &m_pipeline->pipeline );
        delete m_pipeline;
    }
}

void gl::ProgramPipeline::UseProgram( const Program** in_program, const uint32_t in_count )
{
    for ( uint32_t i = 0; i < in_count; i++)
    {
        auto program = static_cast<glCoreProgram_t*>( *in_program[i] );
        glUseProgramStages( m_pipeline->pipeline, program->program, program->stages );
    }
}

void gl::ProgramPipeline::GetLog( GLint *in_length, GLchar *in_infoLog )
{
    GLint length = 0;
    glGetProgramPipelineiv( m_pipeline->pipeline, GL_INFO_LOG_LENGTH, &length );

    // just get log size 
    if ( in_length == nullptr )
        *in_length = length;

    if ( in_infoLog && length > 0 )
        glGetProgramInfoLog( m_pipeline->pipeline, length, in_length, in_infoLog );
}

gl::ProgramPipeline::operator GLuint( void ) const
{
    if ( m_pipeline == nullptr )
        return 0;

    return m_pipeline->pipeline;
}
