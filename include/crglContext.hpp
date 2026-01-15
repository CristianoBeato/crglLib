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

#ifndef __CRGL_CONTEXT_HPP__
#define __CRGL_CONTEXT_HPP__

namespace gl
{
    // current suported features
    typedef struct coreFeatures_t
    {
        GLint maxTextures = 0;
        GLint maxCombined = 0;
        GLint maxColorAttachments = 0;
        GLint maxUBOBindings = 0;
        GLint maxSSBOBindings = 0;
        GLint maxAtomicBindings = 0;
        GLint maxTFBindings = 0;
        GLint maxVBOBindings = 0;
        GLint maxVertexAttribs = 0;
        GLint maxViewports = 0;
        GLint maxDrawBuffers = 0;
    } coreFeatures_t;

    typedef struct textureState_t
    {
        GLuint* samplers = nullptr;
        GLuint* textures = nullptr;
    } textureState_t;

    typedef struct programState_t
    {
        GLuint  program = 0;            // current bind program
        GLuint  pipeline = 0;           // current bind pipeline
        GLuint* uniformBuffers = nullptr;
        GLuint* shaderStorageBuffers = nullptr;
    } programState_t;

    typedef struct stencilState_t
    {
        
    } stencilState_t;

    typedef struct depthState_t
    {
        GLboolean   testing = GL_FALSE;
        GLboolean   clamp = GL_FALSE;
        GLboolean   mask = GL_FALSE;
        GLboolean   func = GL_LESS;
        GLdouble    clear = 0.0;
        GLfloat     factor = 0.0f;
        GLfloat     units = 0.0f; 
    } depthState_t;

    typedef struct blendingState_t
    {
        GLboolean   blend = GL_FALSE;
        GLboolean   colorLogic = GL_FALSE;
        GLenum      modeRGB = GL_FUNC_ADD; 
        GLenum      modeAlpha = GL_FUNC_ADD;
        GLenum      sfactorRGB = GL_ONE;
        GLenum      dfactorRGB = GL_ZERO; 
        GLenum      sfactorAlpha = GL_ONE; 
        GLenum      dfactorAlpha = GL_ZERO;
    } blendingState_t;

    typedef struct drawbuffer_t
    {
        blendingState_t     blending;
    } drawbuffer_t;

    typedef struct scissorState_t
    {
        GLboolean scissor;
    } scissorState_t;

    // represent a viewport space
    typedef struct viewport_t
    {
        GLfloat left = 0.0f;
        GLfloat bottom = 0.0f;
        GLfloat width = 0.0f;
        GLfloat height = 0.0f;
        GLfloat near = 0.0f;
        GLfloat far = 0.0f;
    };

    // map the context state 
    typedef struct coreState_t
    {
        GLboolean           discardRaster = GL_FALSE;
        GLboolean           multisampling = GL_FALSE;
        GLuint              indirectDrawBuffer = 0;
        GLuint              vertexArray = 0;
        GLuint              frameBuffer = 0;
        programState_t      programs;
        textureState_t      textures;
        stencilState_t      stencilState;
        depthState_t        depthState;
        drawbuffer_t*       drawBuffers;
        viewport_t*         viewports;
    } coreState_t;

    typedef struct rect_t
    {
        GLint   x = 0;
        GLint   y = 0;
        GLsizei width = 0;
        GLsizei height = 0;
    } rect_t;

    class Context
    {
    public:
        Context( void );
        ~Context( void );

        virtual bool    Create( const void* in_windowHandle) = 0;
        virtual void    Destroy( void );
        virtual bool    MakeCurrent( void ) = 0;
        virtual bool    Release( void ) = 0;
        virtual bool    SwapBuffers( void ) = 0;
        virtual void*   GetFunctionPointer( const char* in_name ) const;
        virtual void    DebugOuput( const char* in_message ) const = 0;

        // init OpenGL debugOuput, load functions
        bool    Init( void );
        void    Finalize( void );

        /// @brief Clear context state, unbind buffers, textures, states to defalt
        /// @param  
        void    Clear( void );

        /// @brief Force a syncronization whit the drive, this will query all properties from drive
        /// to check external context modifications
        void    Sync( void );

        /// @brief flush context state
        /// @param  
        void    Flush( void );
        void    Finish( void );

        /// @brief Update the blend operation states
        /// @param in_state the new blending state
        /// @return the old state in use
        blendingState_t SetBlendState( const GLuint in_drawBuffer, const blendingState_t in_state );

        stencilState_t SetStencilState( const stencilState_t in_steate );

        depthState_t SetDepthState( const depthState_t in_state );

        viewport_t  SetViewportState( const GLuint in_viewport, const viewport_t in_stae );

        /// @brief 
        /// @param in_enable 
        /// @return 
        GLboolean   Multisample( const GLboolean in_enable );

        /// @brief Discard raster pipeline.
        /// @param in_enable When enabled, primitives are discarded immediately before the rasterization stage,
        /// but after the optional transform feedback stage.
        /// When disabled, primitives are passed through to the rasterization stage to be processed normally. 
        /// @return The old state
        GLboolean   DiscardRaster( const GLboolean in_enable );

        /// @brief bind a shader program direct to the execution pipeline
        /// @param in_program 
        /// @return 
        GLuint  BindProgram( const GLuint in_program );

        /// @brief bind a program separable pipeline in the execution line 
        /// @param in_pipeline 
        /// @return 
        GLuint  BindPipeline( const GLuint in_pipeline );

        /// @brief bind the vertex array object in the excution pipeline
        /// @param in_vertexArray 
        /// @return 
        GLuint  BindVertexArray( const GLuint in_vertexArray );
        GLuint  BindFrameBuffer( const GLuint in_framebuffer );
        GLuint  BindShaderStorageBuffers( );
        GLuint  BindIndirectBuffer( const GLuint in_buffer );  
        GLuint  BindUniformBuffers( const GLuint* in_buffers, const GLintptr* in_offsets, const GLsizeiptr* in_sizes, const GLuint in_first, const GLsizei in_count );
        GLuint  BindShaderStorageBuffers( const GLuint* in_buffers, const GLintptr* in_offsets, const GLsizeiptr* in_sizes, const GLuint in_first, const GLsizei in_count );
        GLuint  BindTextures( const GLuint* in_textures, const GLuint* in_samplers, const GLuint in_first, const GLuint in_count );
        
        void    BlitToCurrentFrameBuffer( const GLuint in_source, const rect_t in_srcRect, const rect_t in_dstRect, const GLbitfield in_mask, const GLenum in_filter );
        
        const   coreFeatures_t  Features( void ) const { return m_features; };
        const   coreState_t     CurrentState( void ) const { return m_state; }

    private:
        coreFeatures_t    m_features;
        coreState_t       m_state;

        void    LoadFunctions( void );
        static void APIENTRY DebugOutputCall( GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam );
    };

};
#endif //!__CRGL_CONTEXT_HPP__