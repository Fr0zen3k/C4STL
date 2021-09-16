#include "Exception.h"

namespace C4STL {
	template<typename __TYPE>
	Exception<__TYPE>::Exception(const std::string& errorMessage /* = "" */) C4STL_NOEXCEPT : m_ErrorMessage(errorMessage), m_ThrowTime(std::chrono::high_resolution_clock::now()) {}

	template<typename __TYPE>
	Exception<__TYPE>::~Exception() C4STL_NOEXCEPT {
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
		// Warn the exception was destroyed without handling.
		/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
	}

	template<typename __TYPE>
	std::string Exception<__TYPE>::GetErrorMessage() const C4STL_NOEXCEPT { return m_ErrorMessage; }

	template<typename __TYPE>
	std::chrono::high_resolution_clock::time_point Exception<__TYPE>::GetThrowTime() const C4STL_NOEXCEPT { return m_ThrowTime; }

	template<typename __TYPE>
	bool Exception<__TYPE>::Handled() const C4STL_NOEXCEPT { return m_Handled; }

	template<typename __TYPE>
	__TYPE Exception<__TYPE>::GetCause() C4STL_NOEXCEPT { return NULL; }
}