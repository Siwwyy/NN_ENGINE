#ifndef SIGMOID_FUNCTION_HPP_INCLUDED
#define SIGMOID_FUNCTION_HPP_INCLUDED
#pragma once

#include <complex>

#include "Activation_Function.hpp"

namespace NN
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Sigmoid : public Activation_Function<T>
	{
	public:
		T f(T x) noexcept override;
		T d_f(T x) noexcept override;
	};

	template <typename T, typename T0>
	T Sigmoid<T, T0>::f(const T x) noexcept
	{
		return 1 / (1 + std::exp(-x));
	}

	template <typename T, typename T0>
	T Sigmoid<T, T0>::d_f(const T f_x) noexcept
	{
		return f_x * (1 - f_x);
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