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
#include "crglCore.hpp"

//
PFNGLGETINTEGERVPROC                            glGetIntegerv = nullptr;
PFNGLGETINTEGER64VPROC                          glGetInteger64v = nullptr;
PFNGLISENABLEDPROC                              glIsEnabled = nullptr;
PFNGLDISABLEPROC                                glDisable = nullptr;
PFNGLENABLEPROC                                 glEnable = nullptr;
PFNGLFINISHPROC                                 glFinish = nullptr;
PFNGLFLUSHPROC                                  glFlush = nullptr;

PFNGLGETERRORPROC                               glGetError = nullptr;
PFNGLGETSTRINGPROC                              glGetString = nullptr;
PFNGLGETBOOLEANVPROC                            glGetBooleanv = nullptr;
PFNGLHINTPROC                                   glHint = nullptr;

PFNGLVIEWPORTPROC                               glViewport = nullptr;
PFNGLSCISSORPROC                                glScissor = nullptr;

// clear buffer 
PFNGLCLEARPROC                                  glClear = nullptr;

// color buffer 
PFNGLCLEARCOLORPROC                             glClearColor = nullptr;
PFNGLCOLORMASKPROC                              glColorMask = nullptr;
PFNGLBLENDFUNCSEPARATEPROC                      glBlendFuncSeparate = nullptr;
PFNGLLOGICOPPROC                                glLogicOp = nullptr;

// depth buffer
PFNGLDEPTHRANGEPROC                             glDepthRange = nullptr;
PFNGLCLEARDEPTHPROC                             glClearDepth = nullptr;
PFNGLDEPTHMASKPROC                              glDepthMask = nullptr;
PFNGLDEPTHFUNCPROC                              glDepthFunc = nullptr;

// stencil buffer
PFNGLCLEARSTENCILPROC                           glClearStencil = nullptr;
PFNGLSTENCILMASKPROC                            glStencilMask = nullptr;
PFNGLSTENCILFUNCPROC                            glStencilFunc = nullptr;
PFNGLSTENCILOPPROC                              glStencilOp = nullptr;

// polygon 
PFNGLLINEWIDTHPROC                              glLineWidth = nullptr;
PFNGLPOINTSIZEPROC                              glPointSize = nullptr;
PFNGLPOLYGONMODEPROC                            glPolygonMode = nullptr;
PFNGLCULLFACEPROC                               glCullFace = nullptr;

// draw
PFNGLDRAWARRAYSPROC                             glDrawArrays = nullptr;
PFNGLDRAWELEMENTSPROC                           glDrawElements = nullptr;
PFNGLMULTIDRAWARRAYSPROC                        glMultiDrawArrays = nullptr;
PFNGLMULTIDRAWELEMENTSPROC                      glMultiDrawElements = nullptr;
PFNGLDRAWELEMENTSBASEVERTEXPROC                 glDrawElementsBaseVertex = nullptr;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC            glDrawRangeElementsBaseVertex = nullptr;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC            glMultiDrawElementsBaseVertex = nullptr;

// GL_ARB_draw_instanced
PFNGLDRAWARRAYSINSTANCEDPROC                    glDrawArraysInstanced = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC                  glDrawElementsInstanced = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC        glDrawElementsInstancedBaseVertex = nullptr;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC        glDrawArraysInstancedBaseInstance = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC      glDrawElementsInstancedBaseInstance = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC    glDrawElementsInstancedBaseVertexBaseInstance = nullptr;

// GL_ARB_draw_indirect
PFNGLDRAWARRAYSINDIRECTPROC                     glDrawArraysIndirect = nullptr;
PFNGLDRAWELEMENTSINDIRECTPROC                   glDrawElementsIndirect = nullptr;

// GL_ARB_multi_draw_indirect
PFNGLMULTIDRAWARRAYSINDIRECTPROC                glMultiDrawArraysIndirect = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC              glMultiDrawElementsIndirect = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC           glMultiDrawArraysIndirectCount = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC         glMultiDrawElementsIndirectCount = nullptr;

// GL_ARB_transform_feedback2
PFNGLDRAWTRANSFORMFEEDBACKPROC                  glDrawTransformFeedback = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC            glDrawTransformFeedbackStream = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC         glDrawTransformFeedbackInstanced = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC   glDrawTransformFeedbackStreamInstanced = nullptr;

// GL_ARB_debug_output // GL_KHR_debug  
PFNGLDEBUGMESSAGECONTROLPROC                    glDebugMessageControl = nullptr;
PFNGLDEBUGMESSAGECALLBACKPROC                   glDebugMessageCallback = nullptr;
PFNGLGETDEBUGMESSAGELOGPROC                     glGetDebugMessageLog = nullptr;
PFNGLDEBUGMESSAGEINSERTPROC                     glDebugMessageInsert = nullptr;
PFNGLOBJECTLABELPROC                            glObjectLabel = nullptr;
PFNGLGETOBJECTLABELPROC                         glGetObjectLabel = nullptr;
PFNGLOBJECTPTRLABELPROC                         glObjectPtrLabel = nullptr;
PFNGLGETOBJECTPTRLABELPROC                      glGetObjectPtrLabel = nullptr;

// vertex array 
PFNGLISVERTEXARRAYPROC                          glIsVertexArray = nullptr;
PFNGLCREATEVERTEXARRAYSPROC                     glCreateVertexArrays = nullptr;
PFNGLDELETEVERTEXARRAYSPROC                     glDeleteVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC                        glBindVertexArray = nullptr;             
PFNGLENABLEVERTEXARRAYATTRIBPROC                glEnableVertexArrayAttrib = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBPROC               glDisableVertexArrayAttrib = nullptr;
PFNGLVERTEXARRAYATTRIBBINDINGPROC               glVertexArrayAttribBinding = nullptr;
PFNGLVERTEXARRAYATTRIBFORMATPROC                glVertexArrayAttribFormat = nullptr;
PFNGLVERTEXARRAYELEMENTBUFFERPROC               glVertexArrayElementBuffer = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERPROC                glVertexArrayVertexBuffer = nullptr; 

// GL_ARB_multi_bind
PFNGLVERTEXARRAYVERTEXBUFFERSPROC               glVertexArrayVertexBuffers = nullptr; 

// shader 
PFNGLCREATESHADERPROC                           glCreateShader = nullptr;
PFNGLDELETESHADERPROC                           glDeleteShader = nullptr;
PFNGLSHADERSOURCEPROC                           glShaderSource = nullptr;
PFNGLSHADERBINARYPROC                           glShaderBinary = nullptr;
PFNGLCOMPILESHADERPROC                          glCompileShader = nullptr;
PFNGLSPECIALIZESHADERPROC                       glSpecializeShader = nullptr;
PFNGLGETSHADERINFOLOGPROC                       glGetShaderInfoLog = nullptr;
PFNGLGETSHADERIVPROC                            glGetShaderiv = nullptr;

// program
PFNGLCREATEPROGRAMPROC                          glCreateProgram = nullptr;
PFNGLDELETEPROGRAMPROC                          glDeleteProgram = nullptr;
PFNGLISPROGRAMPROC                              glIsProgram = nullptr;
PFNGLPROGRAMPARAMETERIPROC                      glProgramParameteri = nullptr;
PFNGLATTACHSHADERPROC                           glAttachShader = nullptr;
PFNGLDETACHSHADERPROC                           glDetachShader = nullptr;
PFNGLLINKPROGRAMPROC                            glLinkProgram = nullptr;
PFNGLVALIDATEPROGRAMPROC                        glValidateProgram = nullptr;
PFNGLGETPROGRAMIVPROC                           glGetProgramiv = nullptr;
PFNGLGETPROGRAMINFOLOGPROC                      glGetProgramInfoLog = nullptr;
PFNGLUSEPROGRAMPROC                             glUseProgram = nullptr;
PFNGLUNIFORM1IPROC                              glUniform1i = nullptr;
PFNGLUNIFORM1IVPROC                             glUniform1iv = nullptr;
PFNGLUNIFORM1UIVPROC                            glUniform1uiv = nullptr;

// pipelines
PFNGLBINDPROGRAMPIPELINEPROC                    glBindProgramPipeline = nullptr;
PFNGLCREATEPROGRAMPIPELINESPROC                 glCreateProgramPipelines = nullptr;
PFNGLDELETEPROGRAMPIPELINESPROC                 glDeleteProgramPipelines = nullptr;
PFNGLVALIDATEPROGRAMPIPELINEPROC                glValidateProgramPipeline = nullptr;
PFNGLGETPROGRAMPIPELINEIVPROC                   glGetProgramPipelineiv = nullptr;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC              glGetProgramPipelineInfoLog = nullptr;
PFNGLUSEPROGRAMSTAGESPROC                       glUseProgramStages = nullptr;
PFNGLACTIVESHADERPROGRAMPROC                    glActiveShaderProgram = nullptr;
PFNGLPROGRAMUNIFORM1IPROC                       glProgramUniform1i = nullptr;
PFNGLPROGRAMUNIFORM1IVPROC                      glProgramUniform1iv = nullptr;
PFNGLPROGRAMUNIFORM1UIVPROC                     glProgramUniform1uiv = nullptr;

// buffer
PFNGLISBUFFERPROC                               glIsBuffer = nullptr;
PFNGLBINDBUFFERPROC                             glBindBuffer = nullptr;
PFNGLBINDBUFFERBASEPROC                         glBindBufferBase = nullptr;
PFNGLBINDBUFFERRANGEPROC                        glBindBufferRange = nullptr;
PFNGLCREATEBUFFERSPROC                          glCreateBuffers = nullptr;
PFNGLDELETEBUFFERSPROC                          glDeleteBuffers = nullptr;
PFNGLNAMEDBUFFERSTORAGEPROC                     glNamedBufferStorage = nullptr;
PFNGLMAPNAMEDBUFFERRANGEPROC                    glMapNamedBufferRange = nullptr;
PFNGLUNMAPNAMEDBUFFERPROC                       glUnmapNamedBuffer = nullptr;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC            glFlushMappedNamedBufferRange = nullptr;
PFNGLNAMEDBUFFERSUBDATAPROC                     glNamedBufferSubData = nullptr;
PFNGLGETNAMEDBUFFERSUBDATAPROC                  glGetNamedBufferSubData = nullptr;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC                 glCopyNamedBufferSubData = nullptr;

// GL_ARB_multi_bind
PFNGLBINDBUFFERSRANGEPROC                       glBindBuffersRange = nullptr;
PFNGLBINDBUFFERSBASEPROC                        glBindBuffersBase = nullptr;

// Image
PFNGLBINDTEXTUREPROC                            glBindTexture = nullptr;
PFNGLBINDTEXTURESPROC					        glBindTextures = nullptr;
PFNGLBINDTEXTUREUNITPROC                        glBindTextureUnit = nullptr;
PFNGLCREATETEXTURESPROC					        glCreateTextures = nullptr;
PFNGLDELETETEXTURESPROC					        glDeleteTextures = nullptr;
PFNGLISTEXTUREPROC                              glIsTexture = nullptr;
PFNGLTEXTURESTORAGE1DPROC				        glTextureStorage1D = nullptr;
PFNGLTEXTURESTORAGE2DPROC				        glTextureStorage2D = nullptr;
PFNGLTEXTURESTORAGE3DPROC				        glTextureStorage3D = nullptr;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC            glTextureStorage2DMultisample = nullptr;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC            glTextureStorage3DMultisample = nullptr;
PFNGLTEXTURESUBIMAGE1DPROC				        glTextureSubImage1D = nullptr;
PFNGLTEXTURESUBIMAGE2DPROC				        glTextureSubImage2D = nullptr;
PFNGLTEXTURESUBIMAGE3DPROC				        glTextureSubImage3D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE1DPROC                  glCopyTextureSubImage1D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE2DPROC                  glCopyTextureSubImage2D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE3DPROC                  glCopyTextureSubImage3D = nullptr;
PFNGLTEXTUREPARAMETERIVPROC				        glTextureParameteriv = nullptr;
PFNGLTEXTUREPARAMETERFVPROC				        glTextureParameterfv = nullptr;
PFNGLGETTEXTUREPARAMETERIVPROC                  glGetTextureParameteriv = nullptr;
PFNGLGETTEXTUREPARAMETERFVPROC                  glGetTextureParameterfv = nullptr;
PFNGLGETTEXTURELEVELPARAMETERFVPROC             glGetTextureLevelParameterfv = nullptr;
PFNGLGETTEXTURELEVELPARAMETERIVPROC             glGetTextureLevelParameteriv = nullptr;
PFNGLGETTEXTUREIMAGEPROC                        glGetTextureImage = nullptr;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC              glGetCompressedTextureImage = nullptr;
PFNGLINVALIDATETEXIMAGEPROC                     glInvalidateTexImage = nullptr;

// GL_ARB_invalidate_subdata
PFNGLINVALIDATETEXSUBIMAGEPROC                  glInvalidateTexSubImage = nullptr;

// GL_ARB_clear_texture
PFNGLCLEARTEXIMAGEPROC                          glClearTexImage = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC                       glClearTexSubImage = nullptr;

// GL_ARB_get_texture_sub_image
PFNGLGETTEXTURESUBIMAGEPROC                     glGetTextureSubImage = nullptr;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC           glGetCompressedTextureSubImage = nullptr;

// GL_ARB_copy_image
PFNGLCOPYIMAGESUBDATAPROC                       glCopyImageSubData = nullptr;

// GL_ARB_texture_view
PFNGLTEXTUREVIEWPROC                            glTextureView = nullptr;

//
PFNGLCREATESAMPLERSPROC                         glCreateSamplers = nullptr;
PFNGLDELETESAMPLERSPROC                         glDeleteSamplers = nullptr;
PFNGLBINDSAMPLERPROC                            glBindSampler = nullptr;
PFNGLBINDSAMPLERSPROC                           glBindSamplers = nullptr;
PFNGLISSAMPLERPROC                              glIsSampler = nullptr;
PFNGLSAMPLERPARAMETERIPROC                      glSamplerParameteri = nullptr;
PFNGLSAMPLERPARAMETERIVPROC                     glSamplerParameteriv = nullptr;
PFNGLSAMPLERPARAMETERFPROC                      glSamplerParameterf = nullptr;
PFNGLSAMPLERPARAMETERFVPROC                     glSamplerParameterfv = nullptr;
PFNGLSAMPLERPARAMETERIIVPROC                    glSamplerParameterIiv = nullptr;
PFNGLSAMPLERPARAMETERIUIVPROC                   glSamplerParameterIuiv = nullptr;
PFNGLGETSAMPLERPARAMETERIVPROC                  glGetSamplerParameteriv = nullptr;
PFNGLGETSAMPLERPARAMETERIIVPROC                 glGetSamplerParameterIiv = nullptr;
PFNGLGETSAMPLERPARAMETERFVPROC                  glGetSamplerParameterfv = nullptr;
PFNGLGETSAMPLERPARAMETERIUIVPROC                glGetSamplerParameterIuiv = nullptr;

// GL_ARB_bindless_texture
PFNGLGETTEXTUREHANDLEARBPROC				    glGetTextureHandleARB = nullptr;
PFNGLGETTEXTURESAMPLERHANDLEARBPROC		        glGetTextureSamplerHandleARB = nullptr;
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC	        glMakeTextureHandleResidentARB = nullptr;
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC        glMakeTextureHandleNonResidentARB = nullptr;
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC 		    glMakeImageHandleResidentARB = nullptr;
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC 	        glMakeImageHandleNonResidentARB = nullptr;
PFNGLUNIFORMHANDLEUI64ARBPROC 			        glUniformHandleui64ARB = nullptr;
PFNGLUNIFORMHANDLEUI64VARBPROC 			        glUniformHandleui64vARB = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC 	        glProgramUniformHandleui64ARB = nullptr;
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC 	        glProgramUniformHandleui64vARB = nullptr;
PFNGLISTEXTUREHANDLERESIDENTARBPROC		        glIsTextureHandleResidentARB = nullptr;
PFNGLISIMAGEHANDLERESIDENTARBPROC		        glIsImageHandleResidentARB = nullptr;

// GL_ARB_framebuffer_object
PFNGLBINDFRAMEBUFFERPROC				        glBindFramebuffer = nullptr;
PFNGLISFRAMEBUFFERPROC                          glIsFramebuffer = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC				        glDeleteFramebuffers = nullptr;
PFNGLCREATEFRAMEBUFFERSPROC				        glCreateFramebuffers = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC		        glNamedFramebufferTexture = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC           glNamedFramebufferTextureLayer = nullptr;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC	        glNamedFramebufferRenderbuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC		        glNamedFramebufferDrawBuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC	        glNamedFramebufferDrawBuffers = nullptr;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC		        glNamedFramebufferReadBuffer = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC		        glFramebufferRenderbuffer = nullptr;
PFNGLFRAMEBUFFERTEXTURE1DPROC			        glFramebufferTexture1D = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC			        glFramebufferTexture2D = nullptr;
PFNGLFRAMEBUFFERTEXTURE3DPROC			        glFramebufferTexture3D = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERPROC		        glFramebufferTextureLayer = nullptr;
PFNGLFRAMEBUFFERTEXTUREPROC				        glFramebufferTexture = nullptr;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC	        glCheckNamedFramebufferStatus = nullptr;
PFNGLBLITNAMEDFRAMEBUFFERPROC                   glBlitNamedFramebuffer = nullptr;

// rendebuffers 
PFNGLISRENDERBUFFERPROC                         glIsRenderbuffer = nullptr;
PFNGLCREATERENDERBUFFERSPROC                    glCreateRenderbuffers = nullptr;
PFNGLDELETERENDERBUFFERSPROC                    glDeleteRenderbuffers = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC               glNamedRenderbufferStorage = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC    glNamedRenderbufferStorageMultisample = nullptr;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC        glGetNamedRenderbufferParameteriv = nullptr;

//GL_ARB_sync
PFNGLISSYNCPROC                                 glIsSync = nullptr;
PFNGLFENCESYNCPROC                              glFenceSync = nullptr;
PFNGLCLIENTWAITSYNCPROC                         glClientWaitSync = nullptr;
PFNGLDELETESYNCPROC                             glDeleteSync = nullptr;
PFNGLWAITSYNCPROC                               glWaitSync = nullptr;
PFNGLGETSYNCIVPROC                              glGetSynciv = nullptr;

void gl::Context::LoadFunctions( void )
{
    glGetIntegerv = reinterpret_cast<PFNGLGETINTEGERVPROC>( GetFunctionPointer( "glGetIntegerv" ) );
    glGetInteger64v = reinterpret_cast<PFNGLGETINTEGER64VPROC>( GetFunctionPointer( "glGetInteger64v" ) );
    glIsEnabled = reinterpret_cast<PFNGLISENABLEDPROC>( GetFunctionPointer( "glIsEnabled" ) );
    glDisable = reinterpret_cast<PFNGLDISABLEPROC>( GetFunctionPointer( "glDisable" ) );
    glEnable = reinterpret_cast<PFNGLENABLEPROC>( GetFunctionPointer( "glEnable" ) );
    glFinish = reinterpret_cast<PFNGLFINISHPROC>( GetFunctionPointer( "glFinish" ) );
    glFlush = reinterpret_cast<PFNGLFLUSHPROC>( GetFunctionPointer( "glFlush" ) );

    glGetError = reinterpret_cast<PFNGLGETERRORPROC>( GetFunctionPointer( "glGetError" ) );
    glGetString = reinterpret_cast<PFNGLGETSTRINGPROC>( GetFunctionPointer( "glGetString" ) );
    glGetBooleanv = reinterpret_cast<PFNGLGETBOOLEANVPROC>( GetFunctionPointer( "glGetBooleanv" ) );
    glHint = reinterpret_cast<PFNGLHINTPROC>( GetFunctionPointer( "glHint" ) );

    glViewport = reinterpret_cast<PFNGLVIEWPORTPROC>( GetFunctionPointer( "glViewport" ) );
    glScissor = reinterpret_cast<PFNGLSCISSORPROC>( GetFunctionPointer( "glScissor" ) );

    // clear buffers 
    glClear = reinterpret_cast<PFNGLCLEARPROC>( GetFunctionPointer( "glClear" ) );

    // color buffer 
    glClearColor = reinterpret_cast<PFNGLCLEARCOLORPROC>( GetFunctionPointer( "glClearColor" ) );
    glColorMask = reinterpret_cast<PFNGLCOLORMASKPROC>( GetFunctionPointer( "glColorMask" ) );
    glBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>( GetFunctionPointer( "glBlendFuncSeparate" ) );
    glLogicOp = reinterpret_cast<PFNGLLOGICOPPROC>( GetFunctionPointer( "glLogicOp" ) );

    // depth buffer
    glDepthRange = reinterpret_cast<PFNGLDEPTHRANGEPROC>( GetFunctionPointer( "glDepthRange" ) );
    glClearDepth = reinterpret_cast<PFNGLCLEARDEPTHPROC>( GetFunctionPointer( "glClearDepth" ) );
    glDepthMask = reinterpret_cast<PFNGLDEPTHMASKPROC>( GetFunctionPointer( "glDepthMask" ) );
    glDepthFunc = reinterpret_cast<PFNGLDEPTHFUNCPROC>( GetFunctionPointer( "glDepthFunc" ) );

    // stencil buffer
    glClearStencil = reinterpret_cast<PFNGLCLEARSTENCILPROC>( GetFunctionPointer( "glClearStencil" ) );
    glStencilMask = reinterpret_cast<PFNGLSTENCILMASKPROC>( GetFunctionPointer( "glStencilMask" ) );
    glStencilFunc = reinterpret_cast<PFNGLSTENCILFUNCPROC>( GetFunctionPointer( "glStencilFunc" ) );
    glStencilOp = reinterpret_cast<PFNGLSTENCILOPPROC>( GetFunctionPointer( "glStencilOp" ) );

    // polygon 
    glLineWidth = reinterpret_cast<PFNGLLINEWIDTHPROC>( GetFunctionPointer( "glLineWidth" ) );
    glPointSize = reinterpret_cast<PFNGLPOINTSIZEPROC>( GetFunctionPointer( "glPointSize" ) );
    glPolygonMode = reinterpret_cast<PFNGLPOLYGONMODEPROC>( GetFunctionPointer( "glPolygonMode" ) );
    glCullFace = reinterpret_cast<PFNGLCULLFACEPROC>( GetFunctionPointer( "glCullFace" ) );

    // draw
    glDrawArrays = reinterpret_cast<PFNGLDRAWARRAYSPROC>( GetFunctionPointer( "glDrawArrays" ) );
    glDrawElements = reinterpret_cast<PFNGLDRAWELEMENTSPROC>( GetFunctionPointer( "glDrawElements" ) );
    glMultiDrawArrays = reinterpret_cast<PFNGLMULTIDRAWARRAYSPROC>( GetFunctionPointer( "glMultiDrawArrays" ) );
    glMultiDrawElements = reinterpret_cast<PFNGLMULTIDRAWELEMENTSPROC>( GetFunctionPointer( "glMultiDrawElements" ) );
    glDrawElementsBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSBASEVERTEXPROC>( GetFunctionPointer( "glDrawElementsBaseVertex" ) );
    glDrawRangeElementsBaseVertex = reinterpret_cast<PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC>( GetFunctionPointer( "glDrawRangeElementsBaseVertex" ) );
    glMultiDrawElementsBaseVertex = reinterpret_cast<PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC>( GetFunctionPointer( "glMultiDrawElementsBaseVertex" ) );

    // GL_ARB_draw_instanced
    glDrawArraysInstanced = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>( GetFunctionPointer( "glDrawArraysInstanced" ) );
    glDrawElementsInstanced = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>( GetFunctionPointer( "glDrawElementsInstanced" ) );
    glDrawElementsInstancedBaseVertex = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC>( GetFunctionPointer( "glDrawElementsInstancedBaseVertex" ) );
    glDrawArraysInstancedBaseInstance = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>( GetFunctionPointer( "glDrawArraysInstancedBaseInstance" ) );
    glDrawElementsInstancedBaseInstance = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>( GetFunctionPointer( "glDrawElementsInstancedBaseInstance" ) );
    glDrawElementsInstancedBaseVertexBaseInstance = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>( GetFunctionPointer( "glDrawElementsInstancedBaseVertexBaseInstance" ) );

    // GL_ARB_draw_indirect
    glDrawArraysIndirect = reinterpret_cast<PFNGLDRAWARRAYSINDIRECTPROC>( GetFunctionPointer( "glDrawArraysIndirect" ) );
    glDrawElementsIndirect = reinterpret_cast<PFNGLDRAWELEMENTSINDIRECTPROC>( GetFunctionPointer( "glDrawElementsIndirect" ) );

    // GL_ARB_multi_draw_indirect
    glMultiDrawArraysIndirect = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTPROC>( GetFunctionPointer( "glMultiDrawArraysIndirect" ) );
    glMultiDrawElementsIndirect = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTPROC>( GetFunctionPointer( "glMultiDrawElementsIndirect" ) );
    glMultiDrawArraysIndirectCount = reinterpret_cast<PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC>( GetFunctionPointer( "glMultiDrawArraysIndirectCount" ) );
    glMultiDrawElementsIndirectCount = reinterpret_cast<PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC>( GetFunctionPointer( "glMultiDrawElementsIndirectCount" ) );

    // GL_ARB_transform_feedback2
    glDrawTransformFeedback = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKPROC>( GetFunctionPointer( "glDrawTransformFeedback" ) );
    glDrawTransformFeedbackStream = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC>( GetFunctionPointer( "glDrawTransformFeedbackStream" ) );
    glDrawTransformFeedbackInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>( GetFunctionPointer( "glDrawTransformFeedbackInstanced" ) );
    glDrawTransformFeedbackStreamInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>( GetFunctionPointer( "glDrawTransformFeedbackStreamInstanced" ) );

    // GL_ARB_debug_output // GL_KHR_debug  
    glDebugMessageControl = reinterpret_cast<PFNGLDEBUGMESSAGECONTROLPROC>( GetFunctionPointer( "glDebugMessageControl" ) );
    glDebugMessageCallback = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>( GetFunctionPointer( "glDebugMessageCallback" ) );
    glGetDebugMessageLog = reinterpret_cast<PFNGLGETDEBUGMESSAGELOGPROC>( GetFunctionPointer( "glGetDebugMessageLog" ) );
    glDebugMessageInsert = reinterpret_cast<PFNGLDEBUGMESSAGEINSERTPROC>( GetFunctionPointer( "glDebugMessageInsert" ) );
    glObjectLabel = reinterpret_cast<PFNGLOBJECTLABELPROC>( GetFunctionPointer( "glObjectLabel" ) );
    glGetObjectLabel = reinterpret_cast<PFNGLGETOBJECTLABELPROC>( GetFunctionPointer( "glGetObjectLabel" ) );
    glObjectPtrLabel = reinterpret_cast<PFNGLOBJECTPTRLABELPROC>( GetFunctionPointer( "glObjectPtrLabel" ) );
    glGetObjectPtrLabel = reinterpret_cast<PFNGLGETOBJECTPTRLABELPROC>( GetFunctionPointer( "glGetObjectPtrLabel" ) );

    // vertex array 
    glIsVertexArray = reinterpret_cast<PFNGLISVERTEXARRAYPROC>( GetFunctionPointer( "glIsVertexArray" ) );
    glCreateVertexArrays = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>( GetFunctionPointer( "glCreateVertexArrays" ) );
    glDeleteVertexArrays = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>( GetFunctionPointer( "glDeleteVertexArrays" ) );
    glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>( GetFunctionPointer( "glBindVertexArray" ) );             
    glEnableVertexArrayAttrib = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIBPROC>( GetFunctionPointer( "glEnableVertexArrayAttrib" ) );
    glDisableVertexArrayAttrib = reinterpret_cast<PFNGLDISABLEVERTEXARRAYATTRIBPROC>( GetFunctionPointer( "glDisableVertexArrayAttrib" ) );
    glVertexArrayAttribBinding = reinterpret_cast<PFNGLVERTEXARRAYATTRIBBINDINGPROC>( GetFunctionPointer( "glVertexArrayAttribBinding" ) );
    glVertexArrayAttribFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>( GetFunctionPointer( "glVertexArrayAttribFormat" ) );
    glVertexArrayElementBuffer = reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>( GetFunctionPointer( "glVertexArrayElementBuffer" ) );
    glVertexArrayVertexBuffer = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>( GetFunctionPointer( "glVertexArrayVertexBuffer" ) ); 

    // GL_ARB_multi_bind
    glVertexArrayVertexBuffers = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>( GetFunctionPointer( "glVertexArrayVertexBuffers" ) ); 

    // shader 
    glCreateShader = reinterpret_cast<PFNGLCREATESHADERPROC>( GetFunctionPointer( "glCreateShader" ) );
    glDeleteShader = reinterpret_cast<PFNGLDELETESHADERPROC>( GetFunctionPointer( "glDeleteShader" ) );
    glShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>( GetFunctionPointer( "glShaderSource" ) );
    glShaderBinary = reinterpret_cast<PFNGLSHADERBINARYPROC>( GetFunctionPointer( "glShaderBinary" ) );
    glCompileShader = reinterpret_cast<PFNGLCOMPILESHADERPROC>( GetFunctionPointer( "glCompileShader" ) );
    glSpecializeShader = reinterpret_cast<PFNGLSPECIALIZESHADERPROC>( GetFunctionPointer( "glSpecializeShader" ) );
    glGetShaderInfoLog = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>( GetFunctionPointer( "glGetShaderInfoLog" ) );
    glGetShaderiv = reinterpret_cast<PFNGLGETSHADERIVPROC>( GetFunctionPointer( "glGetShaderiv" ) );

    // program
    glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>( GetFunctionPointer( "glCreateProgram" ) );
    glDeleteProgram = reinterpret_cast<PFNGLDELETEPROGRAMPROC>( GetFunctionPointer( "glDeleteProgram" ) );
    glIsProgram = reinterpret_cast<PFNGLISPROGRAMPROC>( GetFunctionPointer( "glIsProgram" ) );
    glProgramParameteri = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>( GetFunctionPointer( "glProgramParameteri" ) );
    glAttachShader = reinterpret_cast<PFNGLATTACHSHADERPROC>( GetFunctionPointer( "glAttachShader" ) );
    glDetachShader = reinterpret_cast<PFNGLDETACHSHADERPROC>( GetFunctionPointer( "glDetachShader" ) );
    glLinkProgram = reinterpret_cast<PFNGLLINKPROGRAMPROC>( GetFunctionPointer( "glLinkProgram" ) );
    glValidateProgram = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>( GetFunctionPointer( "glValidateProgram" ) );
    glGetProgramiv = reinterpret_cast<PFNGLGETPROGRAMIVPROC>( GetFunctionPointer( "glGetProgramiv" ) );
    glGetProgramInfoLog = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>( GetFunctionPointer( "glGetProgramInfoLog" ) );
    glUseProgram = reinterpret_cast<PFNGLUSEPROGRAMPROC>( GetFunctionPointer( "glUseProgram" ) );
    glUniform1i = reinterpret_cast<PFNGLUNIFORM1IPROC>( GetFunctionPointer( "glUniform1i" ) );
    glUniform1iv = reinterpret_cast<PFNGLUNIFORM1IVPROC>( GetFunctionPointer( "glUniform1iv" ) );
    glUniform1uiv = reinterpret_cast<PFNGLUNIFORM1UIVPROC>( GetFunctionPointer( "glUniform1uiv" ) );

    // pipelines
    glBindProgramPipeline = reinterpret_cast<PFNGLBINDPROGRAMPIPELINEPROC>( GetFunctionPointer( "glBindProgramPipeline" ) );
    glCreateProgramPipelines = reinterpret_cast<PFNGLCREATEPROGRAMPIPELINESPROC>( GetFunctionPointer( "glCreateProgramPipelines" ) );
    glDeleteProgramPipelines = reinterpret_cast<PFNGLDELETEPROGRAMPIPELINESPROC>( GetFunctionPointer( "glDeleteProgramPipelines" ) );
    glValidateProgramPipeline = reinterpret_cast<PFNGLVALIDATEPROGRAMPIPELINEPROC>( GetFunctionPointer( "glValidateProgramPipeline" ) );
    glGetProgramPipelineiv = reinterpret_cast<PFNGLGETPROGRAMPIPELINEIVPROC>( GetFunctionPointer( "glGetProgramPipelineiv" ) );
    glGetProgramPipelineInfoLog = reinterpret_cast<PFNGLGETPROGRAMPIPELINEINFOLOGPROC>( GetFunctionPointer( "glGetProgramPipelineInfoLog" ) );
    glUseProgramStages = reinterpret_cast<PFNGLUSEPROGRAMSTAGESPROC>( GetFunctionPointer( "glUseProgramStages" ) );
    glActiveShaderProgram = reinterpret_cast<PFNGLACTIVESHADERPROGRAMPROC>( GetFunctionPointer( "glActiveShaderProgram" ) );
    glProgramUniform1i = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>( GetFunctionPointer( "glProgramUniform1i" ) );
    glProgramUniform1iv = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>( GetFunctionPointer( "glProgramUniform1iv" ) );
    glProgramUniform1uiv = reinterpret_cast<PFNGLPROGRAMUNIFORM1UIVPROC>( GetFunctionPointer( "glProgramUniform1uiv" ) );

    // buffer
    glIsBuffer = reinterpret_cast<PFNGLISBUFFERPROC>( GetFunctionPointer( "glIsBuffer" ) );
    glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>( GetFunctionPointer( "glBindBuffer" ) );
    glBindBufferBase = reinterpret_cast<PFNGLBINDBUFFERBASEPROC>( GetFunctionPointer( "glBindBufferBase" ) );
    glBindBufferRange = reinterpret_cast<PFNGLBINDBUFFERRANGEPROC>( GetFunctionPointer( "glBindBufferRange" ) );
    glCreateBuffers = reinterpret_cast<PFNGLCREATEBUFFERSPROC>( GetFunctionPointer( "glCreateBuffers" ) );
    glDeleteBuffers = reinterpret_cast<PFNGLDELETEBUFFERSPROC>( GetFunctionPointer( "glDeleteBuffers" ) );
    glNamedBufferStorage = reinterpret_cast<PFNGLNAMEDBUFFERSTORAGEPROC>( GetFunctionPointer( "glNamedBufferStorage" ) );
    glMapNamedBufferRange = reinterpret_cast<PFNGLMAPNAMEDBUFFERRANGEPROC>( GetFunctionPointer( "glMapNamedBufferRange" ) );
    glUnmapNamedBuffer = reinterpret_cast<PFNGLUNMAPNAMEDBUFFERPROC>( GetFunctionPointer( "glUnmapNamedBuffer" ) );
    glFlushMappedNamedBufferRange = reinterpret_cast<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>( GetFunctionPointer( "glFlushMappedNamedBufferRange" ) );
    glNamedBufferSubData = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>( GetFunctionPointer( "glNamedBufferSubData" ) );
    glGetNamedBufferSubData = reinterpret_cast<PFNGLGETNAMEDBUFFERSUBDATAPROC>( GetFunctionPointer( "glGetNamedBufferSubData" ) );
    glCopyNamedBufferSubData = reinterpret_cast<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>( GetFunctionPointer( "glCopyNamedBufferSubData" ) );

    // GL_ARB_multi_bind
    glBindBuffersRange = reinterpret_cast<PFNGLBINDBUFFERSRANGEPROC>( GetFunctionPointer( "glBindBuffersRange" ) );
    glBindBuffersBase = reinterpret_cast<PFNGLBINDBUFFERSBASEPROC>( GetFunctionPointer( "glBindBuffersBase" ) );

    // Image
    glBindTexture = reinterpret_cast<PFNGLBINDTEXTUREPROC>( GetFunctionPointer( "glBindTexture" ) );
    glBindTextures = reinterpret_cast<PFNGLBINDTEXTURESPROC>( GetFunctionPointer( "glBindTextures" ) );
    glBindTextureUnit = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>( GetFunctionPointer( "glBindTextureUnit" ) );
    glCreateTextures = reinterpret_cast<PFNGLCREATETEXTURESPROC>( GetFunctionPointer( "glCreateTextures" ) );
    glDeleteTextures = reinterpret_cast<PFNGLDELETETEXTURESPROC>( GetFunctionPointer( "glDeleteTextures" ) );
    glIsTexture = reinterpret_cast<PFNGLISTEXTUREPROC>( GetFunctionPointer( "glIsTexture" ) );
    glTextureStorage1D = reinterpret_cast<PFNGLTEXTURESTORAGE1DPROC>( GetFunctionPointer( "glTextureStorage1D" ) );
    glTextureStorage2D = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>( GetFunctionPointer( "glTextureStorage2D" ) );
    glTextureStorage3D = reinterpret_cast<PFNGLTEXTURESTORAGE3DPROC>( GetFunctionPointer( "glTextureStorage3D" ) );
    glTextureStorage2DMultisample = reinterpret_cast<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>( GetFunctionPointer( "glTextureStorage2DMultisample" ) );
    glTextureStorage3DMultisample = reinterpret_cast<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>( GetFunctionPointer( "glTextureStorage3DMultisample" ) );
    glTextureSubImage1D = reinterpret_cast<PFNGLTEXTURESUBIMAGE1DPROC>( GetFunctionPointer( "glTextureSubImage1D" ) );
    glTextureSubImage2D = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>( GetFunctionPointer( "glTextureSubImage2D" ) );
    glTextureSubImage3D = reinterpret_cast<PFNGLTEXTURESUBIMAGE3DPROC>( GetFunctionPointer( "glTextureSubImage3D" ) );
    glCopyTextureSubImage1D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE1DPROC>( GetFunctionPointer( "glCopyTextureSubImage1D" ) );
    glCopyTextureSubImage2D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE2DPROC>( GetFunctionPointer( "glCopyTextureSubImage2D" ) );
    glCopyTextureSubImage3D = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE3DPROC>( GetFunctionPointer( "glCopyTextureSubImage3D" ) );
    glTextureParameteriv = reinterpret_cast<PFNGLTEXTUREPARAMETERIVPROC>( GetFunctionPointer( "glTextureParameteriv" ) );
    glTextureParameterfv = reinterpret_cast<PFNGLTEXTUREPARAMETERFVPROC>( GetFunctionPointer( "glTextureParameterfv" ) );
    glGetTextureParameteriv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIVPROC>( GetFunctionPointer( "glGetTextureParameteriv" ) );
    glGetTextureParameterfv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERFVPROC>( GetFunctionPointer( "glGetTextureParameterfv" ) );
    glGetTextureLevelParameterfv = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERFVPROC>( GetFunctionPointer( "glGetTextureLevelParameterfv" ) );
    glGetTextureLevelParameteriv = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERIVPROC>( GetFunctionPointer( "glGetTextureLevelParameteriv" ) );
    glGetTextureImage = reinterpret_cast<PFNGLGETTEXTUREIMAGEPROC>( GetFunctionPointer( "glGetTextureImage" ) );
    glGetCompressedTextureImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>( GetFunctionPointer( "glGetCompressedTextureImage" ) );
    glInvalidateTexImage = reinterpret_cast<PFNGLINVALIDATETEXIMAGEPROC>( GetFunctionPointer( "glInvalidateTexImage" ) );

    // GL_ARB_invalidate_subdata
    glInvalidateTexSubImage = reinterpret_cast<PFNGLINVALIDATETEXSUBIMAGEPROC>( GetFunctionPointer( "glInvalidateTexSubImage" ) );

    // GL_ARB_clear_texture
    glClearTexImage = reinterpret_cast<PFNGLCLEARTEXIMAGEPROC>( GetFunctionPointer( "glClearTexImage" ) );
    glClearTexSubImage = reinterpret_cast<PFNGLCLEARTEXSUBIMAGEPROC>( GetFunctionPointer( "glClearTexSubImage" ) );

    // GL_ARB_get_texture_sub_image
    glGetTextureSubImage = reinterpret_cast<PFNGLGETTEXTURESUBIMAGEPROC>( GetFunctionPointer( "glGetTextureSubImage" ) );
    glGetCompressedTextureSubImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>( GetFunctionPointer( "glGetCompressedTextureSubImage" ) );

    // GL_ARB_copy_image
    glCopyImageSubData = reinterpret_cast<PFNGLCOPYIMAGESUBDATAPROC>( GetFunctionPointer( "glCopyImageSubData" ) );

    // GL_ARB_texture_view
    glTextureView = reinterpret_cast<PFNGLTEXTUREVIEWPROC>( GetFunctionPointer( "glTextureView" ) );

    //
    glCreateSamplers = reinterpret_cast<PFNGLCREATESAMPLERSPROC>( GetFunctionPointer( "glCreateSamplers" ) );
    glDeleteSamplers = reinterpret_cast<PFNGLDELETESAMPLERSPROC>( GetFunctionPointer( "glDeleteSamplers" ) );
    glBindSampler = reinterpret_cast<PFNGLBINDSAMPLERPROC>( GetFunctionPointer( "glBindSampler" ) );
    glBindSamplers = reinterpret_cast<PFNGLBINDSAMPLERSPROC>( GetFunctionPointer( "glBindSamplers" ) );
    glIsSampler = reinterpret_cast<PFNGLISSAMPLERPROC>( GetFunctionPointer( "glIsSampler" ) );
    glSamplerParameteri = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>( GetFunctionPointer( "glSamplerParameteri" ) );
    glSamplerParameteriv = reinterpret_cast<PFNGLSAMPLERPARAMETERIVPROC>( GetFunctionPointer( "glSamplerParameteriv" ) );
    glSamplerParameterf = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>( GetFunctionPointer( "glSamplerParameterf" ) );
    glSamplerParameterfv = reinterpret_cast<PFNGLSAMPLERPARAMETERFVPROC>( GetFunctionPointer( "glSamplerParameterfv" ) );
    glSamplerParameterIiv = reinterpret_cast<PFNGLSAMPLERPARAMETERIIVPROC>( GetFunctionPointer( "glSamplerParameterIiv" ) );
    glSamplerParameterIuiv = reinterpret_cast<PFNGLSAMPLERPARAMETERIUIVPROC>( GetFunctionPointer( "glSamplerParameterIuiv" ) );
    glGetSamplerParameteriv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIVPROC>( GetFunctionPointer( "glGetSamplerParameteriv" ) );
    glGetSamplerParameterIiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIIVPROC>( GetFunctionPointer( "glGetSamplerParameterIiv" ) );
    glGetSamplerParameterfv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERFVPROC>( GetFunctionPointer( "glGetSamplerParameterfv" ) );
    glGetSamplerParameterIuiv = reinterpret_cast<PFNGLGETSAMPLERPARAMETERIUIVPROC>( GetFunctionPointer( "glGetSamplerParameterIuiv" ) );

    // texture handler
    glGetTextureHandleARB = reinterpret_cast<PFNGLGETTEXTUREHANDLEARBPROC>( GetFunctionPointer( "glGetTextureHandleARB" ) );
    glGetTextureSamplerHandleARB = reinterpret_cast<PFNGLGETTEXTURESAMPLERHANDLEARBPROC>( GetFunctionPointer( "glGetTextureSamplerHandleARB" ) );
    glMakeTextureHandleResidentARB = reinterpret_cast<PFNGLMAKETEXTUREHANDLERESIDENTARBPROC>( GetFunctionPointer( "glMakeTextureHandleResidentARB" ) );
    glMakeTextureHandleNonResidentARB = reinterpret_cast<PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC>( GetFunctionPointer( "glMakeTextureHandleNonResidentARB" ) );
    glMakeImageHandleResidentARB = reinterpret_cast<PFNGLMAKEIMAGEHANDLERESIDENTARBPROC>( GetFunctionPointer( "glMakeImageHandleResidentARB" ) );
    glMakeImageHandleNonResidentARB = reinterpret_cast<PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC>( GetFunctionPointer( "glMakeImageHandleNonResidentARB" ) );
    glUniformHandleui64ARB = reinterpret_cast<PFNGLUNIFORMHANDLEUI64ARBPROC>( GetFunctionPointer( "glUniformHandleui64ARB" ) );
    glUniformHandleui64vARB = reinterpret_cast<PFNGLUNIFORMHANDLEUI64VARBPROC>( GetFunctionPointer( "glUniformHandleui64vARB" ) );
    glProgramUniformHandleui64ARB = reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC>( GetFunctionPointer( "glProgramUniformHandleui64ARB" ) );
    glProgramUniformHandleui64vARB = reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC>( GetFunctionPointer( "glProgramUniformHandleui64vARB" ) );
    glIsTextureHandleResidentARB = reinterpret_cast<PFNGLISTEXTUREHANDLERESIDENTARBPROC>( GetFunctionPointer( "glIsTextureHandleResidentARB" ) );
    glIsImageHandleResidentARB = reinterpret_cast<PFNGLISIMAGEHANDLERESIDENTARBPROC>( GetFunctionPointer( "glIsImageHandleResidentARB" ) );

    // GL_ARB_framebuffer_object
    glBindFramebuffer = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>( GetFunctionPointer( "glBindFramebuffer" ) );
    glIsFramebuffer = reinterpret_cast<PFNGLISFRAMEBUFFERPROC>( GetFunctionPointer( "glIsFramebuffer" ) );
    glDeleteFramebuffers = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>( GetFunctionPointer( "glDeleteFramebuffers" ) );
    glCreateFramebuffers = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>( GetFunctionPointer( "glCreateFramebuffers" ) );
    glNamedFramebufferTexture = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>( GetFunctionPointer( "glNamedFramebufferTexture" ) );
    glNamedFramebufferTextureLayer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>( GetFunctionPointer( "glNamedFramebufferTextureLayer" ) );
    glNamedFramebufferRenderbuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>( GetFunctionPointer( "glNamedFramebufferRenderbuffer" ) );
    glNamedFramebufferDrawBuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>( GetFunctionPointer( "glNamedFramebufferDrawBuffer" ) );
    glNamedFramebufferDrawBuffers = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>( GetFunctionPointer( "glNamedFramebufferDrawBuffers" ) );
    glNamedFramebufferReadBuffer = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>( GetFunctionPointer( "glNamedFramebufferReadBuffer" ) );
    glFramebufferRenderbuffer = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>( GetFunctionPointer( "glFramebufferRenderbuffer" ) );
    glFramebufferTexture1D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>( GetFunctionPointer( "glFramebufferTexture1D" ) );
    glFramebufferTexture2D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>( GetFunctionPointer( "glFramebufferTexture2D" ) );
    glFramebufferTexture3D = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>( GetFunctionPointer( "glFramebufferTexture3D" ) );
    glFramebufferTextureLayer = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>( GetFunctionPointer( "glFramebufferTextureLayer" ) );
    glFramebufferTexture = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>( GetFunctionPointer( "glFramebufferTexture" ) );
    glCheckNamedFramebufferStatus = reinterpret_cast<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>( GetFunctionPointer( "glCheckNamedFramebufferStatus" ) );
    glBlitNamedFramebuffer = reinterpret_cast<PFNGLBLITNAMEDFRAMEBUFFERPROC>( GetFunctionPointer( "glBlitNamedFramebuffer" ) );

    // rendebuffers 
    glIsRenderbuffer = reinterpret_cast<PFNGLISRENDERBUFFERPROC>( GetFunctionPointer( "glIsRenderbuffer" ) );
    glCreateRenderbuffers = reinterpret_cast<PFNGLCREATERENDERBUFFERSPROC>( GetFunctionPointer( "glCreateRenderbuffers" ) );
    glDeleteRenderbuffers = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>( GetFunctionPointer( "glDeleteRenderbuffers" ) );
    glNamedRenderbufferStorage = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>( GetFunctionPointer( "glNamedRenderbufferStorage" ) );
    glNamedRenderbufferStorageMultisample = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>( GetFunctionPointer( "glNamedRenderbufferStorageMultisample" ) );
    glGetNamedRenderbufferParameteriv = reinterpret_cast<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>( GetFunctionPointer( "glGetNamedRenderbufferParameteriv" ) );

    //GL_ARB_sync
    glIsSync = reinterpret_cast<PFNGLISSYNCPROC>( GetFunctionPointer( "glIsSync" ) );
    glFenceSync = reinterpret_cast<PFNGLFENCESYNCPROC>( GetFunctionPointer( "glFenceSync" ) );
    glClientWaitSync = reinterpret_cast<PFNGLCLIENTWAITSYNCPROC>( GetFunctionPointer( "glClientWaitSync" ) );
    glDeleteSync = reinterpret_cast<PFNGLDELETESYNCPROC>( GetFunctionPointer( "glDeleteSync" ) );
    glWaitSync = reinterpret_cast<PFNGLWAITSYNCPROC>( GetFunctionPointer( "glWaitSync" ) );
    glGetSynciv = reinterpret_cast<PFNGLGETSYNCIVPROC>( GetFunctionPointer( "glGetSynciv" ) );   
}