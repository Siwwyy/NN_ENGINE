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
			//NN::Math::

		public:
			Model() = default;
			template<typename ... U>
			explicit Model(U&& ... layer) noexcept;

			template<typename ... U>
			void add_layer(U&& ... layer) noexcept;


		};

		template <typename T, typename T0>
		template <typename ... U>
		Model<T, T0>::Model(U&&... layer) noexcept :
			layers(std::forward<U>(layer)...)
		{ }

		template <typename T, typename T0>
		template <typename ... U>
		void Model<T, T0>::add_layer(U&& ... layer) noexcept
		{
			layers.emplace_back(std::forward<U>(layer)...);
		}

	}

}

#endif /* MODEL_HPP_INCLUDED */