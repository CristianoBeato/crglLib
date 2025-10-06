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
#include "crglImage.hpp"

static const char k_INVALID_CREATE_TEXTURE_TARGET_MSG[41] = { "gl::Image::Create invalid texture target" };
static const char k_INVALID_SUBIMAGE_TEXTURE_TARGET_MSG[44] = { "gl::Image::SubImage invalid texture target " };

typedef struct glCoreImage_t
{
    GLenum      target = 0;
    gl::Format  format = 0;
    GLuint      image = 0;
} glCoreImage_t;

gl::Image::Image( void ) : m_image( nullptr )
{
}

gl::Image::~Image( void )
{
    Destroy();
}

bool gl::Image::Create( 
    const GLenum in_target, 
    const GLenum in_internalformat, 
    const GLsizei in_levels,
    const GLsizei in_layers, 
    const dimensions_t in_dimensions )
{
    Destroy();

    m_image = new glCoreImage_t();
    m_image->target = in_target;
    m_image->format = in_internalformat;
    glCreateTextures( m_image->target, 1, &m_image->image );
    
    // allocate the texture memory
    switch ( m_image->target )
    {
    case GL_TEXTURE_1D:
        glTextureStorage1D( m_image->image, in_levels, m_image->format, in_dimensions.width );
        break;
    case GL_TEXTURE_1D_ARRAY:
        glTextureStorage2D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_layers );
        break;
    case GL_TEXTURE_2D:
    case GL_TEXTURE_RECTANGLE:
        glTextureStorage2D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_dimensions.height );
        break;
    case GL_TEXTURE_3D:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_dimensions.height, in_dimensions.depth );
        break;
    case GL_TEXTURE_2D_ARRAY:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_dimensions.height, in_dimensions.depth );
        break;
    case GL_TEXTURE_CUBE_MAP:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_dimensions.height, 6 );
        break;
    case GL_TEXTURE_CUBE_MAP_ARRAY:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_dimensions.width, in_dimensions.width, in_dimensions.depth );
        break;
        // TODO: multisample textures
        // GL_TEXTURE_2D_MULTISAMPLE
        // GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    default:
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 41, k_INVALID_CREATE_TEXTURE_TARGET_MSG );
        return false;
    }

    return false;
}

void gl::Image::Destroy( void )
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

void gl::Image::SubImage(   const GLint in_level,
                            const offsets_t in_offsets,
                            const dimensions_t in_dimensions,
                            const void* in_pixels, const bool in_invBGR ) const
{
    GLenum format = GL_NONE;
    GLenum type = GL_NONE;

    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    format = m_image->format.ColorChanels( in_invBGR );
    type = m_image->format.DataType();

    switch ( m_image->target )
    {
    case GL_TEXTURE_1D:
        glTextureSubImage1D( m_image->image, in_level, in_offsets.xoffset, in_dimensions.width, format, type, in_pixels );
        break;
    case GL_TEXTURE_1D_ARRAY:
    case GL_TEXTURE_2D:
    case GL_TEXTURE_RECTANGLE:
        glTextureSubImage2D( m_image->image, in_level, in_offsets.xoffset, in_offsets.yoffset, in_dimensions.width, in_dimensions.height, format, type, in_pixels );
        break;        
    case GL_TEXTURE_2D_ARRAY:
    case GL_TEXTURE_CUBE_MAP:
    case GL_TEXTURE_3D:
    case GL_TEXTURE_CUBE_MAP_ARRAY:
        glTextureSubImage3D( m_image->image, in_level, in_offsets.xoffset, in_offsets.yoffset, in_offsets.zoffset, in_dimensions.width, in_dimensions.height, in_dimensions.depth, format, type, in_pixels );
        break;        
    default:
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 44, k_INVALID_SUBIMAGE_TEXTURE_TARGET_MSG );
        break;
    }
}

void gl::Image::GetImage( const GLint in_level, const GLsizei in_bufSize, void *in_pixels ) const
{
    GLenum format = GL_NONE;
    GLenum type = GL_NONE;
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    format = m_image->format.ColorChanels( false ); // todo invert color
    type = m_image->format.DataType();
    glGetTextureImage( m_image->image, in_level, format, type, in_bufSize, in_pixels );
}

void gl::Image::GetCompressedImage( const GLint in_level, const GLsizei in_bufSize, void * in_pixels ) const
{
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    glGetCompressedTextureImage( m_image->image, in_level, in_bufSize, in_pixels );
}

void gl::Image::CopySubImage(   const GLint in_level, 
                                const GLint in_x, 
                                const GLint in_y, 
                                const offsets_t in_offsets, 
                                const dimensions_t in_dimensions ) const
{
    if( !m_image )
    {   
        // TODO: report a error 
        return;
    }

    switch ( m_image->target )
    {
    case GL_TEXTURE_1D:
        glCopyTextureSubImage1D( m_image->image, in_level, in_offsets.xoffset, in_x, in_y, in_dimensions.width );
        break;
    case GL_TEXTURE_1D_ARRAY:
    case GL_TEXTURE_2D:
    case GL_TEXTURE_RECTANGLE:
        glCopyTextureSubImage2D( m_image->image, in_level, in_offsets.xoffset, in_offsets.yoffset, in_x, in_y, in_dimensions.width, in_dimensions.height );
        break;
    case GL_TEXTURE_2D_ARRAY:
    case GL_TEXTURE_CUBE_MAP:
    case GL_TEXTURE_3D:
    case GL_TEXTURE_CUBE_MAP_ARRAY:
        glCopyTextureSubImage3D( m_image->image, in_level, in_offsets.xoffset, in_offsets.yoffset, in_offsets.zoffset, in_x, in_y, in_dimensions.width, in_dimensions.height );
        break;
    default:
        // TODO: error call
        break;
    }
}

void gl::Image::GetSubImage(    const GLint in_level,
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

void gl::Image::GetCompressedSubImage(  const GLint in_level,
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


void gl::Image::CopyImage(  const GLenum in_srcTarget,
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

void gl::Image::Invalidate( const GLint in_level, const offsets_t in_offsets, const dimensions_t in_dimensions ) const
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

void gl::Image::Clear( const void* in_data, const GLint in_level, const offsets_t in_offsets, const dimensions_t in_dimensions ) const
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

void gl::Image::Parameterfv(const GLenum in_pName, const GLfloat *m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }
 
    glTextureParameterfv( m_image->image, in_pName, m_params );   
}

void gl::Image::GetParameteriv(const GLenum in_pName, GLint *m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }

    glGetTextureParameteriv( m_image->image, in_pName, m_params );
}

void gl::Image::GetParameterfv(const GLenum in_pName, GLfloat *m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }

    glGetTextureParameterfv( m_image->image, in_pName, m_params );
}

void gl::Image::Parameteriv( const GLenum in_pName, const GLint* m_params ) const
{
    if ( !m_image )
    {
        // report a error
        return;
    }
 
    glTextureParameteriv( m_image->image, in_pName, m_params );
}

GLuint gl::Image::Handle(void) const
{
    if ( !m_image )
    {
        // report a error
        return 0;
    }
    
    return m_image->image;
}

GLenum gl::Image::Target(void) const
{
    return m_image->target;
}

gl::Image::operator GLuint(void) const
{
    if ( !m_image )
    {
        return 0;
    }
    
    return m_image->image;
}
