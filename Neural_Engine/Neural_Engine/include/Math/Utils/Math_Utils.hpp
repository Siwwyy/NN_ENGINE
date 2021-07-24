#ifndef MATH_UTILS_HPP_INCLUDED
#define MATH_UTILS_HPP_INCLUDED

#include <iostream>

#define HAS_ASSERTION 1
#define HAS_ATTRIBUTES 1

#include "Math/Algebra/Scalar.hpp"
#include "Math/Algebra/Vector.hpp"


#include "Core/Defines/Defines_Assert.hpp"
#include "Core/Defines/Defines_Func_Attributes.hpp"


namespace NN
{
	namespace Math
	{
		namespace Utils
		{

			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> min(Algebra::Scalar<T> scalar_t) noexcept = delete;
			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> min(Algebra::Scalar<T> lhs, Algebra::Scalar<T> rhs) noexcept
			{
				return lhs < rhs ? lhs : rhs;
			}

			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> min(Algebra::Vector<T> vector_t) noexcept
			{
				if (vector_t.size() == 0)
				{
					report("Vector size is equal to 0", vector_t.size() == 0);
					return NN::Math::Algebra::Scalar<T>(0);
				}

				auto smallest_elem = *vector_t.begin();
				for (const auto& elem : vector_t)
				{
					if (smallest_elem > elem)
					{
						smallest_elem = elem;
					}
				}
				return smallest_elem;
			}

			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> max(Algebra::Scalar<T> scalar_t) noexcept = delete;
			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> max(Algebra::Scalar<T> lhs, Algebra::Scalar<T> rhs) noexcept
			{
				return lhs > rhs ? lhs : rhs;
			}

			template<typename T>
			NODISCARD constexpr Algebra::Scalar<T> max(Algebra::Vector<T> vector_t) noexcept
			{
				if (vector_t.size() == 0)
				{
					report("Vector size is equal to 0", vector_t.size() == 0);
					return NN::Math::Algebra::Scalar<T>(0);
				}

				auto greatest_elem = *vector_t.begin();
				for (const auto& elem : vector_t)
				{
					if (greatest_elem < elem)
					{
						greatest_elem = elem;
					}
				}
				return greatest_elem;
			}

			template<typename T>
			NODISCARD Algebra::Scalar<T> pow(T base, const uint32_t exponental) noexcept
			{
				return Algebra::Scalar<T>(std::pow(base, exponental));
			}

			template<typename T>
			NODISCARD Algebra::Scalar<T> pow(Algebra::Scalar<T> scalar_t, const uint32_t exponental) noexcept
			{
				return Algebra::Scalar<T>(std::pow(scalar_t.Get_Scalar_Value(), exponental));
			}

		}
	}
}

#undef HAS_ATTRIBUTES
#undef HAS_ASSERTION

#endif /* MATH_UTILS_HPP_INCLUDED */