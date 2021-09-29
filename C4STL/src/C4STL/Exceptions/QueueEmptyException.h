#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_QUEUE_EMPTY_EXCEPTION_H
#define C4STL_QUEUE_EMPTY_EXCEPTION_H

#include "C4STL/Core/Core.h"
#include "Exception.h"
#include "C4STL/Containers/Queue.h"

namespace C4STL
{

	template<typename __TYPE>
	class QueueEmptyException : public Exception<Queue<__TYPE>*>
	{
	public:
		QueueEmptyException(const std::string& errorMessage = "Queue empty exception.", const Queue<__TYPE>* const queue = nullptr) C4STL_NOEXCEPT;
		QueueEmptyException(const Queue<__TYPE>* const queue) C4STL_NOEXCEPT;
		virtual ~QueueEmptyException() C4STL_NOEXCEPT override;

		virtual const Queue<__TYPE>* const GetCause() C4STL_NOEXCEPT override;

	private:
		const Queue<__TYPE>* const m_Cause;
	};

}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif