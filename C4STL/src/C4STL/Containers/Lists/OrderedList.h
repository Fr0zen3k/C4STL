#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ORDERED_LIST_H
#define C4STL_ORDERED_LIST_H

#include "C4STL/Core/Core.h"
#include "DoubleLinkedList.h"

namespace C4STL
{
    template<typename __TYPE>
    class C4STL_PUBLIC_API OrderedList : public DoubleLinkedList<__TYPE> {
    public:
        OrderedList() C4STL_NOEXCEPT;
        virtual ~OrderedList() C4STL_NOEXCEPT override;

        virtual void Add(const __TYPE& value) C4STL_NOEXCEPT override;

        virtual void Insert(const __TYPE& value, size_t index) C4STL_NOEXCEPT override;

    };
}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif