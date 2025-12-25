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
#ifndef __CRGL_VERTEX_ARRAY_HPP__
#define __CRGL_VERTEX_ARRAY_HPP__

namespace gl
{
    // configure vertex attribs
    typedef struct vertexAttrib_t 
    {
        GLuint      index = 0;          // vertex attribute index 
        GLuint      binding = 0;        // vertex buffer index, that element are 
        GLint       size = 0;           // number of elements in the vertex attribute
        GLenum      type = 0;           // type of the data element in the vertex attribute
        GLboolean   normalized = 0;     // if the values are normalized 
        GLuint      relativeoffset = 0; // relative offset in the vertex 
    
    } vertexAttrib_t;

    class VertexArray
    {
    public:
        VertexArray( void );
        ~VertexArray( void );
        void        Create( const vertexAttrib_t* in_vertexAttrib, const GLuint in_count );
        void        Destroy( void );
        void        BindElementBuffer( const GLuint in_buffer );
        void        BindeVertexBuffers( const GLuint* in_buffers, const GLintptr* in_offsets, const GLsizei* in_strides, const GLuint in_first, const GLsizei in_count );
        GLuint      GetHandle( void ) const;
        operator    GLuint( void ) const;

    private:
        glCoreVertexArray_t*    m_vertexArray;
    };
};
#endif //!__CRGL_VERTEX_ARRAY_HPP__