add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Random")

set(C4STL_MATH_SOURCES 
	"${C4STL_MATH_RANDOM_SOURCES}"
	"${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp" 
	"${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp" 
	"${CMAKE_CURRENT_SOURCE_DIR}/Math.cpp"
	CACHE INTERNAL "" FORCE)

set(C4STL_MATH_HEADERS 
	"${C4STL_MATH_RANDOM_HEADERS}"
	"${CMAKE_CURRENT_SOURCE_DIR}/Vector.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h" 
	"${CMAKE_CURRENT_SOURCE_DIR}/Math.h" 
	CACHE INTERNAL "" FORCE)