#ifndef MODEL_HPP_INCLUDED
#define MODEL_HPP_INCLUDED
#pragma once

#include <type_traits>

#include "Math/Algebra/Vector.hpp"
#include "Math/Loss_Functions/Loss_Function_Base.hpp"

#include "Core/Layers/Layer_Base.hpp"

namespace NN
{
	namespace Model
	{

		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Model
		{
		private:

			NN::Math::Algebra::Vector<NN::Core::Layers::Layer_Base<T>> layers;

			std::unique_ptr<NN::Math::Activation_Functions::Activation_Function_Base<T>> act_function;
			std::unique_ptr<NN::Math::Loss_Functions::Loss_Function_Base<T>> loss_function;
			std::shared_ptr<NN::Math::Algebra::Vector_Arithmetic<T>> train_data;

		public:
			Model() = default;
			template<typename ... U>
			explicit Model(U&& ... layer) noexcept;

			template<typename ... U>
			void add_layer(U&& ... layer) noexcept;

			//Rethink about many declarations and then definitions like e.g for shared ptr references etc.
			template<typename U>
			void compile(std::unique_ptr<U> loss_function);

			//Rethink about many declarations and then definitions like e.g for shared ptr references etc.
			void learn(NN::Math::Algebra::Vector_Arithmetic<T>* const training_data);

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

		template <typename T, typename T0>
		template <typename U>
		void Model<T, T0>::compile(std::unique_ptr<U> loss_function)
		{
			this->loss_function = std::move(loss_function);
		}

		template <typename T, typename T0>
		void Model<T, T0>::learn(NN::Math::Algebra::Vector_Arithmetic<T>* const training_data)
		{
			this->train_data = std::make_shared<NN::Math::Algebra::Vector_Arithmetic<T>>(training_data);
		}

	}
}

#endif /* MODEL_HPP_INCLUDED */