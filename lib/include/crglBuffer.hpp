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
#ifndef __GL_BUFFER_HPP__
#define __GL_BUFFER_HPP__

namespace gl
{
    class Buffer
    {    
    public:
        Buffer( void );
        ~Buffer( void );

        void        Create( const GLuint in_target, const GLsizeiptr in_size, const void* in_data, const GLbitfield in_flags );
        void        Destroy( void );
        void        Upload( const void* data, const GLintptr offset, const GLsizeiptr size );
        void        Download( void* &data, const GLintptr offset, const GLsizeiptr size );
        void*       Map( const GLintptr in_offset, const GLsizeiptr in_length, const GLbitfield in_access );
        void        Unmap( void );
        void        Flush( const GLintptr in_offset, const GLsizeiptr in_length );
        GLuint      GetHandle( void ) const;
        operator    GLuint( void ) const;

    private:
        glCoreBuffer_t* m_bufferHandler;
    };
};

#endif //!__CRGL_BUFFER_HPP__