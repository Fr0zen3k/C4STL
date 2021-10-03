#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_STATIC_ARRAY_H
#define C4STL_STATIC_ARRAY_H

#include <cstdint>

#include "C4STL/Core/Core.h"
#include "Array.h"
#include "C4STL/Containers/Iterators/Iterable.h"
#include "C4STL/Containers/Iterators/Iterator.h"

namespace C4STL
{

	template<typename __TYPE, size_t __SIZE>
	class C4STL_PUBLIC_API StaticArray : public Array<__TYPE> {
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

		StaticArray();
		virtual ~StaticArray() C4STL_NOEXCEPT override;

        virtual C4STL::Iterator<__TYPE> begin();
        virtual C4STL::Iterator<__TYPE> end();

		inline virtual size_t Size() const C4STL_NOEXCEPT override { return __SIZE; };

		virtual __TYPE* Data() override;
		
		virtual __TYPE& Front() override;
		virtual __TYPE& Back() override;
		virtual __TYPE& At(size_t index) override;

		virtual __TYPE& operator [] (size_t index) override;

	private:
		__TYPE m_Data[__SIZE];
	};

};

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif