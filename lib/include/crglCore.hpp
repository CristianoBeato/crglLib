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
#ifndef __CRGL_CORE_HPP__
#define __CRGL_CORE_HPP__

#include <GL/glcorearb.h>

// state cofiguration
extern PFNGLGETINTEGERVPROC                             glGetIntegerv;
extern PFNGLGETINTEGER64VPROC                           glGetInteger64v;
extern PFNGLISENABLEDPROC                               glIsEnabled;
extern PFNGLDISABLEPROC                                 glDisable;
extern PFNGLENABLEPROC                                  glEnable;
extern PFNGLFINISHPROC                                  glFinish;
extern PFNGLFLUSHPROC                                   glFlush;

extern PFNGLGETERRORPROC                                glGetError;
extern PFNGLGETSTRINGPROC                               glGetString;
extern PFNGLGETBOOLEANVPROC                             glGetBooleanv;
extern PFNGLHINTPROC                                    glHint;

extern PFNGLVIEWPORTPROC                                glViewport;
extern PFNGLSCISSORPROC                                 glScissor;

// clear buffer 
extern PFNGLCLEARPROC                                   glClear;

// color buffer 
extern PFNGLCLEARCOLORPROC                              glClearColor;
extern PFNGLCOLORMASKPROC                               glColorMask;
extern PFNGLBLENDFUNCSEPARATEPROC                       glBlendFuncSeparate;
extern PFNGLLOGICOPPROC                                 glLogicOp;

// depth buffer
extern PFNGLDEPTHRANGEPROC                              glDepthRange;
extern PFNGLCLEARDEPTHPROC                              glClearDepth;
extern PFNGLDEPTHMASKPROC                               glDepthMask;
extern PFNGLDEPTHFUNCPROC                               glDepthFunc;

// stencil buffer
extern PFNGLCLEARSTENCILPROC                            glClearStencil;
extern PFNGLSTENCILMASKPROC                             glStencilMask;
extern PFNGLSTENCILFUNCPROC                             glStencilFunc;
extern PFNGLSTENCILOPPROC                               glStencilOp;

// polygon 
extern PFNGLLINEWIDTHPROC                               glLineWidth;
extern PFNGLPOINTSIZEPROC                               glPointSize;
extern PFNGLPOLYGONMODEPROC                             glPolygonMode;
extern PFNGLCULLFACEPROC                                glCullFace;

// draw
extern PFNGLDRAWARRAYSPROC                              glDrawArrays;
extern PFNGLDRAWELEMENTSPROC                            glDrawElements;
extern PFNGLMULTIDRAWARRAYSPROC                         glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC                       glMultiDrawElements;
extern PFNGLDRAWELEMENTSBASEVERTEXPROC                  glDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC             glDrawRangeElementsBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC             glMultiDrawElementsBaseVertex;

// GL_ARB_draw_instanced
extern PFNGLDRAWARRAYSINSTANCEDPROC                     glDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC                   glDrawElementsInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC         glDrawElementsInstancedBaseVertex;
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC         glDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC       glDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC    glDrawElementsInstancedBaseVertexBaseInstance;

// GL_ARB_draw_indirect
extern PFNGLDRAWARRAYSINDIRECTPROC                      glDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC                    glDrawElementsIndirect;

// GL_ARB_multi_draw_indirect
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC                 glMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC               glMultiDrawElementsIndirect;
extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC            glMultiDrawArraysIndirectCount;
extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC          glMultiDrawElementsIndirectCount;

// GL_ARB_transform_feedback2
extern PFNGLDRAWTRANSFORMFEEDBACKPROC                   glDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC             glDrawTransformFeedbackStream;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC          glDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC    glDrawTransformFeedbackStreamInstanced;

// GL_KHR_debug
extern PFNGLDEBUGMESSAGECONTROLPROC                     glDebugMessageControl;
extern PFNGLDEBUGMESSAGECALLBACKPROC                    glDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC                      glGetDebugMessageLog;
extern PFNGLDEBUGMESSAGEINSERTPROC                      glDebugMessageInsert;
extern PFNGLOBJECTLABELPROC                             glObjectLabel;
extern PFNGLGETOBJECTLABELPROC                          glGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC                          glObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC                       glGetObjectPtrLabel;

// vertex array 
extern PFNGLISVERTEXARRAYPROC                           glIsVertexArray;
extern PFNGLCREATEVERTEXARRAYSPROC                      glCreateVertexArrays;
extern PFNGLDELETEVERTEXARRAYSPROC                      glDeleteVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC                         glBindVertexArray;             
extern PFNGLENABLEVERTEXARRAYATTRIBPROC                 glEnableVertexArrayAttrib;
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC                glDisableVertexArrayAttrib;
extern PFNGLVERTEXARRAYATTRIBBINDINGPROC                glVertexArrayAttribBinding;
extern PFNGLVERTEXARRAYATTRIBFORMATPROC                 glVertexArrayAttribFormat;
extern PFNGLVERTEXARRAYELEMENTBUFFERPROC                glVertexArrayElementBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERPROC                 glVertexArrayVertexBuffer; 

// GL_ARB_multi_bind
extern PFNGLVERTEXARRAYVERTEXBUFFERSPROC                glVertexArrayVertexBuffers; 

// shader 
extern PFNGLCREATESHADERPROC                            glCreateShader;
extern PFNGLDELETESHADERPROC                            glDeleteShader;
extern PFNGLSHADERSOURCEPROC                            glShaderSource;
extern PFNGLSHADERBINARYPROC                            glShaderBinary;
extern PFNGLCOMPILESHADERPROC                           glCompileShader;
extern PFNGLSPECIALIZESHADERPROC                        glSpecializeShader;
extern PFNGLGETSHADERINFOLOGPROC                        glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC                             glGetShaderiv;

// program
extern PFNGLCREATEPROGRAMPROC                           glCreateProgram;
extern PFNGLDELETEPROGRAMPROC                           glDeleteProgram;
extern PFNGLISPROGRAMPROC                               glIsProgram;
extern PFNGLPROGRAMPARAMETERIPROC                       glProgramParameteri;
extern PFNGLATTACHSHADERPROC                            glAttachShader;
extern PFNGLDETACHSHADERPROC                            glDetachShader;
extern PFNGLLINKPROGRAMPROC                             glLinkProgram;
extern PFNGLVALIDATEPROGRAMPROC                         glValidateProgram;
extern PFNGLGETPROGRAMIVPROC                            glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC                       glGetProgramInfoLog;
extern PFNGLUSEPROGRAMPROC                              glUseProgram;
extern PFNGLUNIFORM1IPROC                               glUniform1i;
extern PFNGLUNIFORM1IVPROC                              glUniform1iv;
extern PFNGLUNIFORM1UIVPROC                             glUniform1uiv;

// pipelines
extern PFNGLBINDPROGRAMPIPELINEPROC                     glBindProgramPipeline;
extern PFNGLCREATEPROGRAMPIPELINESPROC                  glCreateProgramPipelines;
extern PFNGLDELETEPROGRAMPIPELINESPROC                  glDeleteProgramPipelines;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC                 glValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC                    glGetProgramPipelineiv;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC               glGetProgramPipelineInfoLog;
extern PFNGLUSEPROGRAMSTAGESPROC                        glUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC                     glActiveShaderProgram;
extern PFNGLPROGRAMUNIFORM1IPROC                        glProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC                       glProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1UIVPROC                      glProgramUniform1uiv;

// buffer
extern PFNGLISBUFFERPROC                                glIsBuffer;
extern PFNGLBINDBUFFERPROC                              glBindBuffer;
extern PFNGLBINDBUFFERBASEPROC                          glBindBufferBase;
extern PFNGLBINDBUFFERRANGEPROC                         glBindBufferRange;
extern PFNGLCREATEBUFFERSPROC                           glCreateBuffers;
extern PFNGLDELETEBUFFERSPROC                           glDeleteBuffers;
extern PFNGLNAMEDBUFFERSTORAGEPROC                      glNamedBufferStorage;
extern PFNGLMAPNAMEDBUFFERRANGEPROC                     glMapNamedBufferRange;
extern PFNGLUNMAPNAMEDBUFFERPROC                        glUnmapNamedBuffer;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC             glFlushMappedNamedBufferRange;
extern PFNGLNAMEDBUFFERSUBDATAPROC                      glNamedBufferSubData;
extern PFNGLGETNAMEDBUFFERSUBDATAPROC                   glGetNamedBufferSubData;
extern PFNGLCOPYNAMEDBUFFERSUBDATAPROC                  glCopyNamedBufferSubData;

// GL_ARB_multi_bind
extern PFNGLBINDBUFFERSRANGEPROC                        glBindBuffersRange;
extern PFNGLBINDBUFFERSBASEPROC                         glBindBuffersBase;

// Image
extern PFNGLBINDTEXTUREPROC						        glBindTexture;
extern PFNGLBINDTEXTUREUNITPROC                         glBindTextureUnit;
extern PFNGLBINDTEXTURESPROC					        glBindTextures;
extern PFNGLCREATETEXTURESPROC					        glCreateTextures;
extern PFNGLDELETETEXTURESPROC					        glDeleteTextures;
extern PFNGLISTEXTUREPROC                               glIsTexture;
extern PFNGLTEXTURESTORAGE1DPROC				        glTextureStorage1D;
extern PFNGLTEXTURESTORAGE2DPROC				        glTextureStorage2D;
extern PFNGLTEXTURESTORAGE3DPROC				        glTextureStorage3D;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC		        glTextureStorage2DMultisample;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC		        glTextureStorage3DMultisample;
extern PFNGLTEXTURESUBIMAGE1DPROC				        glTextureSubImage1D;
extern PFNGLTEXTURESUBIMAGE2DPROC				        glTextureSubImage2D;
extern PFNGLTEXTURESUBIMAGE3DPROC				        glTextureSubImage3D;
extern PFNGLCOPYTEXTURESUBIMAGE1DPROC                   glCopyTextureSubImage1D;
extern PFNGLCOPYTEXTURESUBIMAGE2DPROC                   glCopyTextureSubImage2D;
extern PFNGLCOPYTEXTURESUBIMAGE3DPROC                   glCopyTextureSubImage3D;
extern PFNGLTEXTUREPARAMETERIVPROC				        glTextureParameteriv;
extern PFNGLTEXTUREPARAMETERFVPROC				        glTextureParameterfv;
extern PFNGLGETTEXTUREPARAMETERIVPROC                   glGetTextureParameteriv;
extern PFNGLGETTEXTUREPARAMETERFVPROC                   glGetTextureParameterfv;
extern PFNGLGETTEXTUREIMAGEPROC					        glGetTextureImage;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC               glGetCompressedTextureImage;
extern PFNGLINVALIDATETEXIMAGEPROC                      glInvalidateTexImage;

// GL_ARB_invalidate_subdata
extern PFNGLINVALIDATETEXSUBIMAGEPROC                   glInvalidateTexSubImage;

// GL_ARB_clear_texture
extern PFNGLCLEARTEXIMAGEPROC                           glClearTexImage;
extern PFNGLCLEARTEXSUBIMAGEPROC                        glClearTexSubImage;

// GL_ARB_get_texture_sub_image
extern PFNGLGETTEXTURESUBIMAGEPROC                      glGetTextureSubImage;
extern PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC            glGetCompressedTextureSubImage;

// GL_ARB_copy_image
extern PFNGLCOPYIMAGESUBDATAPROC                        glCopyImageSubData;

// GL_ARB_texture_view
extern PFNGLTEXTUREVIEWPROC                             glTextureView;

// sampler
extern PFNGLCREATESAMPLERSPROC                          glCreateSamplers;
extern PFNGLDELETESAMPLERSPROC                          glDeleteSamplers;
extern PFNGLBINDSAMPLERPROC                             glBindSampler;
extern PFNGLBINDSAMPLERSPROC                            glBindSamplers;
extern PFNGLISSAMPLERPROC                               glIsSampler;
extern PFNGLSAMPLERPARAMETERIPROC                       glSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC                      glSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC                       glSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC                      glSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC                     glSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC                    glSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC                   glGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC                  glGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC                   glGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC                 glGetSamplerParameterIuiv;

// texture handler
extern PFNGLGETTEXTUREHANDLEARBPROC				        glGetTextureHandleARB;
extern PFNGLGETTEXTURESAMPLERHANDLEARBPROC		        glGetTextureSamplerHandleARB;
extern PFNGLMAKETEXTUREHANDLERESIDENTARBPROC	        glMakeTextureHandleResidentARB;
extern PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC	        glMakeTextureHandleNonResidentARB;
extern PFNGLMAKEIMAGEHANDLERESIDENTARBPROC 		        glMakeImageHandleResidentARB;
extern PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC 	        glMakeImageHandleNonResidentARB;
extern PFNGLUNIFORMHANDLEUI64ARBPROC 			        glUniformHandleui64ARB;
extern PFNGLUNIFORMHANDLEUI64VARBPROC 			        glUniformHandleui64vARB;
extern PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC 	        glProgramUniformHandleui64ARB;
extern PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC 	        glProgramUniformHandleui64vARB;
extern PFNGLISTEXTUREHANDLERESIDENTARBPROC		        glIsTextureHandleResidentARB;
extern PFNGLISIMAGEHANDLERESIDENTARBPROC		        glIsImageHandleResidentARB;

// GL_ARB_framebuffer_object
extern PFNGLBINDFRAMEBUFFERPROC					        glBindFramebuffer;
extern PFNGLDELETEFRAMEBUFFERSPROC				        glDeleteFramebuffers;
extern PFNGLISFRAMEBUFFERPROC                           glIsFramebuffer;
extern PFNGLCREATEFRAMEBUFFERSPROC				        glCreateFramebuffers;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC			        glNamedFramebufferTexture;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC            glNamedFramebufferTextureLayer;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC	        glNamedFramebufferRenderbuffer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC		        glNamedFramebufferDrawBuffer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC		        glNamedFramebufferDrawBuffers;
extern PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC		        glNamedFramebufferReadBuffer;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC			        glFramebufferRenderbuffer;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC			        glFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC			        glFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC			        glFramebufferTexture3D;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC			        glFramebufferTextureLayer;
extern PFNGLFRAMEBUFFERTEXTUREPROC				        glFramebufferTexture;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC		        glCheckNamedFramebufferStatus;
extern PFNGLBLITNAMEDFRAMEBUFFERPROC                    glBlitNamedFramebuffer;

// renderbuffers 
extern PFNGLISRENDERBUFFERPROC                          glIsRenderbuffer;
extern PFNGLCREATERENDERBUFFERSPROC                     glCreateRenderbuffers;
extern PFNGLDELETERENDERBUFFERSPROC                     glDeleteRenderbuffers;
extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC                glNamedRenderbufferStorage;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC     glNamedRenderbufferStorageMultisample;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC         glGetNamedRenderbufferParameteriv;

// GL_ARB_sync
extern PFNGLISSYNCPROC                                  glIsSync;
extern PFNGLFENCESYNCPROC                               glFenceSync;
extern PFNGLCLIENTWAITSYNCPROC                          glClientWaitSync;
extern PFNGLDELETESYNCPROC                              glDeleteSync;
extern PFNGLWAITSYNCPROC                                glWaitSync;
extern PFNGLGETSYNCIVPROC                               glGetSynciv;

typedef struct glCoreBuffer_t                           glCoreBuffer_t;
typedef struct glCoreShader_t                           glCoreShader_t;
typedef struct glCoreProgram_t                          glCoreProgram_t;
typedef struct glCorePipeline_t                         glCorePipeline_t;
typedef struct glCoreVertexArray_t                      glCoreVertexArray_t;
typedef struct glCoreImage_t                            glCoreImage_t;
typedef struct glCoreSampler_t                          glCoreSampler_t;
typedef struct glCoreFramebuffer_t                      glCoreFramebuffer_t;
typedef struct glCoreRenderbuffer_t                     glCoreRenderbuffer_t;

#include "crglFence.hpp"
#include "crglBuffer.hpp"
#include "crglShaders.hpp"
#include "crglVertexArray.hpp"
#include "crglFormat.hpp"
#include "crglSampler.hpp"
#include "crglImage.hpp"
#include "crglFrameBuffer.hpp"
#include "crglContext.hpp"

#endif //!__CRGL_CORE_HPP__