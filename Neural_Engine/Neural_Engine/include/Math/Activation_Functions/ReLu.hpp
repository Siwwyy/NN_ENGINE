#ifndef RELU_FUNCTION_HPP_INCLUDED
#define RELU_FUNCTION_HPP_INCLUDED
#pragma once

#include "Activation_Function.hpp"

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class ReLu : public Activation_Function<T>
	{
	public:
		T f(T x) noexcept override;
		T d_f(T x) noexcept override;
	};

	template <typename T, typename T0>
	T ReLu<T, T0>::f(T x) noexcept
	{
		T zero = static_cast<T>(0);
		return x > zero ? x : zero;
	}

	template <typename T, typename T0>
	T ReLu<T, T0>::d_f(T x) noexcept
	{
		T zero = static_cast<T>(0);
		return x > zero ? 1 : zero;
	}

}

#endif /* RELU_FUNCTION_HPP_INCLUDED */