
cmake_minimum_required( VERSION 3.16 )

project( crglLib )

## STD 17
set( CMAKE_CXX_STANDARD 17 )

# build test option
option( BUILD_TEST	"Build Test app" OFF )


############################
##  Build Configuration   ##
############################
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID STREQUAL "Clang")

	# memory debugging	
	add_compile_options( -pipe )
	add_compile_options( -fPIC )
	add_compile_options( -Wall )
	#add_compile_options( -Wunknown-pragmas )

	set(CMAKE_C_FLAGS_DEBUG "-g -ggdb -D_DEBUG -O0")
	set(CMAKE_C_FLAGS_DEBUGALL "-g -ggdb -D_DEBUG")
	set(CMAKE_C_FLAGS_PROFILE "-g -ggdb -D_DEBUG -O2 -fno-omit-frame-pointer -Wunknown-pragmas")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -fno-math-errno -fno-trapping-math -fomit-frame-pointer")
	set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -ggdb -O2 -fno-math-errno -fno-trapping-math -fno-omit-frame-pointer")
	set(CMAKE_C_FLAGS_MINSIZEREL "-Os -fno-math-errno -fno-trapping-math -fomit-frame-pointer")

	set(CMAKE_CXX_FLAGS_DEBUGALL ${CMAKE_C_FLAGS_DEBUGALL})
	set(CMAKE_CXX_FLAGS_PROFILE ${CMAKE_C_FLAGS_PROFILE})
else()
	#message(FATAL_ERROR "Unsupported compiler")
endif()

find_package( OpenGL )

#
if( OpenGL_FOUND )
	include_directories( ${OpenGL_INCLUDE_DIR} )
else( OpenGL_FOUND)
	include_directories( ${CMAKE_SOURCE_DIR}/contrib/OpenGL/include )	
endif( OpenGL_FOUND )




# 
include_directories( ${CMAKE_SOURCE_DIR}/lib/include )

add_subdirectory( lib )

if( BUILD_TEST )
	add_subdirectory( test )
endif( BUILD_TEST )