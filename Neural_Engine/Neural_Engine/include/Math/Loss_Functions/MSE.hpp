#ifndef MSE_FUNCTION_HPP_INCLUDED
#define MSE_FUNCTION_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{
	namespace Loss_Function
	{

		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class MSE
		{
		private:

		public:

		};

	}
}

#endif /* MSE_FUNCTION_HPP_INCLUDED */