#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_EXCEPTION_H
#define C4STL_EXCEPTION_H

#include "C4STL/Core/Core.h"

#include <string>
#include <chrono>

namespace C4STL {

	template<typename __TYPE = void*>
	class C4STL_PUBLIC_API Exception {
	public:
		Exception(const std::string& errorMessage = "") C4STL_NOEXCEPT;
		virtual ~Exception() C4STL_NOEXCEPT;

		std::string GetErrorMessage() const C4STL_NOEXCEPT;

		std::chrono::high_resolution_clock::time_point GetThrowTime() const C4STL_NOEXCEPT;

		bool Handled() const C4STL_NOEXCEPT;

		virtual __TYPE GetCause() C4STL_NOEXCEPT;

	private:
		std::string m_ErrorMessage;
		bool m_Handled = false;
		std::chrono::high_resolution_clock::time_point m_ThrowTime;
	};

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif