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

}