#include "Queue.h"
#include "C4STL/Exceptions/QueueEmptyException.h"

namespace C4STL {

	template<typename __TYPE>
	Queue<__TYPE>::Queue() C4STL_NOEXCEPT {
		m_Data = new __TYPE[m_BufferSize];
	}

	template<typename __TYPE>
	Queue<__TYPE>::~Queue() C4STL_NOEXCEPT {
		delete m_Data;
	}

	template<typename __TYPE>
	size_t Queue<__TYPE>::Size() const C4STL_NOEXCEPT {
		return m_First <= m_Last ? m_Last - m_First - 1 : m_Last + m_BufferSize - m_First - 1;
	}

	template<typename __TYPE>
	void Queue<__TYPE>::Push(const __TYPE& value) C4STL_NOEXCEPT {
		if (Size() == m_BufferSize - 1) {
			m_BufferSize *= 2;
			
			__TYPE* temp = new __TYPE[m_BufferSize];
			memcpy(temp, m_Data, sizeof(__TYPE) * m_BufferSize / 2);
			delete[] m_Data;
			m_Data = temp;

			m_Last += m_BufferSize / 2;
		}

		m_Data[m_Last++] = value;

		m_Last %= m_BufferSize;
	}

	template<typename __TYPE>
	__TYPE Queue<__TYPE>::Pop() const {
		if(Empty())
		{
			throw QueueEmptyException<__TYPE>(this);
		}
		
		size_t index = m_First++;
		m_First %= m_BufferSize;
		return m_Data[index];
	}

	template<typename __TYPE>
	__TYPE& Queue<__TYPE>::Peek() {
		if(Empty())
		{
			throw QueueEmptyException<__TYPE>(this);
		}
		
		return m_Data[m_First];
	}

}