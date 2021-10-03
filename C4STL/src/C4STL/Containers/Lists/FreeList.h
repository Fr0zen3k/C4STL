#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_LIST_H
#define C4STL_LIST_H

#include "C4STL/Core/Core.h"
#include "C4STL/Containers/Arrays/DynamicArray.h"
#include "C4STL/Containers/Iterators/Iterable.h"
#include "C4STL/Containers/Iterators/Iterator.h"

namespace C4STL
{
    template<typename __TYPE>
    class C4STL_PUBLIC_API FreeList : public Iterable<__TYPE> {
    public:
        class C4STL_PUBLIC_API Iterator : public C4STL::Iterator<__TYPE> {
        public:
            Iterator(__TYPE* ptr = nullptr) C4STL_NOEXCEPT;

            virtual Iterator& advance(const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& advance(const size_t& position) override;

            virtual int32_t distance(const C4STL::Iterator<__TYPE>& iterator) override;
            virtual int32_t distance(const size_t& position) override;

            virtual Iterator& previous(const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& previous(const size_t& position) override;

            virtual Iterator& next(const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& next(const size_t& position) override;

            virtual __TYPE& operator * () override;
            virtual __TYPE* operator -> () override;

            virtual Iterator& operator ++ () override;
            virtual const Iterator operator ++ (int) override;
            virtual Iterator& operator -- () override;
            virtual const Iterator operator -- (int) override;

            virtual Iterator& operator + (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& operator - (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& operator + (const size_t& position) override;
            virtual Iterator& operator - (const size_t& position) override;

            virtual Iterator& operator += (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& operator += (const size_t& position) override;
            virtual Iterator& operator -= (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual Iterator& operator -= (const size_t& position) override;

            virtual bool operator < (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator < (const size_t& position) override;
            virtual bool operator > (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator > (const size_t& position) override;
            virtual bool operator <= (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator <= (const size_t& position) override;
            virtual bool operator >= (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator >= (const size_t& position) override;
            virtual bool operator == (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator == (const size_t& position) override;
            virtual bool operator != (const C4STL::Iterator<__TYPE>& iterator) override;
            virtual bool operator != (const size_t& position) override;

        private:
            __TYPE* m_Ptr;
        };

        FreeList() C4STL_NOEXCEPT;
        virtual ~FreeList() C4STL_NOEXCEPT;

        virtual C4STL::Iterator<__TYPE> begin();
        virtual C4STL::Iterator<__TYPE> end();

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