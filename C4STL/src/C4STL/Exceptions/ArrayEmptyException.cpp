#include "ArrayEmptyException.h"

namespace C4STL
{

	template<typename __TYPE>
	ArrayEmptyException<__TYPE>::ArrayEmptyException(const std::string& errorMessage, const Array<__TYPE>* const array) C4STL_NOEXCEPT : Exception(errorMessage), m_Cause(array) {}

	template<typename __TYPE>
	ArrayEmptyException<__TYPE>::ArrayEmptyException(const Array<__TYPE>* const array) C4STL_NOEXCEPT : Exception("Array empty exception."), m_Cause(array) {}
	
	template<typename __TYPE>
	ArrayEmptyException<__TYPE>::~ArrayEmptyException() C4STL_NOEXCEPT
	{
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
		// Warn the exception was destroyed without handling.
		/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
	}

	template<typename __TYPE>
	const Array<__TYPE>* const ArrayEmptyException<__TYPE>::GetCause() C4STL_NOEXCEPT {
		return m_Cause;
	}
}