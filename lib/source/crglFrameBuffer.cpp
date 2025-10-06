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
#include "crglFrameBuffer.hpp"

typedef struct  glCoreRenderbuffer_t
{
    GLenum format = GL_NONE;
    GLuint samples = 0;
    GLuint renderBuffer = 0;
} glCoreRenderbuffer_t;

typedef struct glCoreFramebuffer_t
{
    GLuint frameBuffer = 0;
} glCoreFramebuffer_t;

gl::RenderBuffer::RenderBuffer( void ) : m_renderBufferHandle( nullptr )
{
}

gl::RenderBuffer::~RenderBuffer( void )
{
    Destroy();
}

bool gl::RenderBuffer::Create( const GLuint in_width, const GLuint in_height, const GLuint in_samples, const GLenum in_format )
{
    Destroy();

    m_renderBufferHandle = new glCoreRenderbuffer_t();
    
    // Create handle
    glCreateRenderbuffers( 1, &m_renderBufferHandle->renderBuffer );

    m_renderBufferHandle->format = in_format;
    m_renderBufferHandle->samples = in_samples;
    
    if ( m_renderBufferHandle->samples > 0 )
        glNamedRenderbufferStorageMultisample( m_renderBufferHandle->renderBuffer, in_samples, in_format, in_width, in_height );
    else
        glNamedRenderbufferStorage( m_renderBufferHandle->renderBuffer, in_format, in_width, in_height );   
}

void gl::RenderBuffer::Destroy( void )
{
    if ( m_renderBufferHandle != nullptr )
        return;

    if ( m_renderBufferHandle->renderBuffer != 0 )
    {
        glDeleteRenderbuffers( 1, &m_renderBufferHandle->renderBuffer );
        m_renderBufferHandle->renderBuffer = 0;
    }

    delete m_renderBufferHandle;
    m_renderBufferHandle = nullptr;
}

GLuint gl::RenderBuffer::GetHandle( void ) const
{
    return m_renderBufferHandle != nullptr ? m_renderBufferHandle->renderBuffer : 0;
}

gl::RenderBuffer::operator GLuint( void ) const
{
    return m_renderBufferHandle != nullptr ? m_renderBufferHandle->renderBuffer : 0;
}

gl::FrameBuffer::FrameBuffer( void ) : m_frameBufferHandle( nullptr )
{
}

gl::FrameBuffer::~FrameBuffer( void )
{
    Destroy();
}

bool gl::FrameBuffer::Create( void )
{
    Destroy();

    // just create the handle
    m_frameBufferHandle = static_cast<glCoreFramebuffer_t*>( std::malloc( sizeof( glCoreFramebuffer_t ) ) );
    glCreateFramebuffers( 1, &m_frameBufferHandle->frameBuffer );

    return true;
}

void gl::FrameBuffer::Destroy( void )
{
    if ( m_frameBufferHandle == nullptr )
        return;    

    if ( m_frameBufferHandle->frameBuffer != 0 )
    {
        glDeleteFramebuffers( 1, &m_frameBufferHandle->frameBuffer );
        m_frameBufferHandle->frameBuffer = 0;
    }

    std::free( m_frameBufferHandle );
    m_frameBufferHandle = nullptr;
}

bool gl::FrameBuffer::Attach(const attachament_t *in_attachaments, const GLuint in_base, const GLuint in_count)
{
    for ( GLuint i = 0; i < in_count; i++)
    {
        auto attch = in_attachaments[i];
        
        switch (attch.target)
        {
        case GL_RENDERBUFFER:
        {
            glNamedFramebufferRenderbuffer( m_frameBufferHandle->frameBuffer, attch.attachament, GL_RENDERBUFFER, attch.handle );
        } break;
        case GL_TEXTURE_1D:
        case GL_TEXTURE_2D:
        {
            glNamedFramebufferTexture( m_frameBufferHandle->frameBuffer, attch.attachament, attch.handle, 0 );
        } break;
        case GL_TEXTURE_CUBE_MAP:
        case GL_TEXTURE_CUBE_MAP_ARRAY:
        case GL_TEXTURE_1D_ARRAY:
        case GL_TEXTURE_2D_ARRAY:
        {
            glNamedFramebufferTextureLayer( m_frameBufferHandle->frameBuffer, attch.attachament, attch.handle, 0, i + in_base );
        } break;
                
        default:
            break;
        }
    }

    if( glCheckNamedFramebufferStatus( m_frameBufferHandle->frameBuffer, GL_FRAMEBUFFER ) != GL_FRAMEBUFFER_COMPLETE )
        return false;

    return glIsFramebuffer( m_frameBufferHandle->frameBuffer ) == GL_TRUE;
}

void gl::FrameBuffer::Blit( const GLuint in_dstFrameBuffer, const rect_t in_srcRec, const rect_t in_dstRect, const GLbitfield in_mask, const GLenum in_filter ) const
{
    if ( m_frameBufferHandle == nullptr )
    {
        // append error
        return;
    }

    glBlitNamedFramebuffer( 
            m_frameBufferHandle->frameBuffer, 
            in_dstFrameBuffer, 
            in_srcRec.X0, in_srcRec.Y0, in_srcRec.X1, in_srcRec.Y1,
            in_dstRect.X0, in_dstRect.Y0, in_dstRect.X1, in_dstRect.Y1, 
            in_mask, in_filter );  
}


GLuint gl::FrameBuffer::Handler(void) const
{
    return m_frameBufferHandle->frameBuffer;
}

gl::FrameBuffer::operator GLuint(void) const
{
    return m_frameBufferHandle->frameBuffer;
}
