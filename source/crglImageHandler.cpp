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
#include "crglImageHandler.hpp"

typedef struct glCoreImageHandler_t
{
    GLuint64 handler;
} glCoreImageHandler_t;

gl::ImageHandler::ImageHandler( void ) : m_handler( nullptr )
{
}

gl::ImageHandler::~ImageHandler( void )
{
    Destroy();
}

void gl::ImageHandler::Create( const GLuint in_texture, const GLuint in_sample )
{
    Destroy();
    m_handler = new glCoreImageHandler_t();

    if ( in_sample != 0 )
        m_handler->handler = glGetTextureSamplerHandleARB( in_texture, in_sample );
    else
        m_handler->handler = glGetTextureHandleARB( in_texture );

}

void gl::ImageHandler::Destroy(void)
{
    if( m_handler == nullptr )
    return;
    
    if( m_handler->handler == 0 )
    {
        if( IsImageResident() )
            MakeImageNonResident();

        if ( IsTextureResident() )
            MakeTextureNonResident();
    }

    delete m_handler;
}

void gl::ImageHandler::MakeTextureResident(void)
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return;

    glMakeTextureHandleResidentARB( m_handler->handler );
}

void gl::ImageHandler::MakeTextureNonResident( void )
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return;

    glMakeTextureHandleNonResidentARB( m_handler->handler );
}

void gl::ImageHandler::MakeImageResident( const GLenum in_acess )
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return;

    glMakeImageHandleResidentARB( m_handler->handler, in_acess );
}

void gl::ImageHandler::MakeImageNonResident( void )
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return;

    glMakeImageHandleNonResidentARB( m_handler->handler );
}

bool gl::ImageHandler::IsTextureResident( void ) const
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return false;

    return glIsTextureHandleResidentARB( m_handler->handler ) == GL_TRUE;
}

bool gl::ImageHandler::IsImageResident( void ) const
{
    if( m_handler == nullptr || m_handler->handler == 0 )
        return false;

    return glIsImageHandleResidentARB( m_handler->handler ) == GL_TRUE;
}