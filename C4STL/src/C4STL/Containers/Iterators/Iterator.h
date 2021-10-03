//
// Created by jankr on 01-Oct-21.
//

#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ITERATOR_H
#define C4STL_ITERATOR_H

#include "C4STL/Core/Core.h"

namespace C4STL {

    /**
     *  *()
     *  ->
     *  ++
     *  ++(int)
     *  --
     *  --(int)
     *  ==
     *  !=
     *  + / - (between two iterators and between an iterator and a number)
     * @tparam __TYPE
     */

    template<typename __TYPE>
    class C4STL_PUBLIC_API Iterator {
    public:
        Iterator() C4STL_NOEXCEPT = default;

        virtual Iterator<__TYPE>& advance(const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& advance(const size_t& position) = 0;

        virtual int32_t distance(const Iterator<__TYPE>& iterator) = 0;
        virtual int32_t distance(const size_t& position) = 0;

        virtual Iterator<__TYPE>& previous(const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& previous(const size_t& position) = 0;

        virtual Iterator<__TYPE>& next(const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& next(const size_t& position) = 0;

        virtual __TYPE& operator * () = 0;
        virtual __TYPE* operator -> () = 0;

        virtual Iterator<__TYPE>& operator ++ () = 0;
        virtual const Iterator<__TYPE> operator ++ (int) = 0;
        virtual Iterator<__TYPE>& operator -- () = 0;
        virtual const Iterator<__TYPE> operator -- (int) = 0;

        virtual Iterator<__TYPE>& operator + (const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& operator - (const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& operator + (const size_t& position) = 0;
        virtual Iterator<__TYPE>& operator - (const size_t& position) = 0;

        virtual Iterator<__TYPE>& operator += (const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& operator += (const size_t& position) = 0;
        virtual Iterator<__TYPE>& operator -= (const Iterator<__TYPE>& iterator) = 0;
        virtual Iterator<__TYPE>& operator -= (const size_t& position) = 0;

        virtual bool operator < (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator < (const size_t& position) = 0;
        virtual bool operator > (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator > (const size_t& position) = 0;
        virtual bool operator <= (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator <= (const size_t& position) = 0;
        virtual bool operator >= (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator >= (const size_t& position) = 0;
        virtual bool operator == (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator == (const size_t& position) = 0;
        virtual bool operator != (const Iterator<__TYPE>& iterator) = 0;
        virtual bool operator != (const size_t& position) = 0;
    };

}

#endif //C4STL_ITERATOR_H

#if defined (_MSC_VER)
#pragma warning(pop)
#endif
