#ifndef DENSE_HPP_INCLUDED
#define DENSE_HPP_INCLUDED
#pragma once

#include "Math/Algebra/Vector.hpp"

#include "Math/Activation_Functions/Activation_Function_Base.hpp"
#include "Math/Activation_Functions/Sigmoid.hpp"

#include "Math/Utils/Math_Utils.hpp"

#include "Core/Layers/Layer_Base.hpp"

namespace NN
{
	namespace Core
	{
		namespace Layers
		{

			template<typename T>
			class Dense : public Layer_Base<T>
			{
			private:


			public:
				using Layer_Base<T>::Layer_Base;	//ctor deriving 
				
				Dense() = delete;
				//constexpr Dense(const std::size_t neurons_amount, NN::Math::Activation_Functions::Activation_Function_Base<T>&& activation_function) noexcept;
				constexpr Dense(const Dense& Object);
				constexpr Dense(Dense&& Object) noexcept;

				void forward() noexcept override;
				void backward() noexcept override;

				virtual ~Dense() override = default;
			};


			//template <typename T>
			//constexpr Dense<T>::Dense(const std::size_t neurons_amount,
			//	NN::Math::Activation_Functions::Activation_Function_Base<T>&& activation_function) noexcept :
			//	Layer_Base<T>(neurons_amount, std::move(activation_function))
			//{ }

			template <typename T>
			constexpr Dense<T>::Dense(const Dense& Object) :
				Layer_Base<T>(Object)
			{ }

			template <typename T>
			constexpr Dense<T>::Dense(Dense&& Object) noexcept :
				Layer_Base<T>(Object)
			{ }

			template <typename T>
			void Dense<T>::forward() noexcept
			{
				
			}

			template <typename T>
			void Dense<T>::backward() noexcept
			{
				
			}

		}
	}
}

#endif /* DENSE_HPP_INCLUDED */