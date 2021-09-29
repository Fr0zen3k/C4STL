#include "StackEmptyException.h"

namespace C4STL
{

	template<typename __TYPE>
	StackEmptyException<__TYPE>::StackEmptyException(const std::string& errorMessage, const Stack<__TYPE>* const stack) C4STL_NOEXCEPT : Exception(errorMessage), m_Cause(stack) {}

	template<typename __TYPE>
	StackEmptyException<__TYPE>::StackEmptyException(const Stack<__TYPE>* const stack) C4STL_NOEXCEPT : Exception("Stack empty exception."), m_Cause(stack) {}
	
	template<typename __TYPE>
	StackEmptyException<__TYPE>::~StackEmptyException() C4STL_NOEXCEPT
	{
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
		// Warn the exception was destroyed without handling.
		/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
	}

	template<typename __TYPE>
	const Stack<__TYPE>* const StackEmptyException<__TYPE>::GetCause() C4STL_NOEXCEPT {
		return m_Cause;
	}
}