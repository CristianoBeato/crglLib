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
        GLint maxUBOBindings = 0;
        GLint maxSSBOBindings = 0;
        GLint maxAtomicBindings = 0;
        GLint maxTFBindings = 0;
        GLint maxVBOBindings = 0;
        GLint maxVertexAttribs = 0;
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

    // map the context state 
    typedef struct coreState_t
    {
        GLuint              indirectDrawBuffer = 0;
        GLuint              vertexArray = 0;
        GLuint              frameBuffer = 0;
        programState_t      programs;
        textureState_t      textures;
    } coreState_t;

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

        /// @brief flush context state
        /// @param  
        void    Flush( void );
        void    Finish( void );
        GLuint  BindProgram( const GLuint in_program );
        GLuint  BindPipeline( const GLuint in_pipeline );
        GLuint  BindVertexArray( const GLuint in_vertexArray );
        GLuint  BindFrameBuffer( const GLuint in_framebuffer );
        GLuint  BindShaderStorageBuffers( );
        GLuint  BindIndirectBuffer( const GLuint in_buffer );  
        GLuint  BindUniformBuffers( const GLuint* in_buffers, const GLintptr* in_offsets, const GLsizeiptr* in_sizes, const GLuint in_first, const GLsizei in_count );
        GLuint  BindShaderStorageBuffers( const GLuint* in_buffers, const GLintptr* in_offsets, const GLsizeiptr* in_sizes, const GLuint in_first, const GLsizei in_count );
        GLuint  BindTextures( const GLuint* in_textures, const GLuint* in_samplers, const GLuint in_first, const GLuint in_count );

        const   coreFeatures_t  Features( void ) const;  
        const   coreState_t     CurrentState( void ) const;

    private:
        coreFeatures_t    m_features;
        coreState_t       m_state;

        void    LoadFunctions( void );
        static void APIENTRY DebugOutputCall( GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam );
    };

};
#endif //!__CRGL_CONTEXT_HPP__