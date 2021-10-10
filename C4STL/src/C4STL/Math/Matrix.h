//
// Created by jankr on 10-Oct-21.
//

#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_MATRIX_H
#define C4STL_MATRIX_H

#include "C4STL/Core/Core.h"
#include "Vector.h"

namespace C4STL {

    template<typename __TYPE, size_t __ROWS, size_t __COLUMNS>
    class C4STL_PUBLIC_API Matrix {
    public:
        Matrix() C4STL_NOEXCEPT;
        virtual ~Matrix() C4STL_NOEXCEPT;

        C4STL_NODISCARD inline size_t Rows() C4STL_NOEXCEPT { return __ROWS; }
        C4STL_NODISCARD inline size_t Columns() C4STL_NOEXCEPT { return __COLUMNS; }

        __TYPE Determinant() C4STL_NOEXCEPT(__ROWS == __COLUMNS);

        void Inverse();
        void Transpose();

        inline Vector<__TYPE, __ROWS>& operator [] (size_t index) { return m_Vectors[index]; }

    private:
        Vector<__TYPE, __ROWS> m_Vectors*;

    };

}


#endif //C4STL_VECTOR_H


#if defined (_MSC_VER)
#pragma warning(pop)
#endif