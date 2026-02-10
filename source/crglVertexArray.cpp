#include "crglPrecompiled.hpp"
#include "crglVertexArray.hpp"

static const char k_INVALID_ELEMENT_BUFFER_MSG[76] = "gl::VertexArray::BindElementBuffer not recived a valid buffer name as input";
static const char k_INVALID_VERTEX_BUFFER_MSG[77] = "gl::VertexArray::BindeVertexBuffers not recived a valid buffer name as input";

typedef struct glCoreVertexArray_t
{
    GLuint                                  vertexArray = 0;
    GLuint                                  elementBuffer = 0;
    GLuint                                  numVertexBuffers = 0;
    gl::VertexArray::bufferBindingPoint_t*  vertexBuffers = nullptr;
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

void gl::VertexArray::BindeVertexBuffer(const bufferBindingPoint_t in_bufferBinding, const GLuint in_bindingindex )
{
    GLuint bufferCount = in_bindingindex + 1;

    // realloc buffers to fit 
    if ( m_vertexArray->numVertexBuffers < bufferCount )
    {
        if ( m_vertexArray->vertexBuffers == nullptr )
            m_vertexArray->vertexBuffers = static_cast<bufferBindingPoint_t*>( std::malloc( sizeof( bufferBindingPoint_t ) * bufferCount ) );
        else
            m_vertexArray->vertexBuffers = static_cast<bufferBindingPoint_t*>( std::realloc( m_vertexArray->vertexBuffers, sizeof( bufferBindingPoint_t ) * bufferCount ) );
        m_vertexArray->numVertexBuffers = bufferCount; 
    }

#if !defined( NDEBUG ) // we don't check on releases 
    if ( glIsBuffer( in_bufferBinding.buffer ) != GL_TRUE )
    {
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 77, k_INVALID_VERTEX_BUFFER_MSG );
        return;
    }
#endif
    // bind buffer at designed position
    glVertexArrayVertexBuffer( m_vertexArray->vertexArray, in_bindingindex, in_bufferBinding.buffer, in_bufferBinding.offset, in_bufferBinding.stride );
    // store buffer binding configuration 
    m_vertexArray->vertexBuffers[in_bindingindex] = in_bufferBinding;   
}

void gl::VertexArray::BindeVertexBuffers( const bufferBindingPoint_t* in_bindings, const GLuint in_first, const GLsizei in_count )
{
    // TODO:  
    GLuint      buffers[16]{}; 
    GLintptr    offsets[16]{}; 
    GLsizei     strides[16]{};    

    GLuint bufferCount = in_first + in_count; //
    
    // realloc buffers to fit 
    if ( m_vertexArray->numVertexBuffers < bufferCount )
    {
        if ( m_vertexArray->vertexBuffers == nullptr )
            m_vertexArray->vertexBuffers = static_cast<bufferBindingPoint_t*>( std::malloc( sizeof( GLuint ) * bufferCount ) );
        else
            m_vertexArray->vertexBuffers = static_cast<bufferBindingPoint_t*>( std::realloc( m_vertexArray->vertexBuffers, sizeof( GLuint ) * bufferCount ) );
        m_vertexArray->numVertexBuffers = bufferCount; 
    }
    
    //store buffer binding, and check
    for ( GLsizei i = 0; i < in_count; i++)
    {
#if !defined( NDEBUG ) // we don't check on releases 
        if ( glIsBuffer( in_bindings[i].buffer ) != GL_TRUE )
        {
            glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 77, k_INVALID_VERTEX_BUFFER_MSG );
            return;
        }
#endif
        // store buffer info
        buffers[i] = in_bindings[i].buffer;
        offsets[i] = in_bindings[i].offset;
        strides[i] = in_bindings[i].stride;
    }

    // bind buffers
    glVertexArrayVertexBuffers( m_vertexArray->vertexArray, in_first, in_count, buffers, offsets, strides );
    std::memcpy( &m_vertexArray->vertexBuffers[in_first], in_bindings, sizeof( bufferBindingPoint_t) * in_count ); 
}

GLuint gl::VertexArray::GetHandle(void) const
{
    return m_vertexArray->vertexArray;
}

gl::VertexArray::operator    GLuint( void ) const
{
    return m_vertexArray->vertexArray;
}
