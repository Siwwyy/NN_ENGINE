#ifndef TENSOR_HPP_INCLUDED
#define TENSOR_HPP_INCLUDED


#include <iostream>
#include <vector>
#include <type_traits>


#define HAS_ATTRIBUTES 1
#include "Scalar.hpp"
//#include "Tensor_Flatten.hpp"
//#include "Core/NN_CORE/NN_Storage_System/NN_Flatten.hpp"

namespace NN
{
	namespace Math
	{
		namespace Algebra
		{

			template <typename T>
			class Tensor
			{
			public:
				
				using value_type = T;
				using pointer_type = T*;
				using reference_type = T&;
				using size_type = std::size_t;

			private:

				std::vector<value_type> vector;

			public:
				constexpr Tensor();
				constexpr Tensor(const std::initializer_list<value_type>& elems);
				constexpr Tensor(std::size_t init_size);

				void push_back(const value_type& scalar) noexcept;
				void push_back(value_type& scalar) noexcept;
				template <typename... Elems>
				void emplace_back(Elems&& ... elems) noexcept;
				void clear() noexcept;
				bool empty() noexcept;
				//NN::Math::Algebra::Tensor_Flatten<T> flatten();
				NODISCARD constexpr auto index_of(const typename std::vector<value_type>::iterator& elem) noexcept;
				NODISCARD constexpr auto begin() noexcept;
				NODISCARD constexpr auto end() noexcept;
				NODISCARD constexpr auto size() const noexcept;

				NODISCARD T& operator[](size_type elem_pos) noexcept;
				NODISCARD const T& operator[](size_type elem_pos) const noexcept;
			};

			template <typename T>
			constexpr Tensor<T>::Tensor() :
				vector({})
			{
			}

			template <typename T>
			constexpr Tensor<T>::Tensor(const std::initializer_list<value_type>& elems) :
				vector(elems)
			{
			}

			template <typename T>
			constexpr Tensor<T>::Tensor(const std::size_t init_size) :
				vector(init_size)
			{
			}

			template <typename T>
			void Tensor<T>::push_back(const value_type& scalar) noexcept
			{
				vector.push_back(scalar);
			}

			template <typename T>
			void Tensor<T>::push_back(value_type& scalar) noexcept
			{
				vector.push_back(scalar);
			}

			template <typename T>
			template <typename ... Elems>
			void Tensor<T>::emplace_back(Elems&&... elems) noexcept
			{
				vector.emplace_back(std::forward<Elems>(elems)...);
			}

			template <typename T>
			void Tensor<T>::clear() noexcept
			{
				vector.clear();
			}

			template <typename T>
			bool Tensor<T>::empty() noexcept
			{
				return vector.empty();
			}

			//template <typename T>
			//Tensor_Flatten<T> Tensor<T>::flatten()
			//{
			//	return NN::Core::NN_CORE::NN_Storage_System::flatten(*this);
			//}

			template <typename T>
			constexpr auto Tensor<T>::index_of(const typename std::vector<value_type>::iterator& elem) noexcept
			{
				return std::distance(vector.begin(), elem);
			}

			template <typename T>
			constexpr auto Tensor<T>::begin() noexcept
			{
				return vector.begin();
			}

			template <typename T>
			constexpr auto Tensor<T>::end() noexcept
			{
				return vector.end();
			}

			template <typename T>
			constexpr auto Tensor<T>::size() const noexcept
			{
				return vector.size();
			}

			template <typename T>
			T& Tensor<T>::operator[](const size_type elem_pos) noexcept
			{
#if _CONTAINER_DEBUG_LEVEL > 0
				_STL_VERIFY(
					elem_pos < vector.size(), "Tensor subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0
				return vector[elem_pos];
			}

			template <typename T>
			const T& Tensor<T>::operator[](const size_type elem_pos) const noexcept
			{
#if _CONTAINER_DEBUG_LEVEL > 0
				_STL_VERIFY(
					elem_pos < vector.size(), "Tensor subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0
				return vector[elem_pos];
			}



			//ALIASES
			template <typename T>
			using Tensor_Arithmetic = Tensor<Scalar<T>>; //For scalar values e.g. 10, 203.32, 0.321, 1, 3, ...

			template <typename T>
			using Tensor_Arithmetic_2D = Tensor<Tensor_Arithmetic<T>>; //For matrix values 

			template <typename T>
			using Tensor_Arithmetic_3D = Tensor<Tensor_Arithmetic_2D<T>>; //For 3D values, e.g., RGB image

			template <typename T>
			using Tensor_Arithmetic_4D = Tensor<Tensor_Arithmetic_3D<T>>; //For NCHW format

			template <typename T>
			using Tensor_Arithmetic_5D = Tensor<Tensor_Arithmetic_4D<T>>;

			template <typename T>
			using Tensor_Arithmetic_6D = Tensor<Tensor_Arithmetic_5D<T>>;
			
		}
	}
}

#undef HAS_ATTRIBUTES
#endif /* TENSOR_HPP_INCLUDED */