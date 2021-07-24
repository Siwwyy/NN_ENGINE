#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED
#pragma once

#include "Math/Algebra/Vector.hpp"

#include "Math/Activation_Functions/Activation_Function.hpp"
#include "Math/Activation_Functions/Sigmoid.hpp"

#include "Math/Utils/Math_Utils.hpp"

#include "Layers/Layer_Base.hpp"

namespace NN
{
	namespace Layers
	{
		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Dense : public Layer_Base<T>
		{
		private:


		public:
			Dense() = default;
			constexpr Dense(const std::size_t neurons_amount) noexcept;

		};

		template <typename T, typename T0>
		constexpr Dense<T, T0>::Dense(const std::size_t neurons_amount) noexcept :
			Layer_Base<T>(neurons_amount)
		{ }

	}
}

#endif /* DENSE_HPP_INCLUDED */