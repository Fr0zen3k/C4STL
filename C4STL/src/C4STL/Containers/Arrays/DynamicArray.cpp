#include "DynamicArray.h"

namespace C4STL
{

	template<typename __TYPE>
	DynamicArray<__TYPE>::DynamicArray(size_t size /* = 0 */, __TYPE data /* = __TYPE() */) C4STL_NOEXCEPT
	{
		
	}

	template<typename __TYPE>
	DynamicArray<__TYPE>::DynamicArray(size_t size /* = 0 */, __TYPE* dataArray /* = nullptr */) C4STL_NOEXCEPT
	{
		m_Data = new __TYPE[m_InternalSize];
	}

	template<typename __TYPE>
	DynamicArray<__TYPE>::~DynamicArray() C4STL_NOEXCEPT {
		delete[] m_Data;
	}
 
	template<typename __TYPE>
	bool DynamicArray<__TYPE>::Empty() const C4STL_NOEXCEPT
	{
		return m_Size == 0;
	}
	
}