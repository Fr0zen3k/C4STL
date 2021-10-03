#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_DOUBLE_LINKED_LIST_H
#define C4STL_DOUBLE_LINKED_LIST_H

#include <cstdint>

#include "C4STL/Core/Core.h"
#include "List.h"

namespace C4STL
{
    template<typename __TYPE>
    class C4STL_PUBLIC_API DoubleLinkedList : public List<__TYPE>
    {
        struct ListNode
        {
            __TYPE value;
            ListNode* previous = nullptr;
            ListNode* next = nullptr;
        };

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
            ListNode* m_Ptr;
        };

        DoubleLinkedList() C4STL_NOEXCEPT;
        virtual ~DoubleLinkedList() C4STL_NOEXCEPT;

        virtual C4STL::Iterator<__TYPE> begin() override;
        virtual C4STL::Iterator<__TYPE> end() override;

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
        ListNode* m_Head;
        ListNode* m_Tail;
        size_t m_Size = 0;

    };

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif