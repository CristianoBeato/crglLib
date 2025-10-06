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
#include "crglSampler.hpp"

gl::Sampler::Sampler( void ) : m_sampler( 0 )
{
}
    
gl::Sampler::~Sampler( void )
{
    Destroy();
}

void gl::Sampler::Create(void)
{
    if ( m_sampler != 0 )
        Destroy();

    glCreateSamplers( 1, &m_sampler );
}

void gl::Sampler::Destroy(void)
{
    if ( m_sampler != 0 )
    {
        glDeleteSamplers( 1, &m_sampler );
        m_sampler = 0;
    }    
}

void gl::Sampler::Parameteri( const GLenum in_pName, const GLint in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameteri( m_sampler, in_pName, in_param );
}

void gl::Sampler::Parameterf( const GLenum in_pName, const GLfloat in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameterf( m_sampler, in_pName, in_param );
}

void gl::Sampler::Parameteriv( const GLenum in_pName, const GLint *in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameteriv( m_sampler, in_pName, in_param );
}

void gl::Sampler::Parameterfv( const GLenum in_pName, const GLfloat *in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameterfv( m_sampler, in_pName, in_param );
}

void gl::Sampler::ParameterIiv( const GLenum in_pName, const GLint *in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameterIiv( m_sampler, in_pName, in_param );
}

void gl::Sampler::ParameterIuiv( const GLenum in_pName, const GLuint *in_param ) const
{
    if( m_sampler == 0 )
        return;

    glSamplerParameterIuiv( m_sampler, in_pName, in_param );
}

void gl::Sampler::GetParameteriv( const GLenum in_pName, GLint *in_param ) const
{
    if( m_sampler == 0 )
        return;

    glGetSamplerParameteriv( m_sampler, in_pName, in_param );
}

void gl::Sampler::GetParameterfv( const GLenum in_pName, GLfloat *in_param ) const
{
    if( m_sampler == 0 )
        return;
    
    glGetSamplerParameterfv( m_sampler, in_pName, in_param );
}

void gl::Sampler::GetParameterIiv(const GLenum in_pName, GLint *in_param) const
{
    if( m_sampler == 0 )
        return;

    glGetSamplerParameterIiv( m_sampler, in_pName, in_param );
}

void gl::Sampler::GetParameterIuiv(const GLenum in_pName, GLuint *in_param) const
{
    if( m_sampler == 0 )
        return;

    glGetSamplerParameterIuiv( m_sampler, in_pName, in_param );
}
