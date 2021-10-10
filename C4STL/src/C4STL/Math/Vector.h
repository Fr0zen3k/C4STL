//
// Created by jankr on 10-Oct-21.
//

#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_VECTOR_H
#define C4STL_VECTOR_H

#include "C4STL/Core/Core.h"

namespace C4STL {

    template<typename __TYPE, size_t __SIZE>
    class C4STL_PUBLIC_API Vector {
    public:
        Vector() C4SLT_NOEXCEPT;
        virtual ~Vector() C4STL_NOEXCEPT;

        inline __TYPE* Data() C4STL_NOEXCEPT { return m_Data; }

        C4STL_NODISCARD inline size_t Size() C4STL_NOEXCEPT { return __SIZE; }

        void Normalize();
        __TYPE Module();
        __TYPE Length();
        __TYPE Magnitude();

        __TYPE& operator [] (size_t index);

    private:
        __TYPE m_Data[__SIZE];
    };

}


#endif //C4STL_VECTOR_H


#if defined (_MSC_VER)
#pragma warning(pop)
#endif