#ifndef IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED
#define IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED
#pragma once

#include "Activation_Function.hpp"

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Identity_Function : public Activation_Function<T>
	{
	public:
		T f(T x) noexcept override;
		T d_f(T x) noexcept override;
	};

	template <typename T, typename T0>
	T Identity_Function<T, T0>::f(T x) noexcept 
	{
		return x;
	}

	template <typename T, typename T0>
	T Identity_Function<T, T0>::d_f(T f_x) noexcept
	{
		return 1;
	}

}

#endif /* IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED */