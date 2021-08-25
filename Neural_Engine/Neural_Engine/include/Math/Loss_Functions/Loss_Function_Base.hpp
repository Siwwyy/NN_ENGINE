#ifndef LOSS_FUNCTION_BASE_FUNCTION_HPP_INCLUDED
#define LOSS_FUNCTION_BASE_FUNCTION_HPP_INCLUDED
#pragma once

#include "Math/Algebra/Vector.hpp"

namespace NN
{
	namespace Math
	{
		namespace Loss_Functions
		{
			template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
			class Loss_Function_Base
			{
			public:
				using value_type = T;
				using pointer_type = T*;
				using reference_type = T&;
				using Return_Type = Algebra::Vector_Arithmetic<T>;

				Loss_Function_Base() = default;
				constexpr Loss_Function_Base(const Loss_Function_Base& Object) = default;
				constexpr Loss_Function_Base(Loss_Function_Base&& Object) = default;

				virtual Return_Type f(Algebra::Vector_Arithmetic<T> value,
				                      Algebra::Vector_Arithmetic<T> target) noexcept = 0;
				virtual Return_Type d_f(Algebra::Vector_Arithmetic<T> value,
				                        Algebra::Vector_Arithmetic<T> target) noexcept = 0;

				Loss_Function_Base& operator=(const Loss_Function_Base& Object) = default;
				Loss_Function_Base& operator=(Loss_Function_Base&& Object) noexcept = default;

				virtual ~Loss_Function_Base() = default;
			};
		}
	}
}

#endif /* LOSS_FUNCTION_BASE_FUNCTION_HPP_INCLUDED */
