#ifndef NN_FLATTEN_HPP_INCLUDED
#define NN_FLATTEN_HPP_INCLUDED
#pragma once


#include <vector>
#include <ranges>
#include <concepts>

#include "Math/Algebra/Tensor.hpp"


namespace NN
{
	namespace Core
	{
		namespace NN_CORE
		{
			namespace NN_Storage_System
			{
				
				template<typename T>
				struct inner_type
				{
					using value_type = T;
				};

				template<typename T>
				struct inner_type<std::vector<T>>
				{
					using value_type = typename inner_type<T>::value_type;
				};

				template<typename T>
				using inner_type_t = typename inner_type<std::remove_cvref_t<T>>::value_type;


				template <std::ranges::range Rng, typename T>
				auto deep_flatten_impl(const Rng& range, Math::Algebra::Tensor<T>& output);
				
				template<std::ranges::range Rng>
				auto flatten(const Rng& range);
				
			}
		}
	}
}

#endif /* NN_FLATTEN_HPP_INCLUDED */