#ifndef ACTIVATION_FUNCTION_HPP_INCLUDED
#define ACTIVATION_FUNCTION_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{
	namespace Functions
	{
		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Activation_Function
		{
		public:
			using value_type = T;
			using pointer_type = T*;
			using reference_type = T&;

			Activation_Function() {}
			Activation_Function(const Activation_Function& Object) { *this = Object; }
			Activation_Function(Activation_Function&& Object) noexcept { *this = std::move(Object); }

			virtual T f(T x) noexcept = 0;
			virtual T d_f(T x) noexcept = 0;

			virtual ~Activation_Function() {}
		};

	}

}

#endif /* ACTIVATION_FUNCTIONS_HPP_INCLUDED */