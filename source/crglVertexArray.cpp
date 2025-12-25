#include "crglPrecompiled.hpp"
#include "crglVertexArray.hpp"

static const char k_INVALID_ELEMENT_BUFFER_MSG[76] = "gl::VertexArray::BindElementBuffer not recived a valid buffer name as input";
static const char k_INVALID_VERTEX_BUFFER_MSG[77] = "gl::VertexArray::BindeVertexBuffers not recived a valid buffer name as input";

typedef struct glCoreVertexArray_t
{
    GLuint  vertexArray = 0;
    GLuint  elementBuffer = 0;
    GLuint  numVertexBuffers = 0;
    GLuint* vertexBuffers = nullptr;
}glCoreVertexArray_t;

gl::VertexArray::VertexArray( void ) : m_vertexArray( nullptr )
{
}

gl::VertexArray::~VertexArray( void )
{
}

void gl::VertexArray::Create( const vertexAttrib_t* in_vertexAttrib, const GLuint in_count )
{
    // make surre that we are clear beffore create a new 
    Destroy();

    m_vertexArray = new glCoreVertexArray_t();

    // Create the vertex array
    glCreateVertexArrays( 1, &m_vertexArray->vertexArray );

    for ( uint32_t i = 0; i < in_count; i++)
    {
        auto attrb = in_vertexAttrib[i];
        
        //
        glEnableVertexArrayAttrib( m_vertexArray->vertexArray, attrb.index );
        glVertexArrayAttribBinding( m_vertexArray->vertexArray, attrb.index, attrb.binding );
        glVertexArrayAttribFormat( m_vertexArray->vertexArray, attrb.index, attrb.size, attrb.type, attrb.normalized, attrb.relativeoffset );
    }   
}

void gl::VertexArray::Destroy( void )
{
    if ( m_vertexArray == nullptr )
        return;
    
    // 
    if ( m_vertexArray->vertexBuffers != nullptr )
    {
        std::free( m_vertexArray->vertexBuffers );
        m_vertexArray->vertexBuffers = nullptr;
    }
    
    // release alloced memory
    if ( m_vertexArray->vertexBuffers != nullptr )
    {
        std::free( m_vertexArray->vertexBuffers );
        m_vertexArray->vertexBuffers = nullptr;
    }

    // destroy vertex array container
    if ( m_vertexArray->vertexArray != 0 )
    {
        glDeleteVertexArrays( 1, &m_vertexArray->vertexArray );
        m_vertexArray->vertexArray = 0;
    }
    
    delete m_vertexArray;
    m_vertexArray = nullptr;
}

void gl::VertexArray::BindElementBuffer( const GLuint in_buffer )
{
#if !defined( NDEBUG ) // we don't check on releases 
    if ( glIsBuffer( in_buffer ) != GL_TRUE )
    {
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 76, k_INVALID_ELEMENT_BUFFER_MSG );
        return;
    }
#endif 
    
    // if are not current buffer, bind 
    if ( m_vertexArray->elementBuffer != in_buffer )
    {
        glVertexArrayElementBuffer( m_vertexArray->vertexArray, in_buffer );
        m_vertexArray->elementBuffer = in_buffer;
    }
}

void gl::VertexArray::BindeVertexBuffers( const GLuint *in_buffers, const GLintptr *in_offsets, const GLsizei *in_strides, const GLuint in_first, const GLsizei in_count )
{
    GLuint bufferCount = in_first + in_count; //
    
    // realloc buffers to fit 
    if ( m_vertexArray->numVertexBuffers < bufferCount )
    {
        if ( m_vertexArray->vertexBuffers == nullptr )
            m_vertexArray->vertexBuffers = static_cast<GLuint*>( std::malloc( sizeof( GLuint ) * bufferCount ) );
        else
            m_vertexArray->vertexBuffers = static_cast<GLuint*>( std::realloc( m_vertexArray->vertexBuffers, sizeof( GLuint ) * bufferCount ) );
        m_vertexArray->numVertexBuffers = bufferCount; 
    }
    
    //store buffer binding, and check
    for ( GLsizei i = in_first; i < in_count; i++)
    {
#if !defined( NDEBUG ) // we don't check on releases 
        if ( glIsBuffer( in_buffers[i] ) != GL_TRUE )
        {
            glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 77, k_INVALID_VERTEX_BUFFER_MSG );
            return;
        }
#endif

        m_vertexArray->vertexBuffers[i] = in_buffers[i];
    }

    // bind buffers
    glVertexArrayVertexBuffers( m_vertexArray->vertexArray, in_first, in_count, in_buffers, in_offsets, in_strides );        

}

GLuint gl::VertexArray::GetHandle( void ) const
{
    return m_vertexArray->vertexArray;
}

gl::VertexArray::operator    GLuint( void ) const
{
    return m_vertexArray->vertexArray;
}
