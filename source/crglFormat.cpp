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
#include "crglFormat.hpp"


GLuint gl::Format::BytesPerPixel(void) const
{
    

    return 0;
}

GLenum gl::Format::ColorChanels( const bool in_inverse ) const
{
    GLenum format = GL_NONE;
    switch ( internalFormat )
    {
    // 1 color component only 
    case GL_R8:
    case GL_R8I:
    case GL_R8UI:
    case GL_R16:
    case GL_R16I:
    case GL_R16UI:
    case GL_R16_SNORM:
    case GL_R16F:
    case GL_R32F:
    case GL_R32I:
    case GL_R32UI:    
        format = GL_RED;
        break;
    
    // two color components 
    case GL_RG8:
    case GL_RG8I:
    case GL_RG8UI:
    case GL_RG8_SNORM:
    case GL_RG16:
    case GL_RG16I:
    case GL_RG16UI:
    case GL_RG16_SNORM:
    case GL_RG16F:
    case GL_RG32F:
    case GL_RG32I:
    case GL_RG32UI:
        format = GL_RG;
        break;
    
    // 3 color components
    case GL_RGB8:
    case GL_RGB8I:
    case GL_RGB8UI:
    case GL_RGB8_SNORM:
    case GL_SRGB8:
    case GL_RGB16:
    case GL_RGB16I:
    case GL_RGB16UI:
    case GL_RGB16_SNORM:
    case GL_RGB16F:
    case GL_RGB32I:
    case GL_RGB32UI:
    case GL_RGB32F:
    case GL_R3_G3_B2:
    case GL_R11F_G11F_B10F:
    case GL_RGB9_E5:
    case GL_RGB4:
    case GL_RGB5:
    case GL_RGB565:
    case GL_RGB10:
    case GL_RGB12:
        format = ( in_inverse ) ? GL_BGR : GL_RGB;
        break;

    case GL_RGBA8:
    case GL_RGBA8I:
    case GL_RGBA8UI:
    case GL_RGBA8_SNORM:
    case GL_SRGB8_ALPHA8:
    case GL_RGBA16:
    case GL_RGBA16I:
    case GL_RGBA16UI:
    case GL_RGBA16_SNORM:
    case GL_RGBA16F:
    case GL_RGBA32I:
    case GL_RGBA32UI:
    case GL_RGBA32F:
    case GL_RGBA2:
    case GL_RGBA4:
    case GL_RGB5_A1:
    case GL_RGB10_A2:
    case GL_RGB10_A2UI:
    case GL_RGBA12:
        format = ( in_inverse ) ? GL_BGRA : GL_RGBA;
        break;
        
    case GL_DEPTH_COMPONENT16:
    case GL_DEPTH_COMPONENT24:
    case GL_DEPTH_COMPONENT32:
    case GL_DEPTH_COMPONENT32F:
        format = GL_DEPTH_COMPONENT;
        break;

    case GL_DEPTH24_STENCIL8:
    case GL_DEPTH32F_STENCIL8:
        format = GL_DEPTH_STENCIL;
        break;
    
    case GL_STENCIL_INDEX1:
    case GL_STENCIL_INDEX4:
    case GL_STENCIL_INDEX8:
    case GL_STENCIL_INDEX16: 
        format = GL_STENCIL_INDEX;
        break;
    
    // compressed
    case GL_COMPRESSED_RED:
    case GL_COMPRESSED_RED_RGTC1:
    case GL_COMPRESSED_SIGNED_RED_RGTC1:
    case GL_COMPRESSED_R11_EAC:
    case GL_COMPRESSED_SIGNED_R11_EAC:
    case GL_COMPRESSED_RG11_EAC:
        format = GL_RED;
        break;

    case GL_COMPRESSED_RG:
    case GL_COMPRESSED_RG_RGTC2:
    case GL_COMPRESSED_SIGNED_RG_RGTC2:
    case GL_COMPRESSED_SIGNED_RG11_EAC:
        format = GL_RG;
        break;

    case GL_COMPRESSED_RGB:
    case GL_COMPRESSED_SRGB:
    case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:
    case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT:
    case GL_COMPRESSED_RGB8_ETC2:
    case GL_COMPRESSED_SRGB8_ETC2:
    case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
        format = GL_RGB;
        break;

    case GL_COMPRESSED_RGBA:
    case GL_COMPRESSED_SRGB_ALPHA:
    case GL_COMPRESSED_RGBA_BPTC_UNORM:
    case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:
    case GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2:
    case GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2:
    case GL_COMPRESSED_RGBA8_ETC2_EAC:
    case GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC:
    case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        format = GL_RGBA;
        break;

    default:
        // TODO: call a error here
        break;
    }

    return format;
}

