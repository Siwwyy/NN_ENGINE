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
		template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Model
		{
		private:

			Math::Algebra::Vector<Core::Layers::Layer_Base<T>*> layers;

			std::unique_ptr<Math::Activation_Functions::Activation_Function_Base<T>> act_function;
			std::unique_ptr<Math::Loss_Functions::Loss_Function_Base<T>> loss_function;

			//std::shared_ptr<NN::Math::Algebra::Vector_Arithmetic<T>> train_data;
			//std::shared_ptr<NN::Math::Algebra::Vector_Arithmetic<T>> test_data;

			Math::Algebra::Vector_Arithmetic<T>* train_data;
			Math::Algebra::Vector_Arithmetic<T>* test_data;


			void generate_connections() noexcept;
			void initialize_layers() noexcept;
			void start_learning() const noexcept;

		public:
			Model();
			/**
			 * Constructor does not work properly atm.
			 */
			template <typename ... U>
			explicit Model(U&& ... layer) noexcept;

			void add_layer(Core::Layers::Layer_Base<T>&& layer) noexcept;

			//Rethink about many declarations and then definitions like e.g for shared ptr references etc.
			template <typename U>
			void compile(std::unique_ptr<U> loss_function);

			//Rethink about many declarations and then definitions like e.g for shared ptr references etc.
			void learn(Math::Algebra::Vector_Arithmetic<T>* training_data,
			           Math::Algebra::Vector_Arithmetic<T>* test_data);
		};

		template <typename T, typename T0>
		void Model<T, T0>::generate_connections() noexcept
		{
			/*Assume that, when there is no weights at input layer, its creates a new one for
			whole model */
			//if (layers[0]->get_weights().size() == 0)
			//{
			//	using type = int32_t;
			//	const type layers_amount = layers.size();
			//	for (type i = layers_amount - 1; i >= 0; --i)
			//	{
			//		if (i > 0) //if statement for avoid possible subscripting vector out of range
			//		{
			//			layers[i - 1]->get_weights() = NN::Math::Utils::generate_weights<T>(layers[i]->get_neurons_amount());
			//			layers[i - 1]->get_weights() = NN::Math::Utils::generate_weights<T>(layers[i]->get_neurons_amount());
			//		}
			//	}
			//}
			if (layers[0]->get_weights().size() == 0)
			{
				using type = std::size_t;
				const type layers_amount = layers.size();
				for (type i = 0; i < layers_amount; ++i)
				{
					if (i < layers_amount - 1) //if statement for avoid possible subscripting vector out of range
					{
						layers[i]->get_weights() = Math::Utils::generate_weights<T
						>(layers[i + 1]->get_neurons_amount());
						//if(biases==true)
						//layers[i + 1]->get_biases() = NN::Math::Utils::generate_weights<T>(layers[i + 1]->get_neurons_amount());
						layers[i + 1]->get_biases() = {1.f}; //does not work properly, rethink loop
					}
				}
			}

			int dd = 230;
		}

		template <typename T, typename T0>
		void Model<T, T0>::initialize_layers() noexcept
		{
		}

		template <typename T, typename T0>
		void Model<T, T0>::start_learning() const noexcept
		{
			const std::size_t layers_amount = layers.size();

			//Batch
			auto output = NN::Math::Algebra::Vector_Arithmetic<T>{};
			auto Total_Error = NN::Math::Algebra::Vector_Arithmetic<T>{};
			for (const auto& elem : *train_data)
			{
				output = elem;
				for (std::size_t i = 0; i < layers_amount; ++i)
				{
					output = std::move(layers[i]->forward(&output));
				}

				Total_Error += loss_function->f(output, test_data[0]);
			}
		}

		template <typename T, typename T0>
		Model<T, T0>::Model() :
			train_data(nullptr),
			test_data(nullptr)
		{
		}

		template <typename T, typename T0>
		template <typename ... U>
		Model<T, T0>::Model(U&&... layer) noexcept

		{
			//std::size_t connection_amount = 0;
			//layers.emplace_back(std::forward<U>())
		}

		template <typename T, typename T0>
		void Model<T, T0>::add_layer(Core::Layers::Layer_Base<T>&& layer) noexcept
		{
			layers.emplace_back(&layer);
		}

		template <typename T, typename T0>
		template <typename U>
		void Model<T, T0>::compile(std::unique_ptr<U> loss_function)
		{
			this->loss_function = std::move(loss_function);
		}

		template <typename T, typename T0>
		void Model<T, T0>::learn(Math::Algebra::Vector_Arithmetic<T>* const training_data,
		                         Math::Algebra::Vector_Arithmetic<T>* const test_data)
		{
			//this->train_data = std::make_shared<NN::Math::Algebra::Vector_Arithmetic<T>>(training_data);
			//this->test_data = std::make_shared<NN::Math::Algebra::Vector_Arithmetic<T>>(test_data);

			this->train_data = training_data;
			this->test_data = test_data;

			start_learning();
		}
	}
}

#endif /* MODEL_HPP_INCLUDED */
