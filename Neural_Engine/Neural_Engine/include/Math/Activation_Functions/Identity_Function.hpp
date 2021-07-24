#ifndef IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED
#define IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED
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
			class Identity_Function_impl : public Activation_Function_Base<T>
			{
			public:
				T f(T x) noexcept override;
				T d_f(T x) noexcept override;
			};

			template <typename T>
			T Identity_Function_impl<T>::f(T x) noexcept
			{
				return x;
			}

			template <typename T>
			T Identity_Function_impl<T>::d_f(T f_x) noexcept
			{
				return 1;
			}


			template<typename T>
			class Identity_Function_fn
			{
			public:
				
				std::unique_ptr<Identity_Function_impl<T>> operator()() const
				{
					return std::make_unique<Identity_Function_impl<T>>();
				}
				
			};

			template<typename T>
			inline constexpr Identity_Function_fn<T> Identity_Function;
			
		}
	}
}

#endif /* IDENTITY_FUNCTION_FUNCTION_HPP_INCLUDED */