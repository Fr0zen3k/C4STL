#include "QueueEmptyException.h"

namespace C4STL
{

	template<typename __TYPE>
	QueueEmptyException<__TYPE>::QueueEmptyException(const std::string& errorMessage, const Queue<__TYPE>* const queue) C4STL_NOEXCEPT : Exception(errorMessage), m_Cause(queue) {}

	template<typename __TYPE>
	QueueEmptyException<__TYPE>::QueueEmptyException(const Queue<__TYPE>* const queue) C4STL_NOEXCEPT : Exception("Queue empty exception."), m_Cause(queue) {}
	
	template<typename __TYPE>
	QueueEmptyException<__TYPE>::~QueueEmptyException() C4STL_NOEXCEPT
	{
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
		// Warn the exception was destroyed without handling.
		/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
	}

	template<typename __TYPE>
	const Queue<__TYPE>* const QueueEmptyException<__TYPE>::GetCause() C4STL_NOEXCEPT {
		return m_Cause;
	}
}