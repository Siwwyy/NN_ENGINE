#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED
#pragma once

#include "Math/Algebra/Vector.hpp"

#include "Math/Activation_Functions/Activation_Function.hpp"
#include "Math/Activation_Functions/Sigmoid.hpp"

#include "Math/Utils/Math_Utils.hpp"

#include "Layers/Layer_Base.hpp"

namespace NN
{
	namespace Layers
	{
		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Dense : public Layer_Base<T>
		{
		private:

			const std::size_t neurons_amount;

			NN::Math::Vector<T> weights;
			NN::Math::Vector<T> biases;

			std::unique_ptr<NN::Functions::Activation_Function<T>> function;
		public:
			Dense() = default;
			constexpr Dense(const std::size_t neurons_amount) noexcept;

		};

		template <typename T, typename T0>
		constexpr Dense<T, T0>::Dense(const std::size_t neurons_amount) noexcept :
			neurons_amount(neurons_amount),
			//weights(NN::Math::Utils::pow(neurons_amount, 2)),
			weights(neurons_amount * neurons_amount),
			biases(neurons_amount)
		{ }

		//template <typename T, typename T0>
		//Dense<T, T0>::Dense() :
		//	weights({}),
		//	biases({}),
		//	function(std::make_unique<NN::Functions::Sigmoid<T>>())
		//{ }

	}
}

#endif /* DENSE_HPP_INCLUDED */