#ifndef ACTIVATION_FUNCTION_HPP_INCLUDED
#define ACTIVATION_FUNCTION_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Activation_Function
	{
	public:
		Activation_Function();
		
	};

}

#endif /* ACTIVATION_FUNCTIONS_HPP_INCLUDED */