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

			const std::size_t neurons_amount;

			NN::Math::Vector<T> weights;
			NN::Math::Vector<T> biases;

			std::unique_ptr<NN::Functions::Activation_Function<T>> function;

		public:
			Layer_Base() = default;
			constexpr Layer_Base(const std::size_t neurons_amount) noexcept;
			constexpr Layer_Base(const Layer_Base& Object);
			constexpr Layer_Base(Layer_Base&& Object) noexcept;

			Layer_Base& operator=(const Layer_Base& Object);
			Layer_Base& operator=(Layer_Base&& Object) noexcept;

		};

		template <typename T, typename T0>
		constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount) noexcept :
			neurons_amount(neurons_amount),
			weights(NN::Math::Utils::pow(neurons_amount, 2)),
			biases(neurons_amount)
		{ }

		template <typename T, typename T0>
		constexpr Layer_Base<T, T0>::Layer_Base(const Layer_Base& Object) :
			neurons_amount(Object.neurons_amount),
			weights(Object.weights),
			biases(Object.biases)
		{ }

		template <typename T, typename T0>
		constexpr Layer_Base<T, T0>::Layer_Base(Layer_Base&& Object) noexcept :
			neurons_amount(Object.neurons_amount),
			weights(std::exchange(Object.weights, {})),
			biases(std::exchange(Object.biases, {}))
		{ }

		template <typename T, typename T0>
		Layer_Base<T, T0>& Layer_Base<T, T0>::operator=(const Layer_Base& Object)
		{
			if (this != &Object)
			{
				neurons_amount = Object.neurons_amount;
				weights = Object.weights;
				biases = Object.biases;
			}
			return *this;
		}

		template <typename T, typename T0>
		Layer_Base<T, T0>& Layer_Base<T, T0>::operator=(Layer_Base&& Object) noexcept
		{
			if (this != &Object)
			{
				neurons_amount = Object.neurons_amount;
				weights = std::exchange(Object.weights, {});
				biases = std::exchange(Object.biases, {});
			}
			return *this;
		}
	}
}

#endif /* LAYER_BASE_HPP_INCLUDED */