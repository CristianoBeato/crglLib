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

#ifndef __CRGL_SAMPLER_HPP__
#define __CRGL_SAMPLER_HPP__

namespace gl
{
    class Sampler
    {
    public:
        Sampler( void );
        ~Sampler( void );
    
        void        Create( void );
        void        Destroy( void );
        void        Parameteri( const GLenum in_pName, const GLint in_param ) const;
        void        Parameterf( const GLenum in_pName, const GLfloat in_param ) const;
        void        Parameteriv( const GLenum in_pName, const GLint *in_param ) const;
        void        Parameterfv( const GLenum in_pName, const GLfloat *in_param ) const;
        void        ParameterIiv( const GLenum in_pName, const GLint *in_param ) const;
        void        ParameterIuiv( const GLenum in_pName, const GLuint *in_param ) const;
        void        GetParameteriv( const GLenum in_pName, GLint *in_param ) const;
        void        GetParameterfv( const GLenum in_pName, GLfloat *in_param ) const;
        void        GetParameterIiv( const GLenum in_pName, GLint *in_param ) const;
        void        GetParameterIuiv( const GLenum in_pName, GLuint *in_param ) const;

        GLuint Handler( void ) const { return m_sampler; }
        operator GLuint( void ) const { return m_sampler; }

    private:
        GLuint  m_sampler;
    };    
};

#endif //!__CRGL_SAMPLER_HPP__