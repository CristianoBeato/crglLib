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
#include "creglContext.hpp"

#include <iostream>
#include <vector>

bool egl::Context::Create(const void *in_windowHandle)
{

    std::vector<EGLint> egl_attrbs;
    std::vector<EGLint> surface_attribs;
    std::vector<EGLint> context_attribs;
    EGLConfig config = nullptr;
    EGLint num_config = 0;

    auto contextCI = reinterpret_cast<const createInfo_t*>( in_windowHandle );
    if( !contextCI )
    {
        DebugOuput("Context error: createInfo_t\n" );
        return false;
    }

    // Display initialization sequence
    m_display = eglGetPlatformDisplay( contextCI->platform, contextCI->nativeDisplay, nullptr );
    
    // fallback
    if ( m_display == EGL_NO_DISPLAY ) 
    {
        DebugOuput("EGL error: eglGetPlatformDisplay failed\n" );
            
        m_display = eglGetDisplay( EGL_DEFAULT_DISPLAY ); 
        if (m_display == EGL_NO_DISPLAY) 
        {        
            DebugOuput("EGL error: eglGetDisplay failed\n" );
            return false;
        }
    }

    if ( !eglInitialize( m_display, nullptr, nullptr))
    {
        DebugOuput("EGL error: eglInitialize failed\n" ); 
        return false;
    }

    // We are using OpenGL Desktop context
    egl_attrbs.push_back( EGL_RENDERABLE_TYPE );
    egl_attrbs.push_back( EGL_OPENGL_BIT );
    
    egl_attrbs.push_back( EGL_SURFACE_TYPE );
    if ( contextCI->pbuffer )
        egl_attrbs.push_back( EGL_PBUFFER_BIT );
    else
        egl_attrbs.push_back( EGL_WINDOW_BIT );

    // set surface color depth
    egl_attrbs.push_back( EGL_RED_SIZE );
    egl_attrbs.push_back( contextCI->color );
    egl_attrbs.push_back( EGL_GREEN_SIZE );
    egl_attrbs.push_back( contextCI->color );
    egl_attrbs.push_back( EGL_BLUE_SIZE );
    egl_attrbs.push_back( contextCI->color );    
    egl_attrbs.push_back( EGL_ALPHA_SIZE );
    egl_attrbs.push_back( contextCI->color );

    // set depth stencil
    egl_attrbs.push_back( EGL_DEPTH_SIZE );
    egl_attrbs.push_back( contextCI->depth );
    egl_attrbs.push_back( EGL_STENCIL_SIZE );
    egl_attrbs.push_back( contextCI->stencil );

    if ( contextCI->hdr10 )
    {
        egl_attrbs.push_back( EGL_COLOR_COMPONENT_TYPE_EXT );
        egl_attrbs.push_back( EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT );
    }
    
    // finish atrib list
    egl_attrbs.push_back( EGL_NONE );

    eglChooseConfig( m_display, egl_attrbs.data(), &config, 1, &num_config);

    if (num_config == 0) 
        return false;
    
    eglBindAPI(EGL_OPENGL_API); // using OpenGL desktop

    if ( contextCI->pbuffer )
    {
        // cria surface offscreen (pbuffer 1x1 só pra constar)
        EGLint pbuffer_attribs[] = 
        {
            EGL_WIDTH, 1,
            EGL_HEIGHT, 1,
            EGL_NONE,
        };
    
        m_surface = eglCreatePbufferSurface( m_display, config, pbuffer_attribs);
        if ( m_surface == EGL_NO_SURFACE)
        {
            DebugOuput("EGL error: eglCreatePbufferSurface failed\n" );
            return false;
        }
    }
    else
    {
        if ( contextCI->hdr10 )
        {
            surface_attribs.push_back( EGL_GL_COLORSPACE );
            surface_attribs.push_back( EGL_GL_COLORSPACE_BT2020_PQ_EXT ); // EGL_GL_COLORSPACE_BT2020_PQ_EXT is the standard for HDR10
            
        }
        
        surface_attribs.push_back( EGL_NONE );


        m_surface = eglCreateWindowSurface( m_display, config, contextCI->nativeWindow, surface_attribs.data() );
    }

    context_attribs.push_back( EGL_CONTEXT_MAJOR_VERSION_KHR );
    context_attribs.push_back( contextCI->verMaj );
    context_attribs.push_back( EGL_CONTEXT_MINOR_VERSION_KHR );
    context_attribs.push_back( contextCI->verMin );
    
    context_attribs.push_back( EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR );
    if ( contextCI->core )
        context_attribs.push_back( EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR );
    else
        context_attribs.push_back( EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR );

    context_attribs.push_back( EGL_CONTEXT_OPENGL_DEBUG );
    if ( contextCI->debug )
        context_attribs.push_back( EGL_TRUE );
    else
        context_attribs.push_back( EGL_FALSE );

        // finish atrib list
    context_attribs.push_back( EGL_NONE );

    m_context = eglCreateContext( m_display, config, EGL_NO_CONTEXT, context_attribs.data() );
    if ( m_context == EGL_NO_CONTEXT)
    {
        DebugOuput("EGL error: eglCreateContext failed\n" );
        return false;
    }

    if ( eglMakeCurrent( m_display, m_surface, m_surface, m_context ) != EGL_TRUE ) 
    {
        DebugOuput("EGL error: eglMakeCurrent failed\n" );
        return false;
    }

    return true;
}

void egl::Context::Destroy(void)
{
    if ( m_context != nullptr )
    {
        eglDestroyContext( m_display, m_context );
        m_context = nullptr;
    }
    
    if ( m_surface != nullptr )
    {
        eglDestroySurface( m_display, m_surface );
        m_surface = nullptr;
    }
}

bool egl::Context::MakeCurrent(void)
{
    return eglMakeCurrent( m_display, m_surface, nullptr, m_context ) == EGL_TRUE;
}

bool egl::Context::Release(void)
{
    return eglMakeCurrent( m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT ) == EGL_TRUE;
}

bool egl::Context::SwapBuffers(void)
{
    return eglSwapBuffers( m_display, m_surface ) == EGL_TRUE;
}

void *egl::Context::GetFunctionPointer(const char *in_name) const
{
    return reinterpret_cast<void*>( eglGetProcAddress( in_name ) );
}

void egl::Context::DebugOuput(const char *in_message) const
{
    std::cerr << in_message;
}
