#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_LINKED_LIST_H
#define C4STL_LINKED_LIST_H

#include "C4STL/Core/Core.h"
#include "List.h"

namespace C4STL
{
	template<typename __TYPE>
	class C4STL_PUBLIC_API LinkedList : public List<__TYPE>
	{
	public:
		LinkedList() C4STL_NOEXCEPT;
		virtual ~LinkedList() C4STL_NOEXCEPT;

		virtual __TYPE& Head() C4STL_NOEXCEPT override;
		virtual __TYPE& Tail() C4STL_NOEXCEPT override;
		inline virtual size_t Size() const C4STL_NOEXCEPT override { return m_Size; };
		virtual __TYPE& Next(const __TYPE& value) C4STL_NOEXCEPT override;
        virtual __TYPE& Previous(const __TYPE& value) C4STL_NOEXCEPT override;

		virtual void Add(const __TYPE& value) C4STL_NOEXCEPT override;
		virtual void Remove(const __TYPE& value) C4STL_NOEXCEPT override;
		virtual void RemoveAll(const __TYPE& value) C4STL_NOEXCEPT override;

		virtual void Insert(const __TYPE& value, size_t index) C4STL_NOEXCEPT override;

	private:

		struct ListNode
		{
            __TYPE value;
			ListNode* next = nullptr;
		};

		ListNode* m_Head;
		size_t m_Size = 0;
	};

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif