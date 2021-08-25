#ifndef SIGMOID_FUNCTION_HPP_INCLUDED
#define SIGMOID_FUNCTION_HPP_INCLUDED
#pragma once

#include <complex>

#include "Activation_Function_Base.hpp"

namespace NN
{
	namespace Math
	{
		namespace Activation_Functions
		{
			template <typename T>
			class Sigmoid_impl : public Activation_Function_Base<T>
			{
			public:
				T f(T x) noexcept override;
				T d_f(T x) noexcept override;
			};

			template <typename T>
			T Sigmoid_impl<T>::f(const T x) noexcept
			{
				return 1 / (1 + std::exp(-x));
			}

			template <typename T>
			T Sigmoid_impl<T>::d_f(const T f_x) noexcept
			{
				return f_x * (1 - f_x);
			}

			template <typename T>
			class Sigmoid_fn
			{
			public:

				std::unique_ptr<Sigmoid_impl<T>> operator()() const
				{
					return std::make_unique<Sigmoid_impl<T>>();
				}
			};

			template <typename T>
			inline constexpr Sigmoid_fn<T> Sigmoid;
		}
	}
}

#endif /* SIGMOID_FUNCTION_HPP_INCLUDED */


//#ifndef MODEL_HPP_INCLUDED
//#define MODEL_HPP_INCLUDED
//#pragma once
//
//#include <xutility>
//
//#include "Math/Algebra/Vector.hpp"
//#include "Layers/Layer_Base.hpp"
//
//namespace NN
//{
//
//	namespace Model
//	{
//
//		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
//		class Model
//		{
//		private:
//			//NN::Math::Vector<Layers::Layer_Base<T>> layers;
//		public:
//			Model() {};
//
//			//template<typename U>
//			//void add_layer(U&& layers) noexcept;
//		};
//
//		//template <typename T, typename T0>
//		//template <typename U>
//		//void Model<T, T0>::add_layer(U&& layers) noexcept
//		//{
//		//	this->layers.emplace_back(layers);
//		//}
//	}
//
//}
//
//#endif /* MODEL_HPP_INCLUDED */


//#ifndef LAYER_BASE_HPP_INCLUDED
//#define LAYER_BASE_HPP_INCLUDED
//#pragma once
//
////#include <xutility>
//
//namespace NN
//{
//	namespace Layers
//	{
//
//		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
//		class Layer_Base
//		{
//		private:
//
//		public:
//			Layer_Base() {};
//
//
//		};
//
//	}
//}
//
//#endif /* LAYER_BASE_HPP_INCLUDED */
