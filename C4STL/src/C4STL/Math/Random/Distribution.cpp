#include "Distribution.h"

namespace C4STL
{
	namespace Random
	{
		// :::::::::::::::::::::::::::::: UNIFORM DISTRIBUTION :::::::::::::::::::::::::::::::

		UniformDistribution::UniformDistribution(int32_t lower, int32_t upper) C4STL_NOEXCEPT
		{
			
		}

		UniformDistribution::~UniformDistribution() C4STL_NOEXCEPT
		{
			
		}

		int32_t UniformDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0;
		}

		float UniformDistribution::Probability(int32_t x) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: BINOMIAL DISTRIBUTION :::::::::::::::::::::::::::::::::

		BinomialDistribution::BinomialDistribution(int32_t n, float probability) C4STL_NOEXCEPT
		{
			
		}

		BinomialDistribution::~BinomialDistribution() C4STL_NOEXCEPT
		{
			
		}

		int32_t BinomialDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0;
		}

		float BinomialDistribution::Probability(int32_t occurences) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: POISSON DISTRIBUTION ::::::::::::::::::::::::::::::::::

		PoissonDistribution::PoissonDistribution(float lambda) C4STL_NOEXCEPT
		{
			
		}

		PoissonDistribution::~PoissonDistribution() C4STL_NOEXCEPT
		{
			
		}

		int32_t PoissonDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0;
		}

		float PoissonDistribution::Probability(int32_t occurences) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: EXPONENTIAL DISTRIBUTION ::::::::::::::::::::::::::::::

		ExponentialDistribution::ExponentialDistribution(float lambda) C4STL_NOEXCEPT
		{
			
		}

		ExponentialDistribution::~ExponentialDistribution() C4STL_NOEXCEPT
		{
			
		}

		float ExponentialDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0.0f;
		}

		float ExponentialDistribution::Probability(float x) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: NORMAL DISTRIBUTION :::::::::::::::::::::::::::::::::::

		NormalDistribution::NormalDistribution(float mean, float stdDeviation) C4STL_NOEXCEPT
		{
			
		}

		NormalDistribution::~NormalDistribution() C4STL_NOEXCEPT
		{
			
		}

		float NormalDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0.0f;
		}

		float NormalDistribution::Probability(float x) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: STUDENT DISTRIBUTION ::::::::::::::::::::::::::::::::::

		StudentDistribution::StudentDistribution(float mean, float stdDeviation, uint32_t sampleSize) C4STL_NOEXCEPT
		{
			
		}

		StudentDistribution::~StudentDistribution() C4STL_NOEXCEPT
		{
			
		}

		float StudentDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0.0f;
		}

		float StudentDistribution::Probability(float x) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: BERNOULLI DISTRIBUTION ::::::::::::::::::::::::::::::::

		BernoulliDistribution::BernoulliDistribution(float probability) C4STL_NOEXCEPT
		{
			
		}

		BernoulliDistribution::~BernoulliDistribution() C4STL_NOEXCEPT
		{
			
		}

		uint32_t BernoulliDistribution::Random() const C4STL_NOEXCEPT
		{
			return 0;
		}

		float BernoulliDistribution::Probability(uint32_t x) const C4STL_NOEXCEPT
		{
			return 0.0f;
		}



		// :::::::::::::::::::::::::::::: CHI-SQUARED DISTRIBUTION ::::::::::::::::::::::::::::::

		ChiSquaredDistribution::ChiSquaredDistribution(float mean, float stdDeviation, uint32_t k) noexcept
		{
			
		}

		ChiSquaredDistribution::~ChiSquaredDistribution() noexcept
		{
			
		}

		float ChiSquaredDistribution::Random() const noexcept
		{
			return 0.0f;
		}

		float ChiSquaredDistribution::Probability(float x) const noexcept
		{
			return 0.0f;
		}

	}

}
