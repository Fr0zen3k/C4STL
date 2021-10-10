#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_MATH_H
#define C4STL_MATH_H

#include <cstdint>

#include "C4STL/Core/Core.h"

namespace C4STL
{
	namespace Random
	{
		enum class DistributionType
		{
			UNIFORM				= 0,
			BINOMIAL			= 1,
			POISSON				= 2,
			EXPONENTIAL			= 3,
			NORMAL				= 4,
			STUDENT				= 5,
			BERNOULLI			= 6,
			CHI_SQUARED			= 7,
			UNKNOWN				= 8
		};

		enum class DistributionClass
		{
			DISCRETE			= 0,
			CONTINOUS			= 1,
			UNKNOWN				= 2,
			VARIABLE			= 3
		};

		template<typename __TYPE>
		class C4STL_PUBLIC_API Distribution
		{
		public:
			inline static DistributionType GetStaticType() C4STL_NOEXCEPT  { return DistributionType::UNKNOWN; }
			inline static DistributionClass GetStaticClass() C4STL_NOEXCEPT { return DistributionClass::UNKNOWN; }

			virtual DistributionType GetType() const C4STL_NOEXCEPT = 0;
			virtual DistributionClass GetClass() const C4STL_NOEXCEPT = 0;

			virtual __TYPE Random() const C4STL_NOEXCEPT = 0;
			virtual float Probability(__TYPE value) const C4STL_NOEXCEPT = 0;

            virtual float GetPDF(__TYPE value) const C4STL_NOEXCEPT = 0;
            virtual float GetCDF(__TYPE value) const C4STL_NOEXCEPT = 0;
		};

#define C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(distribution, classification)													\
inline static DistributionType GetStaticType() C4STL_NOEXCEPT { return DistributionType::distribution; }						\
inline static DistributionClass GetStaticClass() C4STL_NOEXCEPT { return DistributionClass::classification; }					\
inline virtual DistributionType GetType() const C4STL_NOEXCEPT override { return GetStaticType(); }								\
inline virtual DistributionClass GetClass() const C4STL_NOEXCEPT override { return GetStaticClass(); }

		class C4STL_PUBLIC_API UniformDistribution : public Distribution<int32_t>
		{
		public:
			UniformDistribution(int32_t lower, int32_t upper) C4STL_NOEXCEPT;
			virtual ~UniformDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(UNIFORM, DISCRETE)

			virtual int32_t Random() const C4STL_NOEXCEPT override;
			virtual float Probability(int32_t x) const C4STL_NOEXCEPT override;

            virtual float GetPDF(int32_t value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(int32_t value) const C4STL_NOEXCEPT override;

		private:
			int m_Lower;
			int m_Delta;
		};

		class C4STL_PUBLIC_API BinomialDistribution : public Distribution<int32_t>
		{
		public:
			BinomialDistribution(int32_t n, float probability) C4STL_NOEXCEPT;
			virtual ~BinomialDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(BINOMIAL, DISCRETE)

			virtual int32_t Random() const C4STL_NOEXCEPT override;
			virtual float Probability(int32_t occurences) const C4STL_NOEXCEPT override;

            virtual float GetPDF(int32_t value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(int32_t value) const C4STL_NOEXCEPT override;

        private:
            inline static uint32_t BinomialCoefficient(uint32_t n, uint32_t k) C4STL_NOEXCEPT {
                double res = 1.0;

                for(uint32_t i = 0; i <= k; i++) {
                    res = res * (n - k + i) / i;
                }

                return static_cast<uint32_t>(res + 0.01);
            }

		private:
			int m_NumberOfTrys;
			float m_Probability;
		};

		class C4STL_PUBLIC_API PoissonDistribution : public Distribution<int32_t>
		{
		public:
			PoissonDistribution(float lambda) C4STL_NOEXCEPT;
			virtual ~PoissonDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(POISSON, DISCRETE)

			virtual int32_t Random() const C4STL_NOEXCEPT override;
			virtual float Probability(int32_t occurences) const C4STL_NOEXCEPT override;

            virtual float GetPDF(int32_t value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(int32_t value) const C4STL_NOEXCEPT override;

		private:
			float m_Lambda;
		};

		class C4STL_PUBLIC_API ExponentialDistribution : public Distribution<float>
		{
		public:
			ExponentialDistribution(float lambda) C4STL_NOEXCEPT;
			virtual ~ExponentialDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(EXPONENTIAL, CONTINOUS)

			virtual float Random() const C4STL_NOEXCEPT override;
			virtual float Probability(float x) const C4STL_NOEXCEPT override;

            virtual float GetPDF(float value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(float value) const C4STL_NOEXCEPT override;

		private:
			float m_Lambda;
		};

		class C4STL_PUBLIC_API NormalDistribution : public Distribution<float>
		{
		public:
			NormalDistribution(float mean, float stdDeviation) C4STL_NOEXCEPT;
			virtual ~NormalDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(NORMAL, CONTINOUS)

			virtual float Random() const C4STL_NOEXCEPT override;
			virtual float Probability(float x) const C4STL_NOEXCEPT override;

            virtual float GetPDF(float value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(float value) const C4STL_NOEXCEPT override;

		private:
			float m_Mean;
			float m_StandardDeviation;
		};

		class C4STL_PUBLIC_API StudentDistribution : public Distribution<float>
		{
		public:
			StudentDistribution(float mean, float stdDeviation, uint32_t sampleSize) C4STL_NOEXCEPT;
			virtual ~StudentDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(STUDENT, CONTINOUS)

			virtual float Random() const C4STL_NOEXCEPT override;
			virtual float Probability(float x) const C4STL_NOEXCEPT override;

            virtual float GetPDF(float value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(float value) const C4STL_NOEXCEPT override;

		private:
			float m_Mean;
			float m_StandardDeviation;
			int m_SampleSize;
		};

		class C4STL_PUBLIC_API BernoulliDistribution : public Distribution<uint32_t>
		{
		public:
			BernoulliDistribution(float probability = 0.5f) C4STL_NOEXCEPT;
			virtual ~BernoulliDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(BERNOULLI, DISCRETE)

			virtual uint32_t Random() const C4STL_NOEXCEPT override;
			virtual float Probability(uint32_t x = 1) const C4STL_NOEXCEPT override;

            virtual float GetPDF(uint32_t value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(uint32_t value) const C4STL_NOEXCEPT override;

		private:
			float m_Probability;
		};

		class C4STL_PUBLIC_API ChiSquaredDistribution : public Distribution<float>
		{
		public:
			ChiSquaredDistribution(float mean, float stdDeviation, uint32_t k) C4STL_NOEXCEPT;
			virtual ~ChiSquaredDistribution() C4STL_NOEXCEPT;

			C4STL_DEFINE_DISTRIBUTION_CLASSIFICATION(CHI_SQUARED, CONTINOUS)

			virtual float Random() const C4STL_NOEXCEPT override;
			virtual float Probability(float x) const C4STL_NOEXCEPT override;

            virtual float GetPDF(float value) const C4STL_NOEXCEPT override;
            virtual float GetCDF(float value) const C4STL_NOEXCEPT override;

		private:
			float m_Mean;
			float m_StandardDeviation;
			uint32_t m_DegOfFreedom;
		};
	}
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif