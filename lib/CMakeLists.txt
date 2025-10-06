
set( CRVK_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglPrecompiled.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglCore.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglFormat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglFrameBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglImage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglContext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglBuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglShaders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/crglVertexArray.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglCore.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglContext.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglFrameBuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglImage.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglBuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglShaders.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/crglVertexArray.hpp
    )

add_library( crglLib STATIC ${CRVK_SOURCES} )
target_include_directories( crglLib  PRIVATE ${CMAKE_SOURCE_DIR} )
target_precompile_headers( crglLib PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/source/crglPrecompiled.hpp>" )