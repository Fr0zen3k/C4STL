#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_STACK_H
#define C4STL_STACK_H

#include "C4STL/Core/Core.h"

namespace C4STL {

	template<typename __TYPE>
	class C4STL_PUBLIC_API Queue {
	public:
		Queue() C4STL_NOEXCEPT;
		virtual ~Queue() C4STL_NOEXCEPT;

		size_t Size() const C4STL_NOEXCEPT;

		void Push(const __TYPE& value) C4STL_NOEXCEPT;
		__TYPE Pull() const;
		__TYPE& Peek();

		inline bool Empty() const C4STL_NOEXCEPT { return Size() == 0; }

	private:
		__TYPE* m_Data;

		size_t m_First = 0;
		size_t m_Last = 0;
		size_t m_BufferSize = 64;
	};

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif