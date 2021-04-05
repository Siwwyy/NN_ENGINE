#ifndef MATH_UTILS_HPP_INCLUDED
#define MATH_UTILS_HPP_INCLUDED


#include "Math/Algebra/Scalar.hpp"
#include "Math/Algebra/Vector.hpp"

#include <iostream>


namespace NN
{
	namespace Math
	{
		namespace Utils
		{
#define HAS_ATTRIBUTES 1
#define ASSERTION 1
#include "Core/Defines/Defines.hpp"

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
					//report(("Vector size is equal to 0", vector_t.size() == 0));
					report("dddd")
				
					return Scalar<T>(0);
				}

				Scalar<T> elem = *(vector_t.begin());

				return elem;
			}

#undef ASSERTION
#undef HAS_ATTRIBUTES

		}
	}
}

#endif /* MATH_UTILS_HPP_INCLUDED */