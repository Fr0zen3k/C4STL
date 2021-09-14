#include "DynamicArray.h"

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
	__TYPE* DynamicArray<__TYPE>::Data() C4STL_NOEXCEPT { return m_Data; }

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::Front() C4STL_NOEXCEPT { return m_Data[0]; }

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::Back() C4STL_NOEXCEPT { return m_Data[m_Size - 1]; }

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::At(size_t index) C4STL_NOEXCEPT { return m_Data[index]; }

	template<typename __TYPE>
	__TYPE& DynamicArray<__TYPE>::operator[](size_t index) C4STL_NOEXCEPT { return m_Data[index]; }
}