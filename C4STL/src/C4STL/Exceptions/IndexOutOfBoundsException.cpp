#include "IndexOutOfBoundsException.h"

namespace C4STL
{

	IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& errorMessage /* = "Index out of bounds."*/, size_t index /*static_cast<size_t>(-1)*/) C4STL_NOEXCEPT : Exception(errorMessage), m_Cause(index) {}
	IndexOutOfBoundsException::IndexOutOfBoundsException(size_t index) C4STL_NOEXCEPT : Exception("Index out of bounds."), m_Cause(index) {}

	IndexOutOfBoundsException::~IndexOutOfBoundsException() C4STL_NOEXCEPT {
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
		// Warn the exception was destroyed without handling.
		/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
	}

	size_t IndexOutOfBoundsException::GetCause() C4STL_NOEXCEPT { return m_Cause; }
}