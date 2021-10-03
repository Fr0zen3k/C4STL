cmake_minimum_required(VERSION 3.20.0)

project(C4STL VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/C4STL/src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/C4STL/vendor/LinkCL")

set(
	C4STL_FILES 
	"${C4STL_SOURCE_FILES}" 
	"${C4STL_HEADER_FILES}" 
	CACHE INTERNAL "" FORCE
	)

add_library(
	C4STL 
	SHARED 
	"${C4STL_FILES}"
	)

target_link_libraries(C4STL PUBLIC LinkCL)

target_include_directories(C4STL PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/C4STL/src")

target_compile_definitions(C4STL PRIVATE __C4STL_BUILD)