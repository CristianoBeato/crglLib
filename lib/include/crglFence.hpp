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
#ifndef __CRGL_FENCE_HPP__
#define __CRGL_FENCE_HPP__

namespace gl
{
    class Fence
    {   
    public:
        Fence( void );
        ~Fence( void );

        void    Init( const GLenum in_condition, const GLbitfield in_flags );
        void    Release( void );
        bool    IsSync( void ) const;        
        GLenum  ClientWait( const GLbitfield in_flags, const GLuint64 in_timeout ) const;
        void    Wait( const GLbitfield in_flags, const GLuint64 in_timeout ) const;
        void    Getiv( const GLenum pname, const GLsizei count, GLsizei *length, GLint *values ) const;

    private:
        GLsync  m_sync;
    };
};

#endif //__CRGL_FENCE_HPP__