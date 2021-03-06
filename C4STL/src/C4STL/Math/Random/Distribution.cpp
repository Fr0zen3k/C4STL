#include "Distribution.h"

#include <cmath>


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

        float UniformDistribution::GetPDF(int32_t value) const C4STL_NOEXCEPT {
            return 1.0f / (m_Delta - 1);
        }

        float UniformDistribution::GetCDF(int32_t value) const C4STL_NOEXCEPT {

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

        float BinomialDistribution::GetPDF(int32_t value) const C4STL_NOEXCEPT {
            return BinomialCoefficient(m_NumberOfTrys, value) * pow(m_Probability, value) * pow(1.0f - m_Probability, m_NumberOfTrys - value);
        }

        float BinomialDistribution::GetCDF(int32_t value) const C4STL_NOEXCEPT {

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

        float PoissonDistribution::GetPDF(int32_t value) const C4STL_NOEXCEPT {
            return pow(m_Lambda, value) * exp(-m_Lambda) / tgamma(value + 1);
        }

        float PoissonDistribution::GetCDF(int32_t value) const C4STL_NOEXCEPT {

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

        float ExponentialDistribution::GetPDF(float value) const C4STL_NOEXCEPT {
            return m_Lambda * exp(-1.0f * m_Lambda * value);
        }

        float ExponentialDistribution::GetCDF(float value) const C4STL_NOEXCEPT {
            return 1.0f - exp(-1.0f * m_Lambda * value);
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

        float NormalDistribution::GetPDF(float value) const C4STL_NOEXCEPT {
            return exp(-0.5f * pow((value - m_Mean) / m_StandardDeviation, 2)) / (m_StandardDeviation * sqrt(2.0f * M_PI));
        }

        float NormalDistribution::GetCDF(float value) const C4STL_NOEXCEPT {

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

        float StudentDistribution::GetPDF(float value) const C4STL_NOEXCEPT {

        }

        float StudentDistribution::GetCDF(float value) const C4STL_NOEXCEPT {

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

        float BernoulliDistribution::GetPDF(uint32_t value) const C4STL_NOEXCEPT {

        }

        float BernoulliDistribution::GetCDF(uint32_t value) const C4STL_NOEXCEPT {

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

        float ChiSquaredDistribution::GetPDF(float value) const C4STL_NOEXCEPT {

        }

        float ChiSquaredDistribution::GetCDF(float value) const C4STL_NOEXCEPT {

        }

	}

}
