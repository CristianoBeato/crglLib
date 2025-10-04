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
#ifndef __CRGL_IMAGE_HPP__
#define __CRGL_IMAGE_HPP__

namespace gl
{
    class Image
    {
    public:
        Image( void );
        ~Image( void );

        bool    Create(
                const GLenum in_target, 
                const GLenum in_internalformat, 
                const GLsizei in_levels,
                const GLsizei in_layers, 
                const GLsizei in_width, 
                const GLsizei in_height, 
                const GLsizei in_depth );
        void    Destroy( void );
        void    SubImage();
        void    GetSubImage();

    private:
        glCoreImage_t*  m_image;
    };
};
#endif //!__CRGL_IMAGE_HPP__