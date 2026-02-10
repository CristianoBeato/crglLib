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
    class VertexArray
    {
    public:
        ///@brief specify the organization of vertex arrays
        typedef struct vertexAttrib_t 
        {
            /// @brief The generic vertex attribute array being described.
            GLuint      index = 0;

            /// @brief The index of the vertex buffer binding with which to associate the generic vertex attribute.
            GLuint      binding = 0;        // vertex buffer index, that element are 
            
            /// @brief  The number of values per vertex that are stored in the array.
            GLint       size = 0;
            
            /// @brief The type of the data stored in the array.
            GLenum      type = 0;
            
            /// @brief Specifies whether fixed-point data values should be normalized (GL_TRUE) 
            /// or converted directly as fixed-point values (GL_FALSE) when they are accessed.
            /// This parameter is ignored if type is GL_FIXED.
            GLboolean   normalized = 0;
            
            /// @brief A byte offset of the first element relative to the start of the vertex buffer binding this attribute fetches from.
            GLuint      relativeoffset = 0; // relative offset in the vertex 
        } vertexAttrib_t;
       
        //
        typedef struct bufferBindingPoint_t
        {
            /// @brief The name of a buffer to bind to the vertex buffer binding point.
            GLuint      buffer = 0; 
            /// @brief The offset of the first element of the buffer.
            GLintptr    offset = 0; 
            /// @brief The distance between elements within the buffer.
            GLsizei     stride = 0;
        } bufferBindingPoint_t;

        VertexArray( void );
        ~VertexArray( void );
        void        Create( const vertexAttrib_t* in_vertexAttrib, const GLuint in_count );
        void        Destroy( void );
        void        BindElementBuffer( const GLuint in_buffer );

        /// @brief bind a buffer to a vertex array buffer binding point
        /// @param in_bufferBinding 
        /// @param in_bindingindex The index of the vertex buffer binding point to which to bind the buffer.
        void        BindeVertexBuffer( const bufferBindingPoint_t in_bufferBinding, const GLuint in_bindingindex );
        void        BindeVertexBuffers( const bufferBindingPoint_t* in_bindings, const GLuint in_first, const GLsizei in_count );
        GLuint      GetHandle( void ) const;
        operator    GLuint( void ) const;

    private:
        glCoreVertexArray_t*    m_vertexArray;
    };
};
#endif //!__CRGL_VERTEX_ARRAY_HPP__