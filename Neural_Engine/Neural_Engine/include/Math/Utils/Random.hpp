#ifndef RANDOM_HPP_INCLUDED
#define RANDOM_HPP_INCLUDED


#define HAS_ASSERTION 1
#define HAS_ATTRIBUTES 1

#include <random>

#include "Core/Defines/Defines_Func_Attributes.hpp"
#include "Math/Algebra/Scalar.hpp"
#include "Math/Algebra/Vector.hpp"


namespace NN
{
	namespace Math
	{
		namespace Utils
		{

			template<typename T = float>
			NODISCARD constexpr NN::Math::Algebra::Scalar<T> generate_random_numberF(T min, T max)
			{
				static_assert(std::is_floating_point_v<T>, "Type of template T has to be float or double");
				std::random_device random_seed;
				std::mt19937 random_generator(random_seed());
				const std::uniform_real_distribution<T> distribution(min, max);
				return NN::Math::Algebra::Scalar<T>(distribution(random_generator));
			}
			
			//Rethink, adding everywhere Scalar<T> instead of T, or overloads for Scalar<T> and T
			template<typename T = float>
			NODISCARD constexpr NN::Math::Algebra::Vector<T> generate_random_numbersF(T min, T max, const std::size_t num)
			{
				static_assert(std::is_floating_point_v<T>, "Type of template T has to be float or double");
				std::random_device random_seed;
				std::mt19937 random_generator(random_seed());
				const std::uniform_real_distribution<T> distribution(min, max);

				auto random_values = NN::Math::Algebra::Vector<T>(num);
				auto random_floating_points = [&] { return distribution(random_generator); };
				std::generate_n(random_values.begin(), num, random_floating_points);
				return random_values;
			}


			//std::random_device random_seed;
			//std::mt19937 random_generator(random_seed());
			//const std::uniform_real_distribution<float> distribution(0.05f, 0.95f);

			//auto weights = std::unique_ptr<type[]>(new type[size]);
			//auto random_float = [&] { return distribution(random_generator); };
			//std::generate_n(weights.get(), size, random_float);
			//return weights;
			
			template<typename T = int>
			NODISCARD constexpr NN::Math::Algebra::Scalar<T> generate_random_numberI(T min, T max)
			{
				static_assert(std::is_integral_v<T>, "Type of template T has to be integer, not floating point");
				std::random_device random_seed;
				std::mt19937 random_generator(random_seed());
				const std::uniform_int_distribution<T> distribution(min, max);
				return NN::Math::Algebra::Scalar<T>(distribution(random_generator));
			}

			template<typename T = int>
			NODISCARD constexpr NN::Math::Algebra::Vector<T> generate_random_numbersI(T min, T max, const std::size_t num)
			{
				static_assert(std::is_integral_v<T>, "Type of template T has to be integer, not floating point");
				std::random_device random_seed;
				std::mt19937 random_generator(random_seed());
				const std::uniform_int_distribution<T> distribution(min, max);

				auto random_values = NN::Math::Algebra::Vector<T>(num);
				auto random_integer_points = [&] { return distribution(random_generator); };
				std::generate_n(random_values.begin(), num, random_integer_points);
				return random_values;
			}

		}
	}
}

#undef HAS_ATTRIBUTES
#undef HAS_ASSERTION

#endif /* RANDOM_HPP_INCLUDED */