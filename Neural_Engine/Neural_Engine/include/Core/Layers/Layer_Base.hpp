#ifndef LAYER_BASE_HPP_INCLUDED
#define LAYER_BASE_HPP_INCLUDED
#pragma once

#include <type_traits>

#include "Math/Algebra/Vector.hpp"
#include "Math/Activation_Functions/Activation_Function_Base.hpp"
#include "Math/Utils/Math_Utils.hpp"

namespace NN
{
	namespace Core
	{
		namespace Layers
		{

			template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
			class Layer_Base
			{
			private:

				const std::size_t neurons_amount;

				NN::Math::Algebra::Vector<T> weights;
				NN::Math::Algebra::Vector<T> biases;

				std::unique_ptr<NN::Math::Activation_Functions::Activation_Function_Base<T>> activation_function;

			public:
				Layer_Base() = delete;
				template<typename U>
				constexpr Layer_Base(const std::size_t neurons_amount, std::unique_ptr<U> activation_function) noexcept;
				constexpr Layer_Base(const Layer_Base& Object);
				constexpr Layer_Base(Layer_Base&& Object) noexcept;

				virtual void forward() noexcept;
				virtual void backward() noexcept;

				Layer_Base& operator=(const Layer_Base& Object);
				Layer_Base& operator=(Layer_Base&& Object) noexcept;

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

			template <typename T, typename T0>
			template <typename U>
			constexpr Layer_Base<T, T0>::Layer_Base(const std::size_t neurons_amount,
				std::unique_ptr<U> activation_function) noexcept:
				neurons_amount(neurons_amount),
				weights(NN::Math::Utils::pow(neurons_amount, 2)),
				biases(neurons_amount),
				activation_function(std::move(activation_function))
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
			void Layer_Base<T, T0>::forward() noexcept
			{
				for(std::size_t i = 0; i < weights.size(); ++i)
				{
					
				}
			}

			template <typename T, typename T0>
			void Layer_Base<T, T0>::backward() noexcept
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
}

#endif /* LAYER_BASE_HPP_INCLUDED */