#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_LIST_H
#define C4STL_LIST_H

#include "C4STL/Core/Core.h"
#include "C4STL/Containers/Arrays/DynamicArray.h"

namespace C4STL
{
    template<typename __TYPE>
    class C4STL_PUBLIC_API FreeList {
    public:
        FreeList() C4STL_NOEXCEPT;
        virtual ~FreeList() C4STL_NOEXCEPT;

        inline size_t Size() C4STL_NOEXCEPT { return m_Size; }

        __TYPE& Front();
        __TYPE& Back() ;
        __TYPE& At(size_t index);

        __TYPE& operator [] (size_t index);

        void AddMemoryChunk(__TYPE* memory, size_t memSize) C4STL_NOEXCEPT;

        void DeleteMemoryChunk(__TYPE* memory) C4STL_NOEXCEPT;
        void DeleteMemoryChunk(size_t index);

    private:
        DynamicArray<__TYPE*> m_Memory;
        DynamicArray<size_t> m_SizeChunks;

        size_t m_Size = 0;
    };

}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif