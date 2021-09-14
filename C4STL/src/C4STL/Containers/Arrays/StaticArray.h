#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_STATIC_ARRAY_H
#define C4STL_STATIC_ARRAY_H

#include "C4STL/Core/Core.h"

#include "Array.h"

namespace C4STL
{

	template<typename __TYPE, size_t __SIZE>
	class C4STL_PUBLIC_API StaticArray : public Array<__TYPE> {
	public:
		StaticArray() C4STL_NOEXCEPT;
		virtual ~StaticArray() C4STL_NOEXCEPT override;

		inline virtual size_t Size() const C4STL_NOEXCEPT override { return __SIZE; };

		virtual __TYPE* Data() C4STL_NOEXCEPT override;
		
		virtual __TYPE& Front() C4STL_NOEXCEPT override;
		virtual __TYPE& Back() C4STL_NOEXCEPT override;
		virtual __TYPE& At(size_t index) C4STL_NOEXCEPT override;

		virtual __TYPE& operator [] (size_t index) C4STL_NOEXCEPT override;

	private:
		__TYPE m_Data[__SIZE];
	};

};

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif