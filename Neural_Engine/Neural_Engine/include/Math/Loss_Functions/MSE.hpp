#ifndef MSE_FUNCTION_HPP_INCLUDED
#define MSE_FUNCTION_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class MSE
	{
	public:

	};

}

#endif /* MSE_FUNCTION_HPP_INCLUDED */