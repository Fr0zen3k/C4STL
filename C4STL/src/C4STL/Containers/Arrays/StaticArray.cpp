#include "StaticArray.h"

namespace C4STL
{

	template<typename __TYPE, size_t __SIZE>
	StaticArray<__TYPE, __SIZE>::StaticArray() C4STL_NOEXCEPT {}

	template<typename __TYPE, size_t __SIZE>
	StaticArray<__TYPE, __SIZE>::~StaticArray() C4STL_NOEXCEPT {}

	template<typename __TYPE, size_t __SIZE>
	__TYPE* StaticArray<__TYPE, __SIZE>::Data() C4STL_NOEXCEPT { return m_Data; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::Front() C4STL_NOEXCEPT { m_Data[0]; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::Back() C4STL_NOEXCEPT { m_Data[__SIZE - 1]; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::At(size_t index) C4STL_NOEXCEPT { return m_Data[index]; }

	template<typename __TYPE, size_t __SIZE>
	__TYPE& StaticArray<__TYPE, __SIZE>::operator[](size_t index) C4STL_NOEXCEPT { return m_Data[index]; }

}