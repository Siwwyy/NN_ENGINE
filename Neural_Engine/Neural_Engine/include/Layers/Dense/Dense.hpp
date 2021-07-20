#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED
#pragma once

#include <type_traits>

#include "Math/Algebra/Vector.hpp"

#include "Math/Activation_Functions/Activation_Function.hpp"
#include "Math/Activation_Functions/Sigmoid.hpp"

#include "Math/Loss_Functions/MSE.hpp"

#include "Layers/Layer_Base.hpp"

namespace NN
{
	namespace Layers
	{
		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Dense : public Layer_Base<T>
		{
		private:
			NN::Math::Vector<T> weights;
			NN::Math::Vector<T> biases;

			std::unique_ptr<NN::Activation_Function<T>> function;
			//std::unique_ptr<NN::MSE<T>> error;
		public:
			Dense();

		};

		template <typename T, typename T0>
		Dense<T, T0>::Dense() :
			weights({}),
			biases({}),
			function(std::make_unique<NN::Sigmoid<T>>())
			//error(std::make_unique<NN::MSE<T>>())
		{ }

	}
}

#endif /* DENSE_HPP_INCLUDED */