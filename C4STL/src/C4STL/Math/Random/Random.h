#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_RANDOM_H
#define C4STL_RANDOM_H

#include "C4STL/Core/Core.h"

#include <ctime>
#include <cstdint>

namespace C4STL
{
	namespace Random {
		class C4STL_PUBLIC_API RandomGenerator
		{
		public:
			RandomGenerator(uint32_t seed = static_cast<uint32_t>(time(NULL))) C4STL_NOEXCEPT;
			virtual ~RandomGenerator() C4STL_NOEXCEPT;

			uint32_t Random() C4STL_NOEXCEPT;

			static inline uint32_t Minimum() C4STL_NOEXCEPT { return 0; }
			static inline uint32_t Maximum() C4STL_NOEXCEPT { return 0xFFFFFFFF; }

			void Reseed(uint32_t seed = static_cast<uint32_t>(time(NULL))) C4STL_NOEXCEPT;

		private:
			uint32_t m_CurrentSeed;
		};
	}
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif