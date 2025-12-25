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
#ifndef __CRGL_SHADERS_HPP__
#define __CRGL_SHADERS_HPP__

namespace gl
{
    class Shader
    {
    public:
        Shader( void );
        ~Shader( void );
        bool                Create( const GLenum in_stage,const GLchar *const* in_sources, const GLint *in_lengths, const GLsizei in_count );
        void                Destroy( void );
        void                GetLog( GLint *in_length, GLchar *in_infoLog );
        operator            GLuint( void ) const;
        operator            glCoreShader_t*( void ) const { return m_shader; }

    private:
        glCoreShader_t* m_shader;    
    };

    class Program
    {
    public:
        Program( void );
        ~Program( void );
        bool        Create( const Shader** in_shaders, const GLsizei in_count );
        void        Destroy( void );
        void        GetLog( GLint *in_length, GLchar *in_infoLog );
        operator    GLuint( void ) const;
        operator    glCoreProgram_t*( void ) const { return m_program; }
    
    private:
        glCoreProgram_t*    m_program;
    };

    class ProgramPipeline
    {
    public:
        ProgramPipeline( void );
        ~ProgramPipeline( void );
        bool        Create( void );
        void        Destroy( void );
        void        UseProgram( const Program** in_program, const uint32_t in_count );
        void        GetLog( GLint *in_length, GLchar *in_infoLog );
        operator    GLuint( void ) const;
        operator    glCorePipeline_t*( void ) const { return m_pipeline; }
    private:
        glCorePipeline_t*   m_pipeline;
    };
};
#endif //!__CRGL_SHADERS_HPP__