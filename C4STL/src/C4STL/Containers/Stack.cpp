#include "Stack.h"

namespace C4STL {

	template<typename __TYPE>
	Stack<__TYPE>::Stack() C4STL_NOEXCEPT {
		m_Data = new __TYPE[m_BufferSize];
	}

	template<typename __TYPE>
	Stack<__TYPE>::~Stack() C4STL_NOEXCEPT {
		delete[] m_Data;
	}

	template<typename __TYPE>
	void Stack<__TYPE>::Push(const __TYPE& value) C4STL_NOEXCEPT {
		if (m_Last == m_BufferSize) {
			m_BufferSize *= 2;

			__TYPE* temp = new __TYPE[m_BufferSize];
			memcpy(temp, m_Data, m_Last * sizeof(__TYPE));
			delete[] m_Data;
			m_Data = temp;
		}

		m_Data[m_Last++] = value;
	}

	template<typename __TYPE>
	__TYPE Stack<__TYPE>::Pull() const C4STL_NOEXCEPT {
		// Add size checking
		return m_Data[m_Last - 1];
	}

	template<typename __TYPE>
	__TYPE& Stack<__TYPE>::Peek() C4STL_NOEXCEPT {
		// Add size checking
		return m_Data[m_Last - 1];
	}

	template<typename __TYPE>
	bool Stack<__TYPE>::Empty() C4STL_NOEXCEPT { return m_Last == 0; }

}