GLenum gl::Format::DataType(void) const
{
    GLenum type = GL_NONE;

    switch ( internalFormat )
    {
    case GL_RG8I:
    case GL_RGB8I:
    case GL_RGBA8I:
    case GL_R8_SNORM:
    case GL_RG8_SNORM:
    case GL_RGB8_SNORM:
    case GL_RGBA8_SNORM:
    case GL_R3_G3_B2:
    type = GL_BYTE; 
    break;
    
    case GL_R8:
    case GL_RG8:
    case GL_RGB8:
    case GL_RGBA8:
    case GL_SRGB8:
    case GL_SRGB8_ALPHA8:
    case GL_R8UI:
    case GL_RG8UI:
    case GL_RGB8UI:
    case GL_RGBA8UI:
        type = GL_UNSIGNED_BYTE; 
        break;

    case GL_R16I:
    case GL_RG16I:
    case GL_RGB16I:
    case GL_RGBA16I:
    case GL_R16_SNORM:
    case GL_RG16_SNORM:
    case GL_RGB16_SNORM:
    case GL_RGBA16_SNORM:
        type = GL_SHORT; 
        break;
    
    case GL_R16:
    case GL_RG16:
    case GL_RGB16:
    case GL_RGBA16:
    case GL_R16UI:
    case GL_RG16UI:
    case GL_RGB16UI:
    case GL_RGBA16UI:   
        type = GL_UNSIGNED_SHORT; 
        break;
        
    case GL_R16F:
    case GL_RG16F:
    case GL_RGB16F:
    case GL_RGBA16F:
        type = GL_HALF_FLOAT; 
        break;
        
    case GL_R32I:
    case GL_RG32I:
    case GL_RGB32I:
    case GL_RGBA32I:
        type = GL_INT; 
        break;
    
    case GL_R32UI:    
    case GL_RG32UI:
    case GL_RGB32UI:
    case GL_RGBA32UI:
        type = GL_UNSIGNED_INT; 
        break;
    
    case GL_R32F:
    case GL_RG32F:
    case GL_RGB32F:
    case GL_RGBA32F:
        type = GL_FLOAT; 
        break;

    case GL_R11F_G11F_B10F:
        type = GL_UNSIGNED_INT_10F_11F_11F_REV;
        break;

    case GL_RGB9_E5:
        type = GL_UNSIGNED_INT_5_9_9_9_REV;
        break;

    case GL_RGB565:
        type = GL_UNSIGNED_SHORT_5_6_5;
        break;

    case GL_RGB4:
        type = GL_UNSIGNED_SHORT_4_4_4_4;
        break;

    case GL_RGB5:
        type = GL_UNSIGNED_SHORT_5_5_5_1;
        break;

    case GL_RGB5_A1:
        type = GL_UNSIGNED_SHORT_5_5_5_1;
        break;
    
    case GL_RGB10:
    case GL_RGB10_A2:
    case GL_RGB10_A2UI:
        type = GL_UNSIGNED_INT_10_10_10_2;
        break;

    case GL_RGB12:
    case GL_RGBA12:
        type = GL_UNSIGNED_SHORT;
        break;

    case GL_RGBA2:
    case GL_RGBA4:
        type = GL_BYTE;
        break;

    case GL_DEPTH_COMPONENT16:
        type = GL_HALF_FLOAT;
        break;

    case GL_DEPTH_COMPONENT24:
        type = GL_UNSIGNED_BYTE; 
        break;

    case GL_DEPTH_COMPONENT32:
        type = GL_UNSIGNED_INT;
        break;

    case GL_DEPTH_COMPONENT32F:
        type = GL_FLOAT;
        break;
    
    case GL_DEPTH24_STENCIL8:
    case GL_DEPTH32F_STENCIL8:    
        type= GL_UNSIGNED_INT_24_8;
        break;

    case GL_STENCIL_INDEX1:
    case GL_STENCIL_INDEX4:
    case GL_STENCIL_INDEX8:
        type = GL_UNSIGNED_BYTE;
        break;

    case GL_STENCIL_INDEX16: 
        type = GL_UNSIGNED_SHORT;
        break;
    
    // we not assume a specific type for compressed formats, only raw bytes
    case GL_COMPRESSED_RED:
    case GL_COMPRESSED_RED_RGTC1:
    case GL_COMPRESSED_SIGNED_RED_RGTC1:
    case GL_COMPRESSED_R11_EAC:
    case GL_COMPRESSED_SIGNED_R11_EAC:
    case GL_COMPRESSED_RG11_EAC:
    case GL_COMPRESSED_RG:
    case GL_COMPRESSED_RG_RGTC2:
    case GL_COMPRESSED_SIGNED_RG_RGTC2:
    case GL_COMPRESSED_SIGNED_RG11_EAC:
    case GL_COMPRESSED_RGB:
    case GL_COMPRESSED_SRGB:
    case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:
    case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT:
    case GL_COMPRESSED_RGB8_ETC2:
    case GL_COMPRESSED_SRGB8_ETC2:
    case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
    case GL_COMPRESSED_RGBA:
    case GL_COMPRESSED_SRGB_ALPHA:
    case GL_COMPRESSED_RGBA_BPTC_UNORM:
    case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:
    case GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2:
    case GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2:
    case GL_COMPRESSED_RGBA8_ETC2_EAC:
    case GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC:
    case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
    case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        return GL_UNSIGNED_BYTE;

    default:
        // TODO: call a error here
        break;
    }

    return type;
}
