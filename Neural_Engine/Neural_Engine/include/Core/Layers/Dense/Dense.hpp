#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED
#pragma once

#include "Core/Layers/Layer_Base.hpp"

namespace NN
{
	namespace Core
	{
		namespace Layers
		{
			template <typename T>
			class Dense : public Layer_Base<T>
			{
			private:


			public:
				using Layer_Base<T>::Layer_Base; //ctor deriving 

				Dense() = default;
				//constexpr Dense(const std::size_t neurons_amount, NN::Math::Activation_Functions::Activation_Function_Base<T>&& activation_function) noexcept;
				constexpr Dense(const Dense& Object);
				constexpr Dense(Dense&& Object) noexcept;

				virtual Math::Algebra::Vector_Arithmetic<T>
				forward(Math::Algebra::Vector_Arithmetic<T>* input) noexcept override;
				void backward() noexcept override;

				~Dense() override = default;
			};


			//template <typename T>
			//constexpr Dense<T>::Dense(const std::size_t neurons_amount,
			//	NN::Math::Activation_Functions::Activation_Function_Base<T>&& activation_function) noexcept :
			//	Layer_Base<T>(neurons_amount, std::move(activation_function))
			//{ }

			template <typename T>
			constexpr Dense<T>::Dense(const Dense& Object) :
				Layer_Base<T>(Object)
			{
			}

			template <typename T>
			constexpr Dense<T>::Dense(Dense&& Object) noexcept :
				Layer_Base<T>(Object)
			{
			}

			template <typename T>
			Math::Algebra::Vector_Arithmetic<T> Dense<T>::forward(
				Math::Algebra::Vector_Arithmetic<T>* input) noexcept
			{
				auto output = Math::Algebra::Vector_Arithmetic<T>(this->get_neurons_amount());

				for (std::size_t i = 0; i < this->get_neurons_amount(); ++i)
				{
					for (std::size_t j = 0; j < input->size(); ++j)
					{
						//output[i] += this->get_weights()[j] * input[j];
					}
					if (this->get_biases().size() != 0)
					{
						output[i] += this->get_biases()[i];
					}

					output[i] = this->get_activation_function()->f(output[i]);
				}
				return output;
			}

			template <typename T>
			void Dense<T>::backward() noexcept
			{
			}
			
		}
	}
}

#endif /* DENSE_HPP_INCLUDED */