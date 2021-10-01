#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_DYNAMIC_ARRAY_H
#define C4STL_DYNAMIC_ARRAY_H

#include <cstdint>

#include "C4STL/Core/Core.h"
#include "Array.h"

namespace C4STL
{

	template<typename __TYPE>
	class DynamicArray : public Array<__TYPE> {
	public:
        class C4STL_PUBLIC_API Iterator : public C4STL::Iterator<__TYPE> {
        public:
            Iterator(__TYPE* ptr = nullptr) C4STL_NOEXCEPT;

            virtual Iterator& advance(const Iterator& iterator) override;
            virtual Iterator& advance(const size_t& position) override;

            virtual int32_t distance(const Iterator& iterator) override;
            virtual int32_t distance(const size_t& position) override;

            virtual Iterator& previous(const Iterator& iterator) override;
            virtual Iterator& previous(const size_t& position) override;

            virtual Iterator& next(const Iterator& iterator) override;
            virtual Iterator& next(const size_t& position) override;

            virtual __TYPE& operator * () override;
            virtual __TYPE* operator -> () override;

            virtual Iterator& operator ++ () override;
            virtual Iterator& operator ++ (int) override;
            virtual Iterator& operator -- () override;
            virtual Iterator& operator -- (int) override;

            virtual Iterator& operator + (const Iterator& iterator) override;
            virtual Iterator& operator - (const Iterator& iterator) override;
            virtual Iterator& operator + (const size_t& position) override;
            virtual Iterator& operator - (const size_t& position) override;

            virtual Iterator& operator += (const Iterator& iterator) override;
            virtual Iterator& operator += (const size_t& position) override;
            virtual Iterator& operator -= (const Iterator& iterator) override;
            virtual Iterator& operator -= (const size_t& position) override;

            virtual bool operator < (const Iterator& iterator) override;
            virtual bool operator < (const size_t& position) override;
            virtual bool operator > (const Iterator& iterator) override;
            virtual bool operator > (const size_t& position) override;
            virtual bool operator <= (const Iterator& iterator) override;
            virtual bool operator <= (const size_t& position) override;
            virtual bool operator >= (const Iterator& iterator) override;
            virtual bool operator >= (const size_t& position) override;
            virtual bool operator == (const Iterator& iterator) override;
            virtual bool operator == (const size_t& position) override;
            virtual bool operator != (const Iterator& iterator) override;
            virtual bool operator != (const size_t& position) override;

        private:
            __TYPE* m_Ptr;
        };

		DynamicArray(size_t size = 0, __TYPE* data = nullptr) C4STL_NOEXCEPT;
		virtual ~DynamicArray() C4STL_NOEXCEPT override;

        virtual Iterator begin() override;
        virtual Iterator end() override;

		inline virtual size_t Size() const C4STL_NOEXCEPT { return m_Size; }

		virtual __TYPE* Data() override;

		virtual __TYPE& Front() override;
		virtual __TYPE& Back() override;
		virtual __TYPE& At(size_t index) override;

        void PushBack(const __TYPE& value) C4STL_NOEXCEPT;

        void Delete(size_t index);

		virtual __TYPE& operator [] (size_t index) override;

	private:
		__TYPE* m_Data;

		size_t m_Size = 0;
		size_t m_RealSize = 2;
	};

}


#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif