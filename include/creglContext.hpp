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

#ifndef __CREGL_CONTEXT_HPP__
#define __CREGL_CONTEXT_HPP__

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "crglContext.hpp"

namespace egl
{
    class Context : public gl::Context
    {
    public:
        struct  createInfo_t
        {
            bool                    pbuffer = false;
            bool                    core = false;
            bool                    debug = false;
            bool                    hdr10 = false;
            uint8_t                 color = 8;
            uint8_t                 depth = 24;
            uint8_t                 stencil = 8;
            int                     verMin = 4;
            int                     verMaj = 5;
            EGLenum                 platform;   // display platform ( EGL_PLATFORM_ANGLE_ANGLE / EGL_PLATFORM_WAYLAND_KHR / EGL_PLATFORM_X11_KHR / EGL_PLATFORM_SURFACELESS_MESA)
            EGLNativeWindowType     nativeWindow = 0;
            EGLNativeDisplayType    nativeDisplay = 0;    
        };

        Context( void );
        ~Context( void );

        virtual bool    Create( const void* in_windowHandle) override;
        virtual void    Destroy( void ) override;
        virtual bool    MakeCurrent( void ) override;
        virtual bool    Release( void ) override;
        virtual bool    SwapBuffers( void ) override;
        virtual void*   GetFunctionPointer( const char* in_name ) const override;
        virtual void    DebugOuput( const char* in_message ) const override;
 
    private:
        EGLDisplay m_display;
        EGLContext m_context;
        EGLSurface m_surface;
    };
};

#endif //!__CREGL_CONTEXT_HPP__