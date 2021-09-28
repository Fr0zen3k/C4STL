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

	enum class C4STL_PUBLIC_API ExceptionType
	{
		NONE								= 0,
		ARRAY_EMPTY							= 1,
		QUEUE_EMPTY							= 2,
		STACK_EMPTY							= 3,
		LIST_EMPTY							= 4,
		MAP_EMPTY							= 5,
		SET_EMPTY							= 6,
		INDEX_OUT_BOUNDS					= 7,
		DIVISION_BY_ZERO					= 8,
		INVALID_VECTOR_MULTIPLICATION		= 9,
		INVALID_MATRIX_MULTIPLICATION		= 10,
		UNDEFINED_BEHAVIOUR					= 11,
		INVALID_SYNTAX						= 12,
		INVALID_SEMANTICS					= 13,
		STRING_EMPTY						= 14,
		NULL_POINTER						= 15,
		FORMAT								= 16
	};

	enum class C4STL_PUBLIC_API ExceptionCategory
	{
		GENERAL								= C4STL_BIT(0),
		ALGORITHM							= C4STL_BIT(1),
		PROCESSING							= C4STL_BIT(2),
		MATH								= C4STL_BIT(3),
		CONTAINER							= C4STL_BIT(4),
		STRING								= C4STL_BIT(5),
		ARTIFICIAL_INTELLIGENCE				= C4STL_BIT(6)
	};

	template<typename __TYPE>
	class C4STL_PUBLIC_API Exception {
	public:
		inline Exception(const std::string& errorMessage = "") C4STL_NOEXCEPT : m_ErrorMessage(errorMessage), m_ThrowTime(std::chrono::high_resolution_clock::now()) {}
		inline virtual ~Exception() C4STL_NOEXCEPT {
#ifndef C4STL_EXCEPTION_NOHANDLE_WARN
			// Warn the exception was destroyed without handling.
			/////////////// INSERT FUNCTIONALITY WHEN LOGGING IS FINISHED //////////////////
#endif // !C4STL_NOHANDLE_WARN
		}

		std::string GetErrorMessage() const C4STL_NOEXCEPT;

		std::chrono::high_resolution_clock::time_point GetThrowTime() const C4STL_NOEXCEPT;

		inline void Handle() C4STL_NOEXCEPT { m_Handled = true; }
		bool Handled() const C4STL_NOEXCEPT;

		virtual __TYPE GetCause() C4STL_NOEXCEPT = 0;

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