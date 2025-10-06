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
#include "crglFence.hpp"


gl::Fence::Fence( void )
{
}

gl::Fence::~Fence( void )
{
}

void gl::Fence::Init( const GLenum in_condition, const GLbitfield in_flags )
{
    m_sync = glFenceSync( in_condition, in_flags );
}

void gl::Fence::Release(void)
{
    if ( IsSync() )
    {
        glDeleteSync( m_sync );
        m_sync = nullptr;
    }
}

bool gl::Fence::IsSync(void) const
{
    return glIsSync( m_sync ) == GL_TRUE;
}

GLenum gl::Fence::ClientWait( const GLbitfield in_flags, const GLuint64 in_timeout ) const
{
    return glClientWaitSync( m_sync, in_flags, in_timeout );
}

void gl::Fence::Wait( const GLbitfield in_flags, const GLuint64 in_timeout ) const
{
    glWaitSync( m_sync, in_flags, in_timeout );
}

void gl::Fence::Getiv( const GLenum in_pname, const GLsizei in_count, GLsizei *in_length, GLint *in_values ) const
{
    glGetSynciv( m_sync, in_pname, in_count, in_length, in_values );
}
