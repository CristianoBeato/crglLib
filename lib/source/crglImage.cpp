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

static const char k_INVALID_TEXTURE_TARGET_MSG[41] = { "gl::Image::Create invalid texture target" };

typedef struct glCoreImage_t
{
    GLenum  target = 0;
    GLenum  format = 0;
    GLuint  image = 0;
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
    const GLsizei in_width, 
    const GLsizei in_height, 
    const GLsizei in_depth )
{
    Destroy();

    m_image = static_cast<glCoreImage_t*>( std::malloc( sizeof( glCoreImage_t ) ) );
    m_image->target = in_target;
    m_image->format = in_internalformat;
    glCreateTextures( m_image->target, 1, &m_image->image );
    
    // allocate the texture memory
    switch ( m_image->target )
    {
    case GL_TEXTURE_1D:
        glTextureStorage1D( m_image->image, in_levels, m_image->format, in_width );
        break;
    case GL_TEXTURE_1D_ARRAY:
        glTextureStorage2D( m_image->image, in_levels, m_image->format, in_width, in_layers );
        break;
    case GL_TEXTURE_2D:
        glTextureStorage2D( m_image->image, in_levels, m_image->format, in_width, in_height );
        break;
    case GL_TEXTURE_3D:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_width, in_height, in_depth );
        break;
    case GL_TEXTURE_2D_ARRAY:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_width, in_height, in_depth );
        break;
    case GL_TEXTURE_CUBE_MAP:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_width, in_height, 6 );
        break;
    case GL_TEXTURE_CUBE_MAP_ARRAY:
        glTextureStorage3D( m_image->image, in_levels, m_image->format, in_width, in_width, in_width * 6 * in_layers );
        break;
    default:
        glDebugMessageInsert( GL_DEBUG_SOURCE_THIRD_PARTY, GL_DEBUG_TYPE_ERROR, 0, GL_DEBUG_SEVERITY_HIGH, 41, k_INVALID_TEXTURE_TARGET_MSG );
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

        std::free( m_image );
        m_image = nullptr;
    }
}

void gl::Image::SubImage()
{
}

void gl::Image::GetSubImage()
{
}
