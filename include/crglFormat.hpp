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

#ifndef __CRGL_FORMAT_HPP__
#define __CRGL_FORMAT_HPP__

// internal formats
// GL_R8
// GL_R16
// GL_R16I
// GL_R16UI
// GL_R16_SNORM
// GL_R16F
// GL_R32F
// GL_R32I
// GL_R32UI
// GL_RG8
// GL_RG8I
// GL_RG8UI
// GL_RG8_SNORM
// GL_RG16
// GL_RG16I
// GL_RG16UI
// GL_RG16_SNORM
// GL_RG16F
// GL_RG32F
// GL_RG32I
// GL_RG32UI
// GL_RGB8
// GL_RGB8I
// GL_RGB8UI
// GL_RGB8_SNORM
// GL_SRGB8
// GL_RGB16
// GL_RGB16I
// GL_RGB16UI
// GL_RGB16_SNORM
// GL_RGB16F
// GL_RGB32I
// GL_RGB32UI
// GL_RGB32F
// GL_R3_G3_B2
// GL_R11F_G11F_B10F
// GL_RGB9_E5
// GL_RGB4
// GL_RGB5
// GL_RGB565
// GL_RGB10
// GL_RGB12
// GL_RGBA8
// GL_RGBA8I
// GL_RGBA8UI
// GL_RGBA8_SNORM
// GL_SRGB8_ALPHA8
// GL_RGBA16
// GL_RGBA16I
// GL_RGBA16UI
// GL_RGBA16_SNORM
// GL_RGBA16F
// GL_RGBA32I
// GL_RGBA32UI
// GL_RGBA32F
// GL_RGBA2
// GL_RGBA4
// GL_RGB5_A1
// GL_RGB10_A2
// GL_RGB10_A2UI
// GL_RGBA12
// GL_DEPTH_COMPONENT16
// GL_DEPTH_COMPONENT24
// GL_DEPTH_COMPONENT32
// GL_DEPTH_COMPONENT32F
// GL_DEPTH24_STENCIL8
// GL_DEPTH32F_STENCIL8
// GL_STENCIL_INDEX1
// GL_STENCIL_INDEX4
// GL_STENCIL_INDEX8
// GL_STENCIL_INDEX16
// GL_COMPRESSED_RED
// GL_COMPRESSED_RED_RGTC1
// GL_COMPRESSED_SIGNED_RED_RGTC1
// GL_COMPRESSED_R11_EAC
// GL_COMPRESSED_SIGNED_R11_EAC
// GL_COMPRESSED_RG11_EAC
// GL_COMPRESSED_RG
// GL_COMPRESSED_RG_RGTC2
// GL_COMPRESSED_SIGNED_RG_RGTC2
// GL_COMPRESSED_SIGNED_RG11_EAC
// GL_COMPRESSED_RGB
// GL_COMPRESSED_SRGB
// GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
// GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
// GL_COMPRESSED_RGB8_ETC2
// GL_COMPRESSED_SRGB8_ETC2
// GL_COMPRESSED_RGB_S3TC_DXT1_EXT
// GL_COMPRESSED_RGBA
// GL_COMPRESSED_SRGB_ALPHA
// GL_COMPRESSED_RGBA_BPTC_UNORM
// GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
// GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
// GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
// GL_COMPRESSED_RGBA8_ETC2_EAC
// GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
// GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
// GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
// GL_COMPRESSED_RGBA_S3TC_DXT5_EXT

namespace gl
{
    struct Format
    {
        GLenum internalFormat;

        Format( void ) : internalFormat( GL_NONE )
        {
        }

        Format( const GLenum &in_format ) : internalFormat( in_format )
        {
        }

        GLuint  BytesPerPixel( void ) const;
        GLenum  ColorChanels( const bool in_inverse ) const;
        GLenum  DataType( void ) const;
        
        GLenum operator = ( const GLenum &in_format )
        {
            internalFormat = in_format;
            return internalFormat;
        }

        operator GLenum( void ) const { return internalFormat; }
    };
};

#endif //__CRGL_FORMAT_HPP__