#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ARRAY_H
#define C4STL_ARRAY_H

#include "C4STL/Core/Core.h"
#include "C4STL/Containers/Iterators/Iterable.h"
#include "C4STL/Containers/Iterators/Iterator.h"

namespace C4STL {

	template<typename __TYPE>
    class C4STL_PUBLIC_API Array : public Iterable<__TYPE> {
	public:
		virtual ~Array() C4STL_NOEXCEPT {};

        virtual Iterator<__TYPE> begin() = 0;
        virtual Iterator<__TYPE> end() = 0;

		virtual size_t Size() const C4STL_NOEXCEPT = 0;
		
		virtual __TYPE* Data() = 0;

		virtual __TYPE& Front() = 0;
		virtual __TYPE& Back() = 0;
		virtual __TYPE& At(size_t index) = 0;

		virtual __TYPE& operator [] (size_t index) = 0;
	};

}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif