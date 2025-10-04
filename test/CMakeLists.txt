find_package( SDL3 REQUIRED )
include_directories( ${SDL3_INCLUDE_DIR} ) 

set( CRGLTEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/crglTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/crglTest.hpp 
    )

set( CRGLTEST_LIBRARIES crglLib ${SDL3_LIBRARIES} )

add_executable( crglTest ${CRGLTEST_SOURCES} )
add_dependencies( crglTest crglLib )
target_link_libraries( crglTest PRIVATE ${CRGLTEST_LIBRARIES} )