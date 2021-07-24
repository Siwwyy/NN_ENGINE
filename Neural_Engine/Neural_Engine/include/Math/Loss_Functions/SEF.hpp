#ifndef SEF_FUNCTION_HPP_INCLUDED
#define SEF_FUNCTION_HPP_INCLUDED
#pragma once

#include "Math/Loss_Functions/Loss_Function_Base.hpp"
#include "Math/Utils/Math_Utils.hpp"

namespace NN
{
	namespace Math
	{
		namespace Loss_Functions
		{

			template<typename T>
			class SEF_impl : public Loss_Function_Base<T>
			{
			public:

				virtual T f(T value, T target) noexcept override;
				virtual T d_f(T value, T target) noexcept override;

			};

			template <typename T>
			T SEF_impl<T>::f(T value, T target) noexcept
			{
				return 0.5f * NN::Math::Utils::pow((target - value), 2);
			}

			template <typename T>
			T SEF_impl<T>::d_f(T value, T target) noexcept
			{
				return -1.f * (target - value);
			}

			template<typename T>
			class SEF_fn
			{
			public:

				std::unique_ptr<SEF_impl<T>> operator()() const
				{
					return std::make_unique<SEF_impl<T>>();
				}

			};

			template<typename T>
			inline constexpr SEF_fn<T> SEF;
			
		}
	}
}

#endif /* SEF_FUNCTION_HPP_INCLUDED */