#ifndef ACTIVATION_FUNCTIONS_HPP_INCLUDED
#define ACTIVATION_FUNCTIONS_HPP_INCLUDED
#pragma once

#include <xutility>

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Activation_Functions
	{
	public:
		Activation_Functions();

		void foo();
	};

}

#endif /* ACTIVATION_FUNCTIONS_HPP_INCLUDED */