#ifndef RELU_FUNCTION_HPP_INCLUDED
#define RELU_FUNCTION_HPP_INCLUDED
#pragma once

#include <memory>

#include "Activation_Function_Base.hpp"

namespace NN
{
	namespace Math
	{
		namespace Activation_Functions
		{
			
			template<typename T>
			class ReLu_impl : public Activation_Function_Base<T>
			{
			public:
				
				T f(T x) noexcept override;
				T d_f(T x) noexcept override;
				
			};

			template <typename T>
			T ReLu_impl<T>::f(T x) noexcept
			{
				T zero = static_cast<T>(0);
				return x > zero ? x : zero;
			}

			template <typename T>
			T ReLu_impl<T>::d_f(T x) noexcept
			{
				T zero = static_cast<T>(0);
				return x > zero ? 1 : zero;
			}

			template<typename T>
			class ReLu_fn
			{
			public:

				std::unique_ptr<ReLu_impl<T>> operator()() const
				{
					return std::make_unique<ReLu_impl<T>>();
				}

			};

			template<typename T>
			inline constexpr ReLu_fn<T> ReLu;
			
		}
	}
}

#endif /* RELU_FUNCTION_HPP_INCLUDED */