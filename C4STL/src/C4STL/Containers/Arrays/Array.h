#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ARRAY_H
#define C4STL_ARRAY_H

#include "C4STL/Core/Core.h"

namespace C4STL {

	template<typename __TYPE>
	class C4STL_PUBLIC_API Array {
	public:
		virtual ~Array() C4STL_NOEXCEPT {};

		virtual size_t Size() const C4STL_NOEXCEPT = 0;
		
		virtual __TYPE* Data() C4STL_NOEXCEPT = 0;

		virtual __TYPE& Front() C4STL_NOEXCEPT = 0;
		virtual __TYPE& Back() C4STL_NOEXCEPT = 0;
		virtual __TYPE& At(size_t index) C4STL_NOEXCEPT = 0;

		virtual __TYPE& operator [] (size_t index) C4STL_NOEXCEPT = 0;
	};

}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif