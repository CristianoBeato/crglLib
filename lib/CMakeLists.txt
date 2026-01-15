
set( CRVK_SOURCES
    ../source/crglPrecompiled.hpp
    ../source/crglCore.cpp
    ../source/crglFence.cpp
    ../source/crglFormat.cpp
    ../source/crglFrameBuffer.cpp
    ../source/crglSampler.cpp
    ../source/crglImage.cpp
    ../source/crglImageHandler.cpp
    ../source/crglContext.cpp
    ../source/crglBuffer.cpp
    ../source/crglShaders.cpp
    ../source/crglVertexArray.cpp
    ../include/crglCore.hpp
    ../include/crglEnumerators.hpp
    ../include/crglContext.hpp
    ../include/crglFence.hpp
    ../include/crglFormat.hpp
    ../include/crglFrameBuffer.hpp
    ../include/crglSampler.hpp
    ../include/crglImage.hpp
    ../include/crglBuffer.hpp
    ../include/crglShaders.hpp
    ../include/crglVertexArray.hpp
    )

add_library( crglLib STATIC ${CRVK_SOURCES} )
target_include_directories( crglLib  PRIVATE ../include )
target_include_directories( crglLib  PRIVATE ${CMAKE_SOURCE_DIR} )
target_precompile_headers( crglLib PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:source/crglPrecompiled.hpp>" )