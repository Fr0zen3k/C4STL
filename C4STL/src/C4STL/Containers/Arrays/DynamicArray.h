#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_DYNAMIC_ARRAY_H
#define C4STL_DYNAMIC_ARRAY_H

#include "C4STL/Core/Core.h"
#include "Array.h"

namespace C4STL
{

	template<typename __TYPE>
	class DynamicArray : public Array<__TYPE> {
	public:
		DynamicArray(size_t size = 0, __TYPE* data = nullptr) C4STL_NOEXCEPT;
		virtual ~DynamicArray() C4STL_NOEXCEPT override;

		inline virtual size_t Size() const C4STL_NOEXCEPT { return m_Size; }

		virtual __TYPE* Data() C4STL_NOEXCEPT override;

		virtual __TYPE& Front() C4STL_NOEXCEPT override;
		virtual __TYPE& Back() C4STL_NOEXCEPT override;
		virtual __TYPE& At(size_t index) C4STL_NOEXCEPT override;

		virtual __TYPE& operator [] (size_t index) C4STL_NOEXCEPT override;

	private:
		__TYPE* m_Data;

		size_t m_Size = 0;
		size_t m_RealSize = 2;
	};

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif