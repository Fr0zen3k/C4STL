#include "DynamicArray.h"

#include "C4STL/Exceptions/ArrayEmptyException.h"
#include "C4STL/Exceptions/IndexOutOfBoundsException.h"

#include <cmath>

namespace C4STL
{

	template<typename __TYPE>
	DynamicArray<__TYPE>::DynamicArray(size_t size /* = 0 */, __TYPE* data /* = nullptr */) C4STL_NOEXCEPT : m_Size(size) {
		m_RealSize = static_cast<size_t>(std::pow(2.0f, std::log2(m_Size) + 1));
		m_RealSize = m_RealSize < 2 ? 2 : m_RealSize;

		m_Data = new __TYPE[m_RealSize];

		if (data) {
			std::memcpy(m_Data, data, m_Size * sizeof(__TYPE));
		}
	}

	template<typename __TYPE>
	DynamicArray<__TYPE>::~DynamicArray() C4STL_NOEXCEPT {
		delete[] m_Data;
	}

    template<typename __TYPE>
    Iterator<__TYPE> DynamicArray<__TYPE>::begin() {
        return Iterator(m_Data);
    }

    template<typename __TYPE>
    Iterator<__TYPE> DynamicArray<__TYPE>::end() {
        return Iterator(&m_Data[m_Size]);
    }

	template<typename __TYPE>
	__TYPE* DynamicArray<__TYPE>::Data()
	{
		if(m_Size == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}
		
		return m_Data;
	}

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::Front()
	{
		if (m_Size == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}
		
		return m_Data[0];
	}

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::Back()
	{
		if (m_Size == 0)
		{
			throw ArrayEmptyException<__TYPE>(this);
		}
		
		return m_Data[m_Size - 1];
	}

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::At(size_t index)
	{
		if (index >= m_Size)
		{
			throw IndexOutOfBoundsException(index);
		}

		return m_Data[index];
	}

    template<typename __TYPE>
    void DynamicArray<__TYPE>::PushBack(const __TYPE &value) C4STL_NOEXCEPT {
        if(m_RealSize == m_Size) {
            m_RealSize *= 2;

            __TYPE* temp = new __TYPE[m_RealSize];

            memcpy(m_Data, temp, m_Size * sizeof(__TYPE));

            delete[] m_Data;
            m_Data = temp;
        }

        m_Data[m_Size++] = value;
    }

    template<typename __TYPE>
    void DynamicArray<__TYPE>::Delete(size_t index) {
        if(index > m_Size) {
            throw IndexOutOfBoundsException(index);
        }

        __TYPE var = m_Data[index];

        memcpy(&m_Data[index + 1], &m_Data[index], sizeof(__TYPE) * (m_Size - index));
    }

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::operator[](size_t index)
	{
		if(index >= m_Size)
		{
			throw IndexOutOfBoundsException(index);
		}
		
		return m_Data[index];
	}

    // *********************************** Iterator ***********************************

    template<typename __TYPE>
    DynamicArray<__TYPE>::Iterator::Iterator(__TYPE *ptr) C4STL_NOEXCEPT : C4STL::Iterator<__TYPE>(), m_Ptr(ptr) {}

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::advance(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = iterator.operator->() - m_Data;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::advance(const size_t &position) {
        m_Ptr += position * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    int32_t DynamicArray<__TYPE>::Iterator::distance(const  C4STL::Iterator<__TYPE> &iterator) {
        return iterator.operator->() - m_Ptr;
    }

    template<typename __TYPE>
    int32_t DynamicArray<__TYPE>::Iterator::distance(const size_t &position) {
        return &m_Data[position] - m_Ptr;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::previous(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr = iterator.operator->();
        m_Ptr--;
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::previous(const size_t &position) {
        // TODO: check if position == 0

        m_Ptr = &m_Data[position - 1];
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::next(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr = iterator.operator->();
        m_Ptr++;
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::next(const size_t &position) {
        m_Ptr = &m_Data[position + 1];
        return *this;
    }

    template<typename __TYPE>
    __TYPE &DynamicArray<__TYPE>::Iterator::operator*() {
        return *m_Ptr;
    }

    template<typename __TYPE>
    __TYPE *DynamicArray<__TYPE>::Iterator::operator->() {
        return m_Ptr;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator++() {
        m_Ptr++;
        return *this;
    }

    template<typename __TYPE>
    const typename DynamicArray<__TYPE>::Iterator DynamicArray<__TYPE>::Iterator::operator++(int) {
        DynamicArray<__TYPE>::Iterator temp(m_Ptr++);
        return temp;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator--() {
        m_Ptr--;
        return *this;
    }

    template<typename __TYPE>
    const typename DynamicArray<__TYPE>::Iterator DynamicArray<__TYPE>::Iterator::operator--(int) {
        DynamicArray<__TYPE>::Iterator temp(m_Ptr--);
        return temp;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator+(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = iterator.operator->() - m_Ptr;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator-(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t dif = m_Ptr - iterator.operator->();
        m_Ptr -= dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator+(const size_t &position) {
        int dif = &m_Data[position] - m_Ptr;
        m_Ptr += dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator-(const size_t &position) {
        int32_t dif = m_Ptr - &m_Data[position];
        m_Ptr -= dif * sizeof(__TYPE);
        return *this;
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator+=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator+(iterator);
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator+=(const size_t &position) {
        return operator+(position);
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator-=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator-(iterator);
    }

    template<typename __TYPE>
    typename DynamicArray<__TYPE>::Iterator &DynamicArray<__TYPE>::Iterator::operator-=(const size_t &position) {
        return operator-(position);
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator<(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr < iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator<(const size_t &position) {
        return m_Ptr < &m_Data[position];
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator>(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr > iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator>(const size_t &position) {
        return m_Ptr > &m_Data[position];
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator<=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr <= iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator<=(const size_t &position) {
        return m_Ptr <= &m_Data[position];
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator>=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr >= iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator>=(const size_t &position) {
        return m_Ptr >= &m_Data[position];
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator==(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr == iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator==(const size_t &position) {
        return m_Ptr == &m_Data[position];
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator!=(const C4STL::Iterator<__TYPE> &iterator) {
        return m_Ptr != iterator.operator->();
    }

    template<typename __TYPE>
    bool DynamicArray<__TYPE>::Iterator::operator!=(const size_t &position) {
        return m_Ptr != &m_Data[position];
    }


}