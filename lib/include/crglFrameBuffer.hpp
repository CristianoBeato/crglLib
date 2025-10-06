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
#ifndef __CRGL_FRAMEBUFFER_HPP__
#define __CRGL_FRAMEBUFFER_HPP__

namespace gl
{
    class RenderBuffer
    {
    public:
        RenderBuffer( void );
        ~RenderBuffer( void );
        bool        Create( const GLuint in_width, const GLuint in_height, const GLuint in_samples, const GLenum in_format );
        void        Destroy( void );
        GLuint      GetHandle( void ) const;
        operator    GLuint( void ) const;

    private:
        glCoreRenderbuffer_t*   m_renderBufferHandle;
    };

    class FrameBuffer
    {
    public:
        typedef struct attachament_t
        {
            GLenum target;  // attachament target
            GLenum attachament;
            GLuint handle;
        } attachament_t;

        typedef struct rect_t
        {
            GLint X0; 
            GLint Y0; 
            GLint X1; 
            GLint Y1;
        } rect_t;
        
        FrameBuffer( void );
        ~FrameBuffer( void );
        bool    Create( void );
        void    Destroy( void );
        bool    Attach( const attachament_t* in_attachaments, const GLuint in_base, const GLuint in_count );
        void    Blit( const GLuint in_dstFrameBuffer, const rect_t in_srcRec, const rect_t in_dstRect, GLbitfield mask, GLenum filter ) const;
        GLuint  Handler( void ) const;
        operator GLuint( void ) const;

    private:
        glCoreFramebuffer_t* m_frameBufferHandle;
    };
};
#endif //__CRGL_FRAMEBUFFER_HPP__