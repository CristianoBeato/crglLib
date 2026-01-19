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
#include "crglTexture.hpp"

static const char k_INVALID_CREATE_TEXTURE_TARGET_MSG[43] = { "gl::Texture::Create invalid texture target" };
static const char k_INVALID_SUBIMAGE_TEXTURE_TARGET_MSG[46] = { "gl::Texture::SubImage invalid texture target " };

typedef struct glCoreTexture_t
{
    GLenum                  target = gl::texture::TEXTURE_1D;
    gl::Format              format = 0;
    GLuint                  image = 0;
} glCoreTexture_t;

gl::Texture::Texture( void ) : m_image( nullptr )
{
}

gl::Texture::~Texture( void )
{
    Destroy();
}

bool gl::Texture::Create( const createInfo_t* in_createInfo )
{
    GLenum  format = GL_NONE;
    GLsizei levels = 0;
    GLsizei layers = 0;
    GLsizei samples = 1;
    GLsizei width = 0;
    GLsizei height = 0;
    GLsizei depth = 0;

    /// invalid creation info passed
    if ( !in_createInfo )
    {
        // TODO: apend error:
        return false;
    }
    
    Destroy();

    m_image = new glCoreTexture_t();
    
    /// set image target and format
    m_image->target = in_createInfo->target;
    m_image->format = in_createInfo->format;

    ///
    format  = in_createInfo->format.internalFormat;
    levels  = in_createInfo->levels;
    layers  = in_createInfo->layers;
    samples = in_createInfo->samples;
    width   = in_createInfo->dimensions.width;
    height  = in_createInfo->dimensions.height;
    depth   = in_createInfo->dimensions.depth;

    /// create texture handler 
    glCreateTextures( m_image->target, 1, &m_image->image );
    if ( m_image->image == 0 )
        return false;

    // allocate the texture memory
    switch ( m_image->target )
    {
    case texture::TEXTURE_1D:
        glTextureStorage1D( m_image->image, levels, format, width );
        break;
    case texture::TEXTURE_1D_ARRAY:
        glTextureStorage2D( m_image->image, levels, format, width, layers );
        break;
    case texture::TEXTURE_2D:
    case texture::TEXTURE_RECTANGLE:
        glTextureStorage2D( m_image->image, levels, format, width, height );
        break;
    case texture::TEXTURE_3D:
        glTextureStorage3D( m_image->image, levels, format, width, height, depth );
        break;
    case texture::TEXTURE_2D_ARRAY:
        glTextureStorage3D( m_image->image, levels, format, width, height, layers );
        break;
    case texture::TEXTURE_CUBE_MAP:
        glTextureStorage3D( m_image->image, levels, format, width, height, 6 );
        break;
    case texture::TEXTURE_CUBE_MAP_ARRAY:
        glTextureStorage3D( m_image->image, levels, format, width, width, layers * 6 );
        break;
    case texture::TEXTURE_2D_MULTISAMPLE:
        glTextureStorage2DMultisample( m_image->image, samples, format, width, height, in_createInfo->fixedsamplelocations );
        break;
    case texture::TEXTURE_2D_MULTISAMPLE_ARRAY:
        glTextureStorage3DMultisample( m_image->image, samples, format, width, height, depth, in_createInfo->fixedsamplelocations );
        break;
    default:
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 41, k_INVALID_CREATE_TEXTURE_TARGET_MSG );
        return false;
    }

    return m_image->image != 0 && glIsTexture( m_image->image ) == GL_TRUE;
}

void gl::Texture::Destroy( void )
{
    if ( m_image == nullptr )
        return;
    
    if ( m_image->image == 0 )
    {
        glDeleteTextures( 1, &m_image->image );
        m_image->image = 0;
    }

    delete m_image;
    m_image = nullptr;
}

void gl::Texture::SubImage( const subImage_t *in_subimage, const void* in_pixels ) const
{
    GLint   level = 0;
    GLsizei layer = 0;
    GLsizei xoffset = 0;
    GLsizei yoffset = 0;
    GLsizei zoffset = 0;
    GLsizei width = 0;
    GLsizei height = 0;
    GLsizei depth = 0;
    GLenum  format = GL_NONE;
    GLenum  type = GL_NONE;

    if( !m_image || m_image->image == 0 )
    {   
        // TODO: report a error 
        return;
    }

    level = in_subimage->level;
    xoffset = in_subimage->offsets.xoffset;
    yoffset = in_subimage->offsets.yoffset;
    zoffset = in_subimage->offsets.zoffset;
    width = in_subimage->dimension.width;
    height = in_subimage->dimension.height;
    depth = in_subimage->dimension.depth;
    format = m_image->format.format;
    type = m_image->format.DataType();

    switch ( m_image->target )
    {
    case texture::TEXTURE_1D:
        glTextureSubImage1D( m_image->image, level, xoffset, width, format, type, in_pixels );
        break;

    case texture::TEXTURE_1D_ARRAY:
        glTextureSubImage2D( m_image->image, level, xoffset, layer, width, 1,  format, type, in_pixels );
        break;

    case texture::TEXTURE_2D:
    case texture::TEXTURE_RECTANGLE:
        glTextureSubImage2D( m_image->image, level, xoffset, yoffset, width, height, format, type, in_pixels );
        break;        

    case texture::TEXTURE_2D_ARRAY:
        glTextureSubImage3D( m_image->image, level, xoffset, yoffset, layer, width, height, 1, format, type, in_pixels );
        break;        

    case texture::TEXTURE_3D:
        glTextureSubImage3D( m_image->image, level, xoffset, yoffset, zoffset, width, height, depth, format, type, in_pixels );
        break;        
        
    case texture::TEXTURE_CUBE_MAP:
    case texture::TEXTURE_CUBE_MAP_ARRAY:
        glTextureSubImage3D( m_image->image, level, xoffset, yoffset, layer, width, width, 1, format, type, in_pixels );
        break;
    
    default:
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 44, k_INVALID_SUBIMAGE_TEXTURE_TARGET_MSG );
        break;
    }
}

void gl::Texture::CompressedSubImage(const subImage_t *in_subimage, const void *in_pixels)
{
    GLint   level = 0;
    GLsizei layer = 0;
    GLsizei xoffset = 0;
    GLsizei yoffset = 0;
    GLsizei zoffset = 0;
    GLsizei width = 0;
    GLsizei height = 0;
    GLsizei depth = 0;
    GLsizei imageSize = 0;
    GLenum  format = GL_NONE;
    
    if( !m_image || m_image->image == 0 )
    {   
        // TODO: report a error 
        return;
    }

    level = in_subimage->level;
    layer = in_subimage->layer;
    xoffset = in_subimage->offsets.xoffset;
    yoffset = in_subimage->offsets.yoffset;
    zoffset = in_subimage->offsets.zoffset;
    width = in_subimage->dimension.width;
    height = in_subimage->dimension.height;
    depth = in_subimage->dimension.depth;
    imageSize = in_subimage->imageSize;
    format = m_image->format.format;
    
    switch ( m_image->target )
    {
        case texture::TEXTURE_1D:
            glCompressedTextureSubImage1D( m_image->image, level, xoffset, width, format, imageSize, in_pixels );
            break;

        case texture::TEXTURE_2D:
        case texture::TEXTURE_RECTANGLE:
            glCompressedTextureSubImage2D( m_image->image, level, xoffset, yoffset, width, height, format, imageSize, in_pixels );
            break;

        case texture::TEXTURE_3D:
            glCompressedTextureSubImage3D( m_image->image, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, in_pixels );
            break;

        case texture::TEXTURE_1D_ARRAY:
            glCompressedTextureSubImage2D( m_image->image, level, xoffset, layer, width, 1, format, imageSize, in_pixels );
            break;
            
        case texture::TEXTURE_2D_ARRAY:
            glCompressedTextureSubImage3D( m_image->format, level, xoffset, yoffset, layer, width, height, 1, format, imageSize, in_pixels );
            break;
        case texture::TEXTURE_CUBE_MAP:
        case texture::TEXTURE_CUBE_MAP_ARRAY:
            glCompressedTextureSubImage3D( m_image->format, level, xoffset, yoffset, layer, width, width, 1, format, imageSize, in_pixels );
            break;
        default:
        break;
    }

}

void gl::Texture::GetImage(const GLint in_level, const GLsizei in_bufSize, void *in_pixels) const
{
    GLenum format = GL_NONE;
    GLenum type = GL_NONE;
    if( !m_image || m_image->image )
    {   
        // TODO: report a error 
        return;
    }

    format = m_image->format.ColorChanels( false ); // todo invert color
    type = m_image->format.DataType();
    glGetTextureImage( m_image->image, in_level, format, type, in_bufSize, in_pixels );
}

void gl::Texture::GetCompressedImage( const GLint in_level, const GLsizei in_bufSize, void * in_pixels ) const
{
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    glGetCompressedTextureImage( m_image->image, in_level, in_bufSize, in_pixels );
}

void gl::Texture::CopySubImage( const subImage_t *in_subimage, const GLint in_x, const GLint in_y ) const
{
    GLsizei level = 0; 
    GLsizei layer = 0;
    GLsizei xoffset = 0; 
    GLsizei yoffset = 0;
    GLsizei zoffset = 0;
    GLsizei width = 0;
    GLsizei height = 0;
    //GLsizei depth = 0;

    if( !m_image || m_image->image )
    {   
        // TODO: report a error 
        return;
    }

    level = in_subimage->level;
    layer = in_subimage->layer;
    xoffset = in_subimage->offsets.xoffset;
    yoffset = in_subimage->offsets.yoffset;
    zoffset = in_subimage->offsets.zoffset;
    width = in_subimage->dimension.width;
    height = in_subimage->dimension.height;
    //depth = in_subimage->dimension.depth;

    switch ( m_image->target )
    {
    case texture::TEXTURE_1D:
        glCopyTextureSubImage1D( m_image->image, level, xoffset, in_x, in_y, width );
        break;

    case texture::TEXTURE_1D_ARRAY:
        glCopyTextureSubImage2D( m_image->image, level, xoffset, layer, in_x, in_y, width, 1 );
        break;

    case texture::TEXTURE_2D:
    case texture::TEXTURE_RECTANGLE:
        glCopyTextureSubImage2D( m_image->image, level, xoffset, yoffset, in_x, in_y, width, height );
        break;

    case texture::TEXTURE_2D_ARRAY:
        glCopyTextureSubImage3D( m_image->image, level, xoffset, layer, in_x, in_y, width, height, 1 );
        break;
    
    case texture::TEXTURE_3D:
        glCopyTextureSubImage3D( m_image->image, level, xoffset, yoffset, zoffset, in_x, in_y, width, height );
        break;

    case texture::TEXTURE_CUBE_MAP:
    case texture::TEXTURE_CUBE_MAP_ARRAY:
        glCopyTextureSubImage3D( m_image->image, level, xoffset, yoffset, layer, in_x, in_y, width, height );
        break;

    default:
        // TODO: error call
        break;
    }
}

void gl::Texture::GetSubImage(    const GLint in_level,
                                const offsets_t in_offsets,
                                const dimensions_t in_dimensions,
                                const GLenum in_type,
                                const GLsizei in_bufSize,
                                void *in_pixels ) const
{
    GLenum format = 0;
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }
    
    // todo: color inversion
    format = m_image->format.ColorChanels( false );

    glGetTextureSubImage(   m_image->image, 
                            in_level, 
                            in_offsets.xoffset,
                            in_offsets.yoffset,
                            in_offsets.zoffset,
                            in_dimensions.width, 
                            in_dimensions.height, 
                            in_dimensions.depth, 
                            format, 
                            in_type, 
                            in_bufSize, 
                            in_pixels );
    
}

void gl::Texture::GetCompressedSubImage(  const GLint in_level,
                                        const offsets_t in_offsets,
                                        const dimensions_t in_dimensions,
                                        const GLsizei in_bufSize,
                                        void *in_pixels ) const
{
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }
    
    glGetCompressedTextureSubImage( m_image->image, 
                                    in_level,
                                    in_offsets.xoffset, 
                                    in_offsets.yoffset, 
                                    in_offsets.zoffset, 
                                    in_dimensions.width, 
                                    in_dimensions.height, 
                                    in_dimensions.depth, 
                                    in_bufSize, 
                                    in_pixels );
}


void gl::Texture::CopyImage(  const GLenum in_srcTarget,
                            const GLuint in_source, 
                            const GLint in_srcLevel,
                            const GLint in_dstLevel,
                            const offsets_t in_srcOffsets,
                            const offsets_t in_dstOffsets,
                            const dimensions_t in_dimensions ) const
{
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    glCopyImageSubData( in_source,
                        in_srcTarget,
                        in_srcLevel, 
                        in_srcOffsets.xoffset, 
                        in_srcOffsets.yoffset, 
                        in_srcOffsets.zoffset,
                        m_image->image,
                        m_image->target, 
                        in_dstLevel,
                        in_dstOffsets.xoffset,
                        in_dstOffsets.yoffset,
                        in_dstOffsets.zoffset,
                        in_dimensions.width,
                        in_dimensions.height,
                        in_dimensions.depth );
}

void gl::Texture::Invalidate( const GLint in_level, const offsets_t in_offsets, const dimensions_t in_dimensions ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }

    // if the dimension is not set, invalidade whole image
    if ( ( in_dimensions.width == 0 ) && ( in_dimensions.height == 0 ) && ( in_dimensions.depth == 0 ) )
        glInvalidateTexImage( m_image->image, in_level );
    else // invalidate the given region
        glInvalidateTexSubImage( m_image->image, in_level, in_offsets.xoffset, in_offsets.yoffset, in_offsets.zoffset, in_dimensions.width, in_dimensions.height, in_dimensions.depth );
}

void gl::Texture::Clear( const void* in_data, const GLint in_level, const offsets_t in_offsets, const dimensions_t in_dimensions ) const
{
    GLenum format = GL_NONE;
    GLenum type = GL_NONE;
    if ( !m_image )
    {
        // report a error
        return;
    }

    format = m_image->format.ColorChanels( false );
    type = m_image->format.DataType();

    if ( ( in_dimensions.width == 0 ) && ( in_dimensions.height == 0 ) && ( in_dimensions.depth == 0 ) )
        glClearTexImage( m_image->image, in_level, format, type, in_data );
    else
        glClearTexSubImage( m_image->image, in_level, 
            in_offsets.xoffset, in_offsets.yoffset, in_offsets.zoffset, 
            in_dimensions.width, in_dimensions.height, in_dimensions.depth,
            format,
            type, 
            in_data );    
}

void gl::Texture::Parameterfv(const GLenum in_pName, const GLfloat *m_params ) const
{
    if ( !m_image || m_image->image == 0 )
    {
        // report a error
        return;
    }
 
    glTextureParameterfv( m_image->image, in_pName, m_params );   
}

void gl::Texture::GetParameteriv(const GLenum in_pName, GLint *m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }

    glGetTextureParameteriv( m_image->image, in_pName, m_params );
}

void gl::Texture::GetParameterfv(const GLenum in_pName, GLfloat *m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }

    glGetTextureParameterfv( m_image->image, in_pName, m_params );
}

void gl::Texture::Parameteriv( const GLenum in_pName, const GLint* m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }
 
    glTextureParameteriv( m_image->image, in_pName, m_params );
}

GLuint gl::Texture::Handle(void) const
{
    if ( !m_image )
    {
        // report a error
        return 0;
    }
    
    return m_image->image;
}

GLenum gl::Texture::Target(void) const
{
    return m_image->target;
}

gl::Texture::operator GLuint(void) const
{
    if ( !m_image )
    {
        return 0;
    }
    
    return m_image->image;
}
