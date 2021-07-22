#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ARRAY_H
#define C4STL_ARRAY_H

#include "C4STL/Core/Core.h"

namespace C4STL
{

	template <typename __TYPE, size_t __SIZE = 1>
	class C4STL_PUBLIC_API Array {
	public:
		  Array() C4STL_NOEXCEPT(__SIZE != 0);
		  // Init from array
		  Array(const __TYPE* const dataArray) C4STL_NOEXCEPT(__SIZE != 0);
		  // Init all to one value
		  Array(const __TYPE& data) C4STL_NOEXCEPT(__SIZE != 0);
		  virtual ~Array() C4STL_NOEXCEPT = default;

		  inline size_t Size() const C4STL_NOEXCEPT { return __SIZE; }

		  __TYPE* Data() C4STL_NOEXCEPT(__SIZE != 0);

		  __TYPE& Front() C4STL_NOEXCEPT(__SIZE != 0);
		  __TYPE& Back() C4STL_NOEXCEPT(__SIZE != 0);
		  __TYPE& At(size_t index) C4STL_NOEXCEPT(index < __SIZE && __SIZE > 0);

		  __TYPE& operator [] (size_t index) C4STL_NOEXCEPT(index < __SIZE && __SIZE > 0);

	private:
		__TYPE m_Data[__SIZE];
	};

};

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif