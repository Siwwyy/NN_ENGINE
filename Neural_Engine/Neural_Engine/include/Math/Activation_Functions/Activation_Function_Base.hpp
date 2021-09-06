#ifndef ACTIVATION_FUNCTION_BASE_BASE_HPP_INCLUDED
#define ACTIVATION_FUNCTION_BASE_BASE_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{
	namespace Math
	{
		namespace Activation_Functions
		{
			template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
			class Activation_Function_Base
			{
			public:
				using value_type = T;
				using pointer_type = T*;
				using reference_type = T&;

				Activation_Function_Base() = default;
				constexpr Activation_Function_Base(const Activation_Function_Base& Object) = default;
				constexpr Activation_Function_Base(Activation_Function_Base&& Object) noexcept = default;

				virtual T f(T x) noexcept = 0;
				virtual T d_f(T x) noexcept = 0;

				Activation_Function_Base& operator=(const Activation_Function_Base& Object) = default;
				Activation_Function_Base& operator=(Activation_Function_Base&& Object) noexcept = default;

				virtual ~Activation_Function_Base() = default;
			};
		}
	}
}

#endif /* ACTIVATION_FUNCTION_BASE_BASE_HPP_INCLUDED */
