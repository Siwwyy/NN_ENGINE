#ifndef LAYER_BASE_HPP_INCLUDED
#define LAYER_BASE_HPP_INCLUDED
#pragma once

#include <type_traits>

namespace NN
{
	namespace Layers
	{

		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Layer_Base
		{
		private:

		public:
			Layer_Base() {}


		};

	}
}

#endif /* LAYER_BASE_HPP_INCLUDED */