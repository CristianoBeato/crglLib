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

#ifndef __CRGL_IMAGE_HANDLER_HPP__
#define __CRGL_IMAGE_HANDLER_HPP__

namespace gl
{
    class ImageHandler
    {
    public:
        ImageHandler( void );
        ~ImageHandler( void );

        void    Create( const GLuint in_texture, const GLuint in_sample = 0 );
        void    Destroy( void );

        void    MakeTextureResident( void );
        void    MakeTextureNonResident( void );
        void    MakeImageResident( const GLenum in_acess );
        void    MakeImageNonResident( void );
        bool    IsTextureResident( void ) const;
        bool    IsImageResident( void ) const;

        const GLuint64 GetHandler( void ) const;
        operator GLuint64( void ) const;

    private:
        glCoreImageHandler_t*   m_handler;
    };
};

#endif //__CRGL_IMAGE_HANDLER_HPP__