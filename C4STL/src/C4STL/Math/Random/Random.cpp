#include "Random.h"

#include <cmath>

namespace C4STL
{
	namespace Random
	{
		// TODO: Check for power of two in the seed
		RandomGenerator::RandomGenerator(uint32_t seed) C4STL_NOEXCEPT : m_CurrentSeed(seed) {}

		RandomGenerator::~RandomGenerator() C4STL_NOEXCEPT {}

		uint32_t RandomGenerator::Random() C4STL_NOEXCEPT {
			uint32_t rand = 0;
			
			for(uint8_t i = 0; i < 32; i++)
			{
				if(m_CurrentSeed % 2 == 0)
				{
					m_CurrentSeed /= 2;
				}
				else
				{
					m_CurrentSeed = m_CurrentSeed * 3 + 1;
				}

				uint32_t bit;
				
				if(m_CurrentSeed % 2 == 0)
				{
					bit = 0x00000001;
				}
				else
				{
					bit = 0x00000000;
				}

				rand |= bit;
				rand <<= 1;
			}

			return rand;
		}
		
		void RandomGenerator::Reseed(uint32_t seed) C4STL_NOEXCEPT
		{
			// TODO: Check for power of two in the seed
			m_CurrentSeed = seed;
		}
	}
}