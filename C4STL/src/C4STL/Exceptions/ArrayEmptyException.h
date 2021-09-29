#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_QUEUE_EMPTY_EXCEPTION_H
#define C4STL_QUEUE_EMPTY_EXCEPTION_H

#include "C4STL/Core/Core.h"
#include "Exception.h"
#include "C4STL/Containers/Arrays/Array.h"

namespace C4STL
{

	template<typename __TYPE>
	class ArrayEmptyException : public Exception<Array<__TYPE>*>
	{
	public:
		ArrayEmptyException(const std::string& errorMessage = "Array empty exception.", const Array<__TYPE>* const array = nullptr) C4STL_NOEXCEPT;
		ArrayEmptyException(const Array<__TYPE>* const array) C4STL_NOEXCEPT;
		virtual ~ArrayEmptyException() C4STL_NOEXCEPT override;

		virtual const Array<__TYPE>* const GetCause() C4STL_NOEXCEPT override;

	private:
		const Array<__TYPE>* const m_Cause;
	};

}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif