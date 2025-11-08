#ifndef LAYER_BASE_HPP_INCLUDED
#define LAYER_BASE_HPP_INCLUDED
#pragma once

#include <type_traits>

#include "Math/Algebra/Tensor.hpp"
#include "Math/Activation_Functions/Activation_Function_Base.hpp"
#include "Math/Utils/Math_Utils.hpp"


#define HAS_ASSERTION 1

namespace NN
{
	namespace Core
	{
		namespace Layers
		{
			template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
			class Layer_Base
			{
			private:

				const std::size_t neurons_amount;

				Math::Algebra::Tensor_Arithmetic<T> weights;
				Math::Algebra::Tensor_Arithmetic<T> biases;
				Math::Algebra::Tensor_Arithmetic<T> states;

				std::unique_ptr<Math::Activation_Functions::Activation_Function_Base<T>> activation_function;

			public:
				Layer_Base() = delete;
				template <typename U>
				constexpr Layer_Base(std::size_t neurons_amount, std::unique_ptr<U> activation_function,
				                     Math::Algebra::Tensor_Arithmetic<T> weights = {},
				                     Math::Algebra::Tensor_Arithmetic<T> biases = {}) noexcept;
				constexpr Layer_Base(const Layer_Base& Object);
				constexpr Layer_Base(Layer_Base&& Object) noexcept;

				virtual Math::Algebra::Tensor_Arithmetic<T> forward(Math::Algebra::Tensor_Arithmetic<T>* input) noexcept = 0;
				virtual void backward() noexcept = 0;

				Layer_Base& operator=(const Layer_Base& Object);
				Layer_Base& operator=(Layer_Base&& Object) noexcept;

				NODISCARD auto get_neurons_amount() const noexcept;
				NODISCARD const auto& get_weights() const noexcept;
				NODISCARD auto& get_weights() noexcept;
				NODISCARD const auto& get_biases() const noexcept;
				NODISCARD auto& get_biases() noexcept;
				NODISCARD const auto& get_states() const noexcept;
				NODISCARD auto& get_states() noexcept;
				NODISCARD const auto& get_activation_function() const noexcept;


				virtual ~Layer_Base() = default;
			};

			//template <typename T, typename T0>
			//constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount) noexcept :
			//	neurons_amount(neurons_amount),
			//	weights(NN::Math::Utils::pow(neurons_amount, 2)),
			//	biases(neurons_amount)
			//{ }

			//template <typename T, typename T0>
			//constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount, NN::Math::Activation_Functions::Activation_Function_Base<T>&& activation_function) noexcept :
			//neurons_amount(neurons_amount),
			//weights(NN::Math::Utils::pow(neurons_amount, 2)),
			//biases(neurons_amount),
			//activation_function(std::make_unique<NN::Math::Activation_Functions::Activation_Function_Base<T>*>(&activation_function))
			//{ }

			//template <typename T, typename T0>
			//template <typename U>
			//constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount,
			//	std::unique_ptr<U> activation_function, NN::Math::Algebra::Vector<T> weights = { 0.5f }) noexcept :
			//	neurons_amount(neurons_amount),
			//	weights(NN::Math::Utils::pow(neurons_amount, 2)),
			//	biases(neurons_amount),
			//	activation_function(std::move(activation_function))
			//{ }

			template <typename T, typename T0>
			template <typename U>
			constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount,
			                                        std::unique_ptr<U> activation_function,
			                                        Math::Algebra::Tensor_Arithmetic<T> weights,
			                                        Math::Algebra::Tensor_Arithmetic<T> biases) noexcept :
				neurons_amount(neurons_amount),
				weights(std::move(weights)),
				biases(std::move(biases)),
				states({}),
				activation_function(std::move(activation_function))
			{
				report("Neurons amount and biases amount has to be equal!", neurons_amount != biases.size())
			}

			template <typename T, typename T0>
			constexpr Layer_Base<T, T0>::Layer_Base(const Layer_Base& Object) :
				neurons_amount(Object.neurons_amount),
				weights(Object.weights),
				biases(Object.biases),
				states(Object.states),
				activation_function(Object.activation_function)
			{
			}

			template <typename T, typename T0>
			constexpr Layer_Base<T, T0>::Layer_Base(Layer_Base&& Object) noexcept :
				neurons_amount(Object.neurons_amount),
				weights(std::exchange(Object.weights, {})),
				biases(std::exchange(Object.biases, {})),
				states(std::exchange(Object.states, {})),
				activation_function(std::exchange(Object.activation_function, {}))
			{
			}

			template <typename T, typename T0>
			Layer_Base<T, T0>& Layer_Base<T, T0>::operator=(const Layer_Base& Object)
			{
				if (this != &Object)
				{
					neurons_amount = Object.neurons_amount;
					weights = Object.weights;
					biases = Object.biases;
					states = Object.states;
					activation_function = Object.activation_function;
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
					states = std::exchange(Object.states, {});
					activation_function = std::exchange(Object.activation_function, {});
				}
				return *this;
			}

			template <typename T, typename T0>
			auto Layer_Base<T, T0>::get_neurons_amount() const noexcept
			{
				return neurons_amount;
			}

			template <typename T, typename T0>
			const auto& Layer_Base<T, T0>::get_weights() const noexcept
			{
				return weights;
			}

			template <typename T, typename T0>
			auto& Layer_Base<T, T0>::get_weights() noexcept
			{
				return weights;
			}

			template <typename T, typename T0>
			const auto& Layer_Base<T, T0>::get_biases() const noexcept
			{
				return biases;
			}

			template <typename T, typename T0>
			auto& Layer_Base<T, T0>::get_biases() noexcept
			{
				return biases;
			}

			template <typename T, typename T0>
			const auto& Layer_Base<T, T0>::get_states() const noexcept
			{
				return states;
			}

			template <typename T, typename T0>
			auto& Layer_Base<T, T0>::get_states() noexcept
			{
				return states;
			}

			template <typename T, typename T0>
			const auto& Layer_Base<T, T0>::get_activation_function() const noexcept
			{
				return activation_function;
			}
		}
	}
}

#undef HAS_ASSERTION
#endif /* LAYER_BASE_HPP_INCLUDED */
