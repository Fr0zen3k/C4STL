#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_DYNAMIC_ARRAY_H
#define C4STL_DYNAMIC_ARRAY_H

#include "C4STL/Core/Core.h"

namespace C4STL
{

	template<typename __TYPE>
	class C4STL_PUBLIC_API DynamicArray {
	public:
		DynamicArray(size_t size = 0, __TYPE data = __TYPE()) C4STL_NOEXCEPT;
		DynamicArray(size_t size = 0, __TYPE* dataArray = nullptr) C4STL_NOEXCEPT;
		virtual ~DynamicArray() C4STL_NOEXCEPT;

		inline size_t Size() const C4STL_NOEXCEPT { return m_Size; }
		bool Empty() const C4STL_NOEXCEPT;

		__TYPE& Front() C4STL_NOEXCEPT(m_Size > 0);
		__TYPE& Back() C4STL_NOEXCEPT(m_Size > 0);
		__TYPE& At(size_t index) C4STL_NOEXCEPT(m_Size > 0);
		
		__TYPE* Data() C4STL_NOEXCEPT(m_Size > 0);

		__TYPE& operator [] (size_t index) C4STL_NOEXCEPT(m_Size > 0);
		
	private:
		void ResizeData();
		
	private:
		__TYPE* m_Data = nullptr;
		
		size_t m_Size;
		size_t m_InternalSize = 16;
	};
	
}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif