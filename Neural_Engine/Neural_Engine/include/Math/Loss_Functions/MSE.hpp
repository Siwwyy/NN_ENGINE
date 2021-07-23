#ifndef MSE_FUNCTION_HPP_INCLUDED
#define MSE_FUNCTION_HPP_INCLUDED
#pragma once

#include <memory>

#include "Math/Loss_Functions/Loss_Function_Base.hpp"

namespace NN
{
	namespace Math
	{
		namespace Loss_Functions
		{
			
			template<typename T>
			class MSE_impl : public Loss_Function_Base<T>
			{
			public:
				
				virtual T f(T value, T target) noexcept override;
				virtual T d_f(T value, T target) noexcept override;

			};

			template <typename T>
			T MSE_impl<T>::f(T value, T target) noexcept
			{
				return 0;
			}

			template <typename T>
			T MSE_impl<T>::d_f(T value, T target) noexcept
			{
				return 0;
			}

			template<typename T>
			class MSE_fn
			{
			public:

				std::unique_ptr<MSE_impl<T>> operator()() const
				{
					return std::make_unique<MSE_impl<T>>();
				}

			};

			template<typename T>
			inline constexpr MSE_fn<T> MSE;
			
		}
	}
}

#endif /* MSE_FUNCTION_HPP_INCLUDED */