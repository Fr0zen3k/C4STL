#include "Array.h"

namespace C4STL
{

	template<typename __TYPE, size_t __SIZE>
	Array<__TYPE, __SIZE>::Array() C4STL_NOEXCEPT(__SIZE != 0)
	{
		for(size_t i = 0; i < __SIZE; i++)
		{
			m_Data[i] = __TYPE();
		}
	}

	template<typename __TYPE, size_t __SIZE>
	Array<__TYPE, __SIZE>::Array(const __TYPE* const dataArray) C4STL_NOEXCEPT(__SIZE != 0)
	{
		for (size_t i = 0; i < __SIZE; i++)
		{
			m_Data[i] = dataArray[i];
		}
	}

	template<typename __TYPE, size_t __SIZE>
	Array<__TYPE, __SIZE>::Array(const __TYPE& data) C4STL_NOEXCEPT(__SIZE != 0)
	{
		for (size_t i = 0; i < __SIZE; i++)
		{
			m_Data[i] = data;
		}
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE* Array<__TYPE, __SIZE>::Data() C4STL_NOEXCEPT(__SIZE != 0)
	{
		return m_Data;
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& Array<__TYPE, __SIZE>::Front() C4STL_NOEXCEPT(__SIZE != 0)
	{
		return m_Data[0];
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& Array<__TYPE, __SIZE>::Back() C4STL_NOEXCEPT(__SIZE != 0)
	{
		return m_Data[__SIZE - 1];
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& Array<__TYPE, __SIZE>::At(size_t index) C4STL_NOEXCEPT(index < __SIZE && __SIZE > 0)
	{
		return m_Data[index];
	}

	template<typename __TYPE, size_t __SIZE>
	__TYPE& Array<__TYPE, __SIZE>::operator[] (size_t index) C4STL_NOEXCEPT(index < __SIZE && __SIZE > 0) {
	
		return m_Data[index];
	}
}