#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_LIST_H
#define C4STL_LIST_H

#include "C4STL/Core/Core.h"
#include "C4STL/Containers/Iterators/Iterable.h"
#include "C4STL/Containers/Iterators/Iterator.h"

namespace C4STL
{
	template<typename __TYPE>
	class C4STL_PUBLIC_API List : public Iterable<__TYPE>
	{
	public:
        virtual Iterator<__TYPE> begin() override = 0;
        virtual Iterator<__TYPE> end() override = 0;

		virtual __TYPE& Head() C4STL_NOEXCEPT = 0;
		virtual __TYPE& Tail() C4STL_NOEXCEPT = 0;
		virtual size_t Size() const C4STL_NOEXCEPT = 0;
		virtual __TYPE& Next(const __TYPE& value) C4STL_NOEXCEPT = 0;
		virtual __TYPE& Previous(const __TYPE& value) C4STL_NOEXCEPT = 0;

		virtual void Add(const __TYPE& value) C4STL_NOEXCEPT = 0;
		virtual void Remove(const __TYPE& value) C4STL_NOEXCEPT = 0;
		virtual void RemoveAll(const __TYPE& value) C4STL_NOEXCEPT = 0;

		virtual void Insert(const __TYPE& value, size_t index) C4STL_NOEXCEPT = 0;
	};
	
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif