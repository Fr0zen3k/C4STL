//
// Created by jankr on 01-Oct-21.
//

#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_ITERABLE_H
#define C4STL_ITERABLE_H

#include "C4STL/Core/Core.h"
#include "Iterator.h"

namespace C4STL {

    template<typename __TYPE>
    class C4STL_PUBLIC_API Iterable {
    public:
        virtual Iterator<__TYPE> begin() = 0;
        virtual Iterator<__TYPE> end() = 0;

    };

}

#endif //C4STL_ITERABLE_H

#if defined (_MSC_VER)
#pragma warning(pop)
#endif
