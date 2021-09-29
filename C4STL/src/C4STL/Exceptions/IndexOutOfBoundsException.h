#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define C4STL_INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include "C4STL/Core/Core.h"
#include "Exception.h"

namespace C4STL
{

	class C4STL_PUBLIC_API IndexOutOfBoundsException : public Exception<size_t>
	{
	public:
		IndexOutOfBoundsException(const std::string& errorMessage = "Index out of bounds.", size_t index = static_cast<size_t>(-1)) C4STL_NOEXCEPT;
		IndexOutOfBoundsException(size_t index) C4STL_NOEXCEPT;
		virtual ~IndexOutOfBoundsException() C4STL_NOEXCEPT override;

		virtual size_t GetCause() C4STL_NOEXCEPT override;

	private:
		size_t m_Cause;
	};
	
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif