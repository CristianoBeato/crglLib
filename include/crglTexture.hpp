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
#ifndef __CRGL_TEXTURE_HPP__
#define __CRGL_TEXTURE_HPP__

namespace gl
{
    class Texture
    {
    public:

        struct offsets_t
        {
            GLint xoffset = 0; 
            GLint yoffset = 0; 
            GLint zoffset = 0;
        };

        struct dimensions_t
        {
            GLsizei width = 0;
            GLsizei height = 0;
            GLsizei depth = 0;
        };

        struct subImage_t
        {
            /// @brief the mipmap level
            GLint           level;

            /// @brief the multilayer image level / cubemap face
            GLsizei         layer;      //

            /// @brief compressed pixel buffer size
            GLsizei         imageSize;

            // pixel offsets 
            offsets_t       offsets;

            /// @brief dimensions of the subimage
            dimensions_t    dimension;  //
        };
        
        struct createInfo_t
        {
            /// @brief texture type 1/2/3D, Cubemap, rectangle, multisample, array
            GLenum          target; 

            /// @brief texture pixel format
            gl::Format      format; 

            /// @brief number of mipmap levels
            GLsizei         levels;

            /// @brief number of layers for TEXTURE_*D_ARRAY / TEXTURE_CUBE_MAP_ARRAY
            GLsizei         layers; 

            /// @brief sample count for TEXTURE_2D_MULTISAMPLE and TEXTURE_2D_MULTISAMPLE_ARRAY
            GLsizei         samples;

            /// @brief image width, height and depth dimensions 
            dimensions_t    dimensions;

            GLboolean       fixedsamplelocations;
        }; 

        Texture( void );
        ~Texture( void );

        /// @brief Create image handler and allocate fixed memory
        /// @param in_createInfo 
        /// @return true on sucess 
        bool    Create( const createInfo_t* in_createInfo );

        /// @brief destroy image handle and free image memory 
        void    Destroy( void );

        /// @brief Upload pixels to a sub image
        /// @param in_subimage subimage representation data  
        /// @param in_pixels pixel buffer/upack buffer offset
        void    SubImage( const subImage_t *in_subimage, const void *in_pixels ) const;

        /// @brief 
        /// @param in_subimage 
        /// @param in_pixels 
        void    CompressedSubImage( const subImage_t *in_subimage, const void *in_pixels );

        /// @brief Return the whole image data
        void GetImage( const GLint in_level, const GLsizei in_bufSize, void * in_pixels ) const;
        void GetCompressedImage( const GLint in_level, const GLsizei in_bufSize, void * in_pixels ) const; 

        /// @brief copy the content of the current frame buffer to the image 
        void CopySubImage( const subImage_t *in_subimage, const GLint in_x, const GLint in_y ) const;

        /// @brief retrieve the content of the image level
        /// @param level 
        /// @param xoffset 
        /// @param yoffset 
        /// @param zoffset 
        /// @param width 
        /// @param height 
        /// @param depth 
        /// @param type 
        /// @param bufSize 
        /// @param pixels 
        void    GetSubImage(    const GLint level,
                                const offsets_t in_offsets,
                                const dimensions_t in_dimensions,
                                const GLenum type,
                                const GLsizei bufSize,
                                void *pixels ) const;

        void    GetCompressedSubImage(  const GLint in_level,
                                        const offsets_t in_offsets,
                                        const dimensions_t in_dimensions,
                                        const GLsizei in_bufSize,
                                        void *in_pixels ) const;

        /// @brief Copy the content of the source image to this image
        /// @param in_source the source image name 
        /// @param in_srcLevel the source mip level
        /// @param in_dstLevel the destine mip level
        /// @param in_srcOffsets source image offsets
        /// @param in_dstOffsets destine image offsets 
        /// @param in_dimensions the copy dimension
        void    CopyImage(  const GLenum in_srcTarget,
                            const GLuint in_source,
                            const GLint in_srcLevel,
                            const GLint in_dstLevel,
                            const offsets_t in_srcOffsets,
                            const offsets_t in_dstOffsets,
                            const dimensions_t in_dimensions ) const;
        
        void Invalidate( const GLint in_level, const offsets_t in_offsets = { 0, 0, 0 }, const dimensions_t in_dimensions = { 0, 0, 0 } ) const;
        void Clear( const void* in_data, const GLint in_level, const offsets_t in_offsets = { 0, 0, 0 }, const dimensions_t in_dimensions = { 0, 0, 0 } ) const;
        void Parameteriv( const GLenum in_pName, const GLint* m_params ) const;
        void Parameterfv(  const GLenum in_pName, const GLfloat* m_params ) const;
        void GetParameteriv( const GLenum in_pName, GLint* m_params ) const;
        void GetParameterfv(  const GLenum in_pName, GLfloat* m_params ) const;
        GLuint Handle( void ) const;
        GLenum Target( void ) const;

        operator GLuint( void ) const;

    private:
        glCoreTexture_t*  m_image;
    };
};
#endif //!__CRGL_TEXTURE_HPP__