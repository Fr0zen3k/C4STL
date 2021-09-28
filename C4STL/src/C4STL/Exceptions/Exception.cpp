#include "Exception.h"

namespace C4STL {
	
	template<typename __TYPE>
	std::string Exception<__TYPE>::GetErrorMessage() const C4STL_NOEXCEPT { return m_ErrorMessage; }

	template<typename __TYPE>
	std::chrono::high_resolution_clock::time_point Exception<__TYPE>::GetThrowTime() const C4STL_NOEXCEPT { return m_ThrowTime; }

	template<typename __TYPE>
	bool Exception<__TYPE>::Handled() const C4STL_NOEXCEPT { return m_Handled; }
	
}