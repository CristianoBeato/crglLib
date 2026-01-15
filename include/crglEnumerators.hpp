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
#ifndef __CRGL_ENUMS_HPP__
#define __CRGL_ENUMS_HPP__

namespace gl
{
    enum boolean : GLboolean
    {
        TRUE = GL_TRUE,
        FALSE = GL_FALSE,
        ONE = GL_ONE,
        ZERO = GL_ZERO,
    };

    /// @brief Specifies a symbolic constant indicating a GL capability. glEnable/glEnablei and glDisable/glDisablei
    enum state_t : GLenum
    {
        /// @brief If enabled, blend the computed fragment color values with the values in the color buffers.
        /// See glBlendFunc. Sets the blend enable/disable flag for all color buffers.
        BLEND = GL_BLEND,
        
        /// @brief If enabled, clip geometry against user-defined half space i.
        CLIP_DISTANCE = GL_CLIP_DISTANCE0,
        
        /// @brief If enabled, apply the currently selected logical operation to the computed fragment color and color buffer values.
        /// See glLogicOp.
        COLOR_LOGIC_OP = GL_COLOR_LOGIC_OP,
        
        /// @brief If enabled, cull polygons based on their winding in window coordinates. See glCullFace.
        CULL_FACE = GL_CULL_FACE,
        
        /// @brief If enabled, cull polygons based on their winding in window coordinates. See glCullFace. 
        DEBUG_OUTPUT = GL_DEBUG_OUTPUT,
        
        /// @brief If enabled, debug messages are produced by a debug context. 
        /// When disabled, the debug message log is silenced. 
        /// Note that in a non-debug context, very few, if any messages might be produced, 
        /// even when GL_DEBUG_OUTPUT is enabled.
        DEBUG_OUTPUT_SYNCHRONOUS = GL_DEBUG_OUTPUT_SYNCHRONOUS,
        
        /// @brief If enabled, the -wc ≤ zc ≤ wc plane equation is ignored by view volume clipping (effectively, 
        /// there is no near or far plane clipping). See glDepthRange.
        DEPTH_CLAMP = GL_DEPTH_CLAMP,
        
        /// @brief If enabled, do depth comparisons and update the depth buffer. 
        /// Note that even if the depth buffer exists and the depth mask is non-zero, 
        /// the depth buffer is not updated if the depth test is disabled. 
        /// See glDepthFunc and glDepthRange.
        DEPTH_TEST = GL_DEPTH_TEST,
        
        /// @brief If enabled, dither color components or indices before they are written to the color buffer.
        DITHER = GL_DITHER,
        
        /// @brief If enabled and the value of GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING for the framebuffer attachment
        /// corresponding to the destination buffer is GL_SRGB,  the R, G, and B destination color values 
        /// (after conversion from fixed-point to floating-point) are considered to be encoded for the sRGB color space and hence are 
        /// linearized prior to their use in blending.
        FRAMEBUFFER_SRGB = GL_FRAMEBUFFER_SRGB,
        
        /// @brief If enabled, draw lines with correct filtering. Otherwise, draw aliased lines.
        /// See glLineWidth.
        LINE_SMOOTH = GL_LINE_SMOOTH,
        
        /// @brief If enabled, use multiple fragment samples in computing the final color of a pixel.
        /// See glSampleCoverage.
        MULTISAMPLE = GL_MULTISAMPLE,
        
        /// @brief If enabled, and if the polygon is rendered in GL_FILL mode, 
        /// an offset is added to depth values of a polygon's fragments before the depth comparison is performed. 
        /// See glPolygonOffset.
        POLYGON_OFFSET_FILL = GL_POLYGON_OFFSET_FILL,
        
        /// @brief If enabled, and if the polygon is rendered in GL_LINE mode, 
        /// an offset is added to depth values of a polygon's fragments before the depth comparison is performed. 
        /// See glPolygonOffset.
        POLYGON_OFFSET_LINE = GL_POLYGON_OFFSET_LINE,
        
        /// @brief If enabled, an offset is added to depth values of a polygon's fragments before the depth comparison is performed, 
        /// if the polygon is rendered in GL_POINT mode. 
        /// See glPolygonOffset.
        POLYGON_OFFSET_POINT = GL_POLYGON_OFFSET_POINT,
        
        /// @brief If enabled, draw polygons with proper filtering.
        /// Otherwise, draw aliased polygons. For correct antialiased polygons, 
        /// an alpha buffer is needed and the polygons must be sorted front to back.
        POLYGON_SMOOTH = GL_POLYGON_SMOOTH,
        
        /// @brief Enables primitive restarting. 
        /// If enabled, any one of the draw commands which transfers a set of generic attribute array elements to 
        /// the GL will restart the primitive when the index of the vertex is equal to the primitive restart index. 
        /// See glPrimitiveRestartIndex.
        PRIMITIVE_RESTART = GL_PRIMITIVE_RESTART,
        
        /// @brief Enables primitive restarting with a fixed index.
        /// If enabled, any one of the draw commands which transfers a set of generic attribute array elements to the GL will restart the primitive
        /// when the index of the vertex is equal to the fixed primitive index for the specified index type. 
        /// The fixed index is equal to $ 2^{n}-1 $ where n is equal to 8 for GL_UNSIGNED_BYTE, 
        /// 16 for GL_UNSIGNED_SHORT and 32 for GL_UNSIGNED_INT.
        PRIMITIVE_RESTART_FIXED_INDEX = GL_PRIMITIVE_RESTART_FIXED_INDEX,
        
        /// @brief If enabled, all primitives are discarded before rasterization,
        /// but after any optional transform feedback. Also causes glClear and glClearBuffer commands to be ignored.
        RASTERIZER_DISCARD = GL_RASTERIZER_DISCARD,
        
        /// @brief If enabled, compute a temporary coverage value where each bit is determined by the alpha value at the corresponding sample location. 
        /// The temporary coverage value is then ANDed with the fragment coverage value.
        SAMPLE_ALPHA_TO_COVERAGE = GL_SAMPLE_ALPHA_TO_COVERAGE,
        
        /// @brief If enabled, each sample alpha value is replaced by the maximum representable alpha value.
        SAMPLE_ALPHA_TO_ONE = GL_SAMPLE_ALPHA_TO_ONE,
        
        /// @brief If enabled, the fragment's coverage is ANDed with the temporary coverage value.
        /// If GL_SAMPLE_COVERAGE_INVERT is set to GL_TRUE, invert the coverage value.
        /// See glSampleCoverage.
        SAMPLE_COVERAGE = GL_SAMPLE_COVERAGE,
        
        /// @brief If enabled, the active fragment shader is run once for each covered sample, 
        /// or at fraction of this rate as determined by the current value of GL_MIN_SAMPLE_SHADING_VALUE.
        /// See glMinSampleShading.
        SAMPLE_SHADING = GL_SAMPLE_SHADING,
        
        /// @brief If enabled, 
        /// the sample coverage mask generated for a fragment during rasterization will be ANDed with the value of GL_SAMPLE_MASK_VALUE before shading occurs. 
        /// See glSampleMaski.
        SAMPLE_MASK = GL_SAMPLE_MASK,
        
        /// @brief If enabled, discard fragments that are outside the scissor rectangle. 
        /// See glScissor.
        SCISSOR_TEST = GL_SCISSOR_TEST,
        
        /// @brief If enabled, do stencil testing and update the stencil buffer.
        /// See glStencilFunc and glStencilOp.
        STENCIL_TEST = GL_STENCIL_TEST,
        
        /// @brief If enabled, cubemap textures are sampled such that when linearly sampling from the border between two adjacent faces, 
        /// texels from both faces are used to generate the final sample value. 
        /// When disabled, texels from only a single face are used to construct the final sample value.
        TEXTURE_CUBE_MAP_SEAMLESS = GL_TEXTURE_CUBE_MAP_SEAMLESS,
        
        /// @brief If enabled and a vertex or geometry shader is active, 
        /// then the derived point size is taken from the (potentially clipped) shader builtin gl_PointSize and clamped to the implementation-dependent point size range.
        PROGRAM_POINT_SIZE = GL_PROGRAM_POINT_SIZE,
    };

    /// @brief face mode, used by 
    // glCullFace, glStencilFuncSeparate, glStencilOpSeparate
    enum face_t : GLenum
    {
        FRONT = GL_FRONT,
        BACK = GL_BACK,
        FRONT_AND_BACK = GL_FRONT_AND_BACK
    };
    
    namespace buffer
    {
        enum buffer_target_t : GLenum
        {
            /// @brief Vertex attributes
            ARRAY_BUFFER                = GL_ARRAY_BUFFER,
            
            /// @brief Atomic counter storage
            ATOMIC_COUNTER_BUFFER       = GL_ATOMIC_COUNTER_BUFFER,
            
            /// @brief Buffer copy source
            COPY_READ_BUFFER            = GL_COPY_READ_BUFFER,

            /// @brief Buffer copy destination
            COPY_WRITE_BUFFER           = GL_COPY_WRITE_BUFFER,

            /// @brief Indirect compute dispatch commands
            DISPATCH_INDIRECT_BUFFER    = GL_DISPATCH_INDIRECT_BUFFER,

            /// @brief Indirect command arguments
            DRAW_INDIRECT_BUFFER        = GL_DRAW_INDIRECT_BUFFER,

            /// @brief Vertex array indices
            ELEMENT_ARRAY_BUFFER        = GL_ELEMENT_ARRAY_BUFFER,
            
            /// @brief Draw parameters
            PARAMETER_BUFFER            = GL_PARAMETER_BUFFER,

            /// @brief Pixel read target
            PIXEL_PACK_BUFFER           = GL_PIXEL_PACK_BUFFER,

            /// @brief Texture data source
            PIXEL_UNPACK_BUFFER         = GL_PIXEL_UNPACK_BUFFER,
            
            /// @brief Query result buffer
            QUERY_BUFFER                = GL_QUERY_BUFFER,
            
            /// @brief Read-write storage for shaders
            SHADER_STORAGE_BUFFER       = GL_SHADER_STORAGE_BUFFER,
            
            /// @brief Texture data buffer
            TEXTURE_BUFFER              = GL_TEXTURE_BUFFER,
            
            /// @brief Transform feedback buffer
            TRANSFORM_FEEDBACK_BUFFER   = GL_TRANSFORM_FEEDBACK_BUFFER,
            
            /// @brief Uniform block storage
            UNIFORM_BUFFER              = GL_UNIFORM_BUFFER
        };

        enum buffer_usage_t : GLenum
        {
            /// @brief The data store contents will be specified once by the application,
            /// and sourced at most a few times.
            STREAM_DRAW = GL_STREAM_DRAW,
            
            /// @brief The data store contents will be specified once by reading data from
            /// the GL, and queried at most a few times by the application.
            STREAM_READ = GL_STREAM_READ,
            
            /// @brief The data store contents will be specified once by reading data from
            /// the GL, and sourced at most a few times.
            STREAM_COPY = GL_STREAM_COPY,
            
            /// @brief The data store contents will be specified once by the application,
            /// and sourced many times.
            STATIC_DRAW = GL_STATIC_DRAW,
            
            /// @brief The data store contents will be specified once by reading data from
            /// the GL, and queried many times by the application.
            STATIC_READ = GL_STATIC_READ,
            
            /// @brief The data store contents will be specified once by reading data from
            /// the GL, and sourced many times.
            STATIC_COPY = GL_STATIC_COPY,
            
            /// @brief The data store contents will be respecified repeatedly by the 
            /// application, and sourced many times.
            DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
            
            /// @brief The data store contents will be respecified repeatedly by reading
            /// data from the GL, and queried many times by the application.
            DYNAMIC_READ = GL_DYNAMIC_READ,
            
            /// @brief The data store contents will be respecified repeatedly by reading
            /// data from the GL, and sourced many times.
            DYNAMIC_COPY = GL_DYNAMIC_COPY
        };

        enum buffer_access_t : GLenum
        {
            /// @brief 
            READ_ONLY,

            /// @brief 
            WRITE_ONLY,
            
            /// @brief 
            READ_WRITE
        };

        enum buffer_access_flags_t : GLbitfield
        {
            /// @brief Indicates that the returned pointer may be used to read
            /// buffer object data. No GL error is generated if the pointer is used to query
            /// a mapping which excludes this flag, but the result is undefined and system
            /// errors (possibly including program termination) may occur.
            MAP_READ_BIT = GL_MAP_READ_BIT,

            /// @brief Indicates that the returned pointer may be used to modify
            /// buffer object data. No GL error is generated if the pointer is used to modify
            /// a mapping which excludes this flag, but the result is undefined and system
            /// errors (possibly including program termination) may occur.
            MAP_WRITE_BIT = GL_MAP_WRITE_BIT,

            // @brief Indicates that it is not an error for the GL to read
            // data from or write data to the buffer while it is mapped (see section 6.3.2).
            // If this bit is set, the value of BUFFER_STORAGE_FLAGS for the buffer being
            // mapped must include MAP_PERSISTENT_BIT.
            MAP_PERSISTENT_BIT = GL_MAP_PERSISTENT_BIT, 

            /// @brief Indicates that the mapping should be performed co-
            /// herently. That is, such a mapping follows the rules set forth in section 6.2.
            /// If this bit is set, the value of BUFFER_STORAGE_FLAGS for the buffer being
            /// mapped must include MAP_COHERENT_BIT.
            MAP_COHERENT_BIT = GL_MAP_COHERENT_BIT,
            
            /// @brief Indicates that the previous contents of the
            /// specified range may be discarded. Data within this range are undefined with
            /// the exception of subsequently written data. No GL error is generated if sub-
            /// sequent GL operations access unwritten data, but the result is undefined and
            /// system errors (possibly including program termination) may occur. This flag
            /// may not be used in combination with MAP_READ_BIT.
            MAP_INVALIDATE_RANGE_BIT = GL_MAP_INVALIDATE_RANGE_BIT,

            /// @brief Indicates that the previous contents of the
            /// entire buffer may be discarded. Data within the entire buffer are undefined
            /// with the exception of subsequently written data. No GL error is generated if
            /// subsequent GL operations access unwritten data, but the result is undefined
            /// and system errors (possibly including program termination) may occur. This
            /// flag may not be used in combination with MAP_READ_BIT.
            MAP_INVALIDATE_BUFFER_BIT = GL_MAP_INVALIDATE_BUFFER_BIT,

            /// @brief Indicates that one or more discrete subranges
            /// of the mapping may be modified. When this flag is set, modifications to
            /// each subrange must be explicitly flushed by calling FlushMappedBuffer-
            /// Range. No GL error is set if a subrange of the mapping is modified and
            /// not flushed, but data within the corresponding subrange of the buffer are un-
            /// defined. This flag may only be used in conjunction with MAP_WRITE_BIT.
            /// When this option is selected, flushing is strictly limited to regions that are
            /// explicitly indicated with calls to FlushMappedBufferRange prior to un-
            /// map; if this option is not selected UnmapBuffer will automatically flush the
            /// entire mapped range when called.
            MAP_FLUSH_EXPLICIT_BIT = GL_MAP_FLUSH_EXPLICIT_BIT, 

            /// @brief Indicates that the GL should not attempt
            /// to synchronize pending operations on the buffer prior to returning from
            /// Map*BufferRange. No GL error is generated if pending operations which
            /// source or modify the buffer overlap the mapped region, but the result of such
            /// previous and any subsequent operations is undefined.
            MAP_UNSYNCHRONIZED_BIT = GL_MAP_UNSYNCHRONIZED_BIT, 
        };
    };

    namespace texture
    {  
        enum texture_target_t : GLenum
        {
            TEXTURE_1D =                     GL_TEXTURE_1D, 
            TEXTURE_2D =                     GL_TEXTURE_2D, 
            TEXTURE_3D =                     GL_TEXTURE_3D, 
            TEXTURE_1D_ARRAY =               GL_TEXTURE_1D_ARRAY, 
            TEXTURE_2D_ARRAY =               GL_TEXTURE_2D_ARRAY, 
            TEXTURE_2D_MULTISAMPLE =         GL_TEXTURE_2D_MULTISAMPLE,
            TEXTURE_2D_MULTISAMPLE_ARRAY =   GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
            TEXTURE_CUBE_MAP =               GL_TEXTURE_CUBE_MAP, 
            TEXTURE_CUBE_MAP_ARRAY =         GL_TEXTURE_CUBE_MAP_ARRAY, 
            TEXTURE_BUFFER =                 GL_TEXTURE_BUFFER, 
            TEXTURE_RECTANGLE =              GL_TEXTURE_RECTANGLE
        };
    };    

    namespace blend
    {
        /// @brief as source specifies how the red, green, blue, and alpha source blending factors are computed. 
        /// The initial value is GL_ONE.
        /// as destination factor specifies how the red, green, blue, and alpha destination blending factors are computed. 
        /// The initial value is GL_ZERO.
        enum factor_t : GLenum 
        {
            //	RGB Factor (0, 0, 0) Alpha Factor 0
            ZERO = GL_ZERO,
            
            //	RGB Factor (1, 1, 1)	Alpha Factor 1
            ONE = GL_ONE,
            
            //	RGB Factor (Rs0, Gs0, Bs0)	Alpha Factor As0
            SRC_COLOR = GL_SRC_COLOR,
            
            //	RGB Factor (1, 1, 1) - (Rs0, Gs0, Bs0)	Alpha Factor 1 - As0
            ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
            
            //	RGB Factor (Rd, Gd, Bd)	Alpha Factor Ad
            DST_COLOR = GL_DST_COLOR,
            
            //	RGB Factor (1, 1, 1) - (Rd, Gd, Bd)	Alpha Factor 1 - Ad
            ONE_MINUS_DST_COLOR = GL_ONE_MINUS_DST_COLOR,
            
            //	RGB Factor (As0, As0, As0)	Alpha Factor As0
            SRC_ALPHA = GL_SRC_ALPHA,
            
            //	RGB Factor (1, 1, 1) - (As0, As0, As0)	Alpha Factor 1 - As0
            ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA,
            
            //	RGB Factor (Ad, Ad, Ad)	Alpha Factor Ad
            DST_ALPHA = GL_DST_ALPHA,
            
            //	RGB Factor (1, 1, 1) - (Ad, Ad, Ad)	Alpha Factor Ad
            ONE_MINUS_DST_ALPHA = GL_ONE_MINUS_DST_ALPHA,
            
            //	RGB Factor (Rc, Gc, Bc)	Alpha Factor Ac
            CONSTANT_COLOR = GL_CONSTANT_COLOR,
            
            //	RGB Factor (1, 1, 1) - (Rc, Gc, Bc)	Alpha Factor 1 - Ac
            ONE_MINUS_CONSTANT_COLOR = GL_ONE_MINUS_CONSTANT_COLOR,
            
            //	RGB Factor (Ac, Ac, Ac)	Alpha Factor Ac
            CONSTANT_ALPHA = GL_CONSTANT_ALPHA,
            
            //	RGB Factor (1, 1, 1) - (Ac, Ac, Ac)	Alpha Factor 1 - Ac
            ONE_MINUS_CONSTANT_ALPHA = GL_ONE_MINUS_CONSTANT_ALPHA,
            
            //	RGB Factor (i, i, i)	Alpha Factor 1
            SRC_ALPHA_SATURATE = GL_SRC_ALPHA_SATURATE,
            
            //	RGB Factor (Rs1, Gs1, Bs1)	Alpha Factor As1
            SRC1_COLOR = GL_SRC1_COLOR,
            
            //	RGB Factor (1, 1, 1) - (Rs1, Gs1, Bs1)	Alpha Factor 1 - As1
            // ONE_MINUS_SRC_COLOR = GL_ONE_MINUS_SRC_COLOR,
            
            //	RGB Factor (As1, As1, As1)	Alpha Factor As1
            SRC1_ALPHA = GL_SRC1_ALPHA,
            
            //	RGB Factor (1, 1, 1) - (As1, As1, As1)	Alpha Factor 1 - As1
            // ONE_MINUS_SRC_ALPHA = GL_ONE_MINUS_SRC_ALPHA
        };

        enum equation_t : GLenum
        {
            /// @brief The source and destination colors are added to each other. 
            /// O = sS + dD. 
            /// The The s and d are blending parameters that are multiplied into each of S and D before the addition.
            FUNC_ADD = GL_FUNC_ADD, 
            
            /// @brief Subtracts the destination from the source. 
            /// O = sS - dD.
            /// The source and dest are multiplied by blending parameters.
            FUNC_SUBTRACT = GL_FUNC_SUBTRACT, 
            
            /// @brief Subtracts the source from the destination.
            /// O = dD - sS. 
            /// The source and dest are multiplied by blending parameters.
            FUNC_REVERSE_SUBTRACT = GL_FUNC_REVERSE_SUBTRACT, 
            
            /// @brief The output color is the component-wise minimum value of the source and dest colors. 
            /// So performing GL_MIN in the RGB equation means that Or = min(Sr, Dr), Og = min(Sg, Dg), and so forth. 
            /// The parameters s and d are ignored for this equation.
            MIN = GL_MIN, 
            
            /// @brief The output color is the component-wise maximum value of the source and dest colors. 
            /// The parameters s and d are ignored for this equation.
            MAX = GL_MAX, 
        };
    };

    namespace logicalOperation
    {
        /// @brief specify a logical pixel operation for rendering ( glLogicOp )
        /// The component value for the fragment color is called S; the component value from the framebuffer image is called D. 
        /// "&" is a bitwise and, "|" is a bitwise or, "^" is the bitwise xor, and ~ is the bitwise negation.
        enum operation_t : GLenum
        {
            /// @brief Resulting Operation: 0
            CLEAR           = GL_CLEAR,
            
            /// @brief Resulting Operation: 1
            SET             = GL_SET,
            
            /// @brief Resulting Operation: S
            COPY            = GL_COPY,

            /// @brief Resulting Operation: ~S
            COPY_INVERTED   = GL_COPY_INVERTED,
            
            /// @brief Resulting Operation: D
            NOOP            = GL_NOOP,
            
            /// @brief Resulting Operation: ~D
            INVERT          = GL_INVERT,

            /// @brief Resulting Operation: S & D
            AND             = GL_AND, 
            
            /// @brief Resulting Operation: ~(S & D)
            NAND            = GL_NAND,
            
            /// @brief Resulting Operation: S | D
            OR              = GL_OR,
            
            /// @brief Resulting Operation: ~(S | D)
            NOR             = GL_NOR,
            
            /// @brief Resulting Operation: S ^ D
            XOR             = GL_XOR,
            
            /// @brief Resulting Operation: ~(S ^ D)
            EQUIV           = GL_EQUIV,
            
            /// @brief Resulting Operation: S & ~D
            AND_REVERSE     = GL_AND_REVERSE,
            
            /// @brief Resulting Operation: ~S & D
            AND_INVERTED    = GL_AND_INVERTED, 
            
            /// @brief Resulting Operation: S | ~D
            OR_REVERSE      = GL_OR_REVERSE,
            
            /// @brief Resulting Operation: ~S | D
            OR_INVERTED     = GL_OR_INVERTED
        };
    };

    /// @brief used to compare each incoming pixel depth value with the depth value present in the depth/stencil buffer.
    enum compare_t : GLenum
    {
        /// @brief depth Never passes, Always fails.
        NEVER = GL_NEVER,   
        
        /// @brief Passes if the incoming depth value is less than the stored depth value.
        LESS = GL_LESS,
        
        /// @brief Passes if the incoming depth value is equal to the stored depth value.
        EQUAL = GL_EQUAL,
        
        /// @brief Passes if the incoming depth value is less than or equal to the stored depth value.
        LEQUAL = GL_LEQUAL,
        
        /// @brief Passes if the incoming depth value is greater than the stored depth/stencil value.
        GREATER = GL_GREATER,
        
        /// @brief Passes if the incoming depth value is not equal to the stored depth/stencil value.
        NOTEQUAL = GL_NOTEQUAL,
        
        /// @brief Passes if the incoming depth value is greater than or equal to the stored depth/stencil value.
        GEQUAL = GL_GEQUAL,
        
        /// @brief Always passes.
        ALWAYS = GL_ALWAYS
    };

    /// @brief stencil test actions
    enum operation_t : GLenum
    {
        /// @brief Keeps the current value.
        KEEP        = GL_KEEP,      

        /// @brief Sets the stencil buffer value to 0.
        //ZERO        = GL_ZERO,
        
        /// @brief Sets the stencil buffer value to ref, as specified by
        REPLACE     = GL_REPLACE,   
        
        /// @brief Increments the current stencil buffer value. Clamps to the maximum representable unsigned value.
        INCR        = GL_INCR,      
        
        /// @brief Increments the current stencil buffer value. Wraps stencil buffer value to zero when incrementing the maximum
        /// representable unsigned value.
        INCR_WRAP   = GL_INCR_WRAP, 
        
        /// @brief Decrements the current stencil buffer value. Clamps to 0.
        DECR        = GL_DECR,      
        
        /// @brief Decrements the current stencil buffer value. Wraps stencil buffer value to the maximum representable 
        /// unsigned value when decrementing a stencil buffer value of zero.
        DECR_WRAP   = GL_DECR_WRAP, 
        
        /// @brief Bitwise inverts the current stencil buffer value.
        INVERT      = GL_INVERT     
    };
};

#endif  //__