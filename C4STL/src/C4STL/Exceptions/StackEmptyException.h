#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_STACK_EMPTY_EXCEPTION_H
#define C4STL_STACK_EMPTY_EXCEPTION_H

#include "C4STL/Core/Core.h"
#include "Exception.h"
#include "C4STL/Containers/Stack.h"

namespace C4STL
{
	
	template<typename __TYPE>
	class StackEmptyException : public Exception<Stack<__TYPE>*>
	{
	public:
		StackEmptyException(const std::string& errorMessage = "Stack empty exception.", const Stack<__TYPE>* const stack = nullptr) C4STL_NOEXCEPT;
		StackEmptyException(const Stack<__TYPE>* const stack) C4STL_NOEXCEPT;
		virtual ~StackEmptyException() C4STL_NOEXCEPT override;

		virtual const Stack<__TYPE>* const GetCause() C4STL_NOEXCEPT override;

	private:
		const Stack<__TYPE>* const m_Cause;
	};
	
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif