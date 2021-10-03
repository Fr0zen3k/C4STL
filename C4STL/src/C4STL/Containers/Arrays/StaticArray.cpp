#include "StaticArray.h"
#include "C4STL/Exceptions/ArrayEmptyException.h"
#include "C4STL/Exceptions/IndexOutOfBoundsException.h"

namespace C4STL
{
	template<typename __TYPE, size_t __SIZE>
	StaticArray<__TYPE, __SIZE>::StaticArray() {
		// TODO: Add size checking with proper exception throwing
	}

	template<typename __TYPE, size_t __SIZE>
	StaticArray<__TYPE, __SIZE>::~StaticArray() C4STL_NOEXCEPT {}

    template<typename __TYPE, size_t __SIZE>
    Iterator<__TYPE> StaticArray<__TYPE, __SIZE>::begin() {
        return Iterator(m_Data);
    }

    template<typename __TYPE, size_t __SIZE>
    Iterator<__TYPE> StaticArray<__TYPE, __SIZE>::end() {
        return Iterator(&m_Data[__SIZE]);
    }

	template<typename __TYPE, size_t __SIZE>
	__TYPE* StaticArray<__TYPE, __SIZE>::Data()
	{
		if(__SIZE == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}
		
		return m_Data;
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::Front() {
		if (__SIZE == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}

		return m_Data[0]; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::Back() {
		if (__SIZE == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}

		return m_Data[__SIZE - 1]; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::At(size_t index)
	{
		if(index >= __SIZE)
		{
			throw IndexOutOfBoundsException(index);
		}
		
		return m_Data[index];
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::operator[](size_t index) {
		if (index >= __SIZE)
		{
			throw IndexOutOfBoundsException(index);
		}

		return m_Data[index];
	}


    // *********************************** Iterator ***********************************

    template<typename __TYPE, size_t __SIZE>
    StaticArray<__TYPE, __SIZE>::Iterator::Iterator(__TYPE *ptr) C4STL_NOEXCEPT : C4STL::Iterator<__TYPE>(), m_Ptr(ptr) {}

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::advance(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = iterator.operator->() - m_Data;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::advance(const size_t &position) {
        m_Ptr += position * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    int32_t StaticArray<__TYPE, __SIZE>::Iterator::distance(const C4STL::Iterator<__TYPE> &iterator) {
        return iterator.operator->() - m_Ptr;
    }

    template<typename __TYPE, size_t __SIZE>
    int32_t StaticArray<__TYPE, __SIZE>::Iterator::distance(const size_t &position) {
        return &m_Data[position] - m_Ptr;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::previous(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr = iterator.operator->();
        m_Ptr--;
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::previous(const size_t &position) {
        // TODO: check if position == 0

        m_Ptr = &m_Data[position - 1];
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::next(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr = iterator.operator->();
        m_Ptr++;
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::next(const size_t &position) {
        m_Ptr = &m_Data[position + 1];
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    __TYPE &StaticArray<__TYPE, __SIZE>::Iterator::operator*() {
        return *m_Ptr;
    }

    template<typename __TYPE, size_t __SIZE>
    __TYPE *StaticArray<__TYPE, __SIZE>::Iterator::operator->() {
        return m_Ptr;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator++() {
        m_Ptr++;
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    const typename StaticArray<__TYPE, __SIZE>::Iterator StaticArray<__TYPE, __SIZE>::Iterator::operator++(int) {
        StaticArray<__TYPE, __SIZE>::Iterator temp(m_Ptr++);
        return temp;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator--() {
        m_Ptr--;
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    const typename StaticArray<__TYPE, __SIZE>::Iterator StaticArray<__TYPE, __SIZE>::Iterator::operator--(int) {
        StaticArray<__TYPE, __SIZE>::Iterator temp(m_Ptr--);
        return temp;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator+(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = iterator.operator->() - m_Ptr;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator-(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = m_Ptr - iterator.operator->();
        m_Ptr -= dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator+(const size_t &position) {
        int dif = &m_Data[position] - m_Ptr;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator-(const size_t &position) {
        int32_t dif = m_Ptr - &m_Data[position];
        m_Ptr -= dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator+=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator+(iterator);
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator+=(const size_t &position) {
        return operator+(position);
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator-=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator-(iterator);
    }

    template<typename __TYPE, size_t __SIZE>
    typename StaticArray<__TYPE, __SIZE>::Iterator &StaticArray<__TYPE, __SIZE>::Iterator::operator-=(const size_t &position) {
        return operator-(position);
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator<(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr < iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator<(const size_t &position) {
        return m_Ptr < &m_Data[position];
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator>(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr > iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator>(const size_t &position) {
        return m_Ptr > &m_Data[position];
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator<=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr <= iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator<=(const size_t &position) {
        return m_Ptr <= &m_Data[position];
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator>=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr >= iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator>=(const size_t &position) {
        return m_Ptr >= &m_Data[position];
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator==(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr == iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator==(const size_t &position) {
        return m_Ptr == &m_Data[position];
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator!=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr != iterator.operator->();
    }

    template<typename __TYPE, size_t __SIZE>
    bool StaticArray<__TYPE, __SIZE>::Iterator::operator!=(const size_t &position) {
        return m_Ptr != &m_Data[position];
    }


}