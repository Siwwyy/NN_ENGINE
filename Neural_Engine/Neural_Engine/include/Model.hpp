#ifndef MODEL_HPP_INCLUDED
#define MODEL_HPP_INCLUDED
#pragma once

#include <type_traits>

#include "Math/Algebra/Vector.hpp"
#include "Layers/Layer_Base.hpp"

namespace NN
{

	namespace Model
	{

		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Model
		{
		private:
			NN::Math::Vector<Layers::Layer_Base<T>> layers;
		public:
			Model() {};

			template<typename U>
			void add_layer(U&& layers) noexcept;
		};

		template <typename T, typename T0>
		template <typename U>
		void Model<T, T0>::add_layer(U&& layers) noexcept
		{
			this->layers.emplace_back(layers);
		}
	}

}

#endif /* MODEL_HPP_INCLUDED */