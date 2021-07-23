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
			NODISCARD constexpr Scalar<T> min(Scalar<T> scalar_t) noexcept = delete;
			template<typename T>
			NODISCARD constexpr Scalar<T> min(Scalar<T> lhs, Scalar<T> rhs) noexcept
			{
				return lhs < rhs ? lhs : rhs;
			}

			template<typename T>
			NODISCARD constexpr Scalar<T> min(Vector<T> vector_t) noexcept
			{
				if (vector_t.size() == 0)
				{
					report("Vector size is equal to 0", vector_t.size() == 0);
					return Scalar<T>(0);
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
			NODISCARD constexpr Scalar<T> max(Scalar<T> scalar_t) noexcept = delete;
			template<typename T>
			NODISCARD constexpr Scalar<T> max(Scalar<T> lhs, Scalar<T> rhs) noexcept
			{
				return lhs > rhs ? lhs : rhs;
			}

			template<typename T>
			NODISCARD constexpr Scalar<T> max(Vector<T> vector_t) noexcept
			{
				if (vector_t.size() == 0)
				{
					report("Vector size is equal to 0", vector_t.size() == 0);
					return Scalar<T>(0);
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
			NODISCARD Scalar<T> pow(T base, const uint32_t exponental) noexcept
			{
				return Scalar<T>(std::pow(base, exponental));
			}

			template<typename T>
			NODISCARD Scalar<T> pow(Scalar<T> scalar_t, const uint32_t exponental) noexcept
			{
				return Scalar<T>(std::pow(scalar_t.Get_Scalar_Value(), exponental));
			}

		}
	}
}

#undef HAS_ATTRIBUTES
#undef HAS_ASSERTION

#endif /* MATH_UTILS_HPP_INCLUDED */