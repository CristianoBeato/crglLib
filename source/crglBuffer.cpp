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
#include "crglBuffer.hpp"
#include "crglShaders.hpp"

typedef struct glCoreBuffer_t 
{
    GLenum  target = 0;
    GLuint  buffer = 0;
} glCoreBuffer_t;

gl::Buffer::Buffer( void ) : m_bufferHandler( nullptr )
{
}

gl::Buffer::~Buffer( void )
{
    Destroy();

    if ( m_bufferHandler != nullptr )
    {
        delete m_bufferHandler;
        m_bufferHandler = nullptr;
    }
}

void gl::Buffer::Create( const GLuint in_target, const GLsizeiptr in_size, const void* in_data, const GLbitfield in_flags )
{
    // clear old buffer remain 
    Destroy(); 

    //
    m_bufferHandler = new glCoreBuffer_t();
    m_bufferHandler->target = in_target;

    // create the buffer object
    glCreateBuffers( 1, &m_bufferHandler->buffer );
    glNamedBufferStorage( m_bufferHandler->buffer, in_size, in_data, in_flags );
}

void gl::Buffer::Destroy( void )
{
    if( m_bufferHandler == nullptr )
        return;

    if( m_bufferHandler->buffer != 0 )
    {
        glDeleteBuffers( 1, &m_bufferHandler->buffer );
        m_bufferHandler->buffer = 0;
    }

    delete m_bufferHandler;
    m_bufferHandler = nullptr;
}

void gl::Buffer::Upload(const void *in_data, const GLintptr in_offset, const GLsizeiptr in_size)
{
    if ( m_bufferHandler == nullptr )
        throw std::runtime_error( "invalid handle!" );

    glNamedBufferSubData( m_bufferHandler->buffer, in_offset, in_size, in_data );
}

void gl::Buffer::Download( void* &in_data, const GLintptr in_offset, const GLsizeiptr in_size )
{
    if ( m_bufferHandler == nullptr )
        throw std::runtime_error( "invalid handle!" );
    glGetNamedBufferSubData( m_bufferHandler->buffer, in_offset, in_size, in_data );
}

void* gl::Buffer::Map( const GLintptr in_offset, const GLsizeiptr in_length, const GLbitfield in_access )
{
    if ( m_bufferHandler == nullptr )
        throw std::runtime_error( "invalid handle!" );

    return glMapNamedBufferRange( m_bufferHandler->buffer, in_offset, in_length, in_access );
}

void gl::Buffer::Unmap( void )
{
    if ( m_bufferHandler == nullptr )
        throw std::runtime_error( "invalid handle!" );
    
    glUnmapNamedBuffer( m_bufferHandler->buffer );
}

void gl::Buffer::Flush( const GLintptr in_offset, const GLsizeiptr in_length )
{
    if ( m_bufferHandler == nullptr )
        throw std::runtime_error( "invalid handle!" );

    glFlushMappedNamedBufferRange( m_bufferHandler->buffer, in_offset, in_length );
}

GLuint gl::Buffer::GetHandle(void) const
{
    return m_bufferHandler->buffer;
}

gl::Buffer::operator GLuint( void ) const
{
    return m_bufferHandler->buffer;
}
