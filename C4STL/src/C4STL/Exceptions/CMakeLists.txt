set(C4STL_EXCEPTIONS_SOURCES 
	"${CMAKE_CURRENT_SOURCE_DIR}/Exception.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/StackEmptyException.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/ArrayEmptyException.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/QueueEmptyException.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/IndexOutOfBoundsException.cpp"
	CACHE INTERNAL "" FORCE)

set(C4STL_EXCEPTIONS_HEADERS 
	"${CMAKE_CURRENT_SOURCE_DIR}/Exception.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/StackEmptyException.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/ArrayEmptyException.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/QueueEmptyException.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/IndexOutOfBoundsException.h"
	CACHE INTERNAL "" FORCE)