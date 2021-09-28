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
		StaticArray();
		virtual ~StaticArray() C4STL_NOEXCEPT override;

		inline virtual size_t Size() const C4STL_NOEXCEPT override { return __SIZE; };

		virtual __TYPE* Data() override;
		
		virtual __TYPE& Front() override;
		virtual __TYPE& Back() override;
		virtual __TYPE& At(size_t index) override;

		virtual __TYPE& operator [] (size_t index) override;

	private:
		__TYPE m_Data[__SIZE];
	};

};

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif