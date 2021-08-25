#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED


#include <iostream>
#include <vector>
#include <ranges>
#include <concepts>
#include <type_traits>
#include <vector>


#define HAS_ATTRIBUTES 1
#include "Scalar.hpp"

namespace NN
{
	namespace Math
	{
		namespace Algebra
		{



			template <typename T>
			class Vector; //FORWARD DECLARATION

			template <typename T>
			using Vector_Arithmetic = Vector<Scalar<T>>; //For scalar values e.g. 10, 203.32, 0.321, 1, 3, ...



			template <std::ranges::range Rng, typename T>
			auto deep_flatten_impl(const Rng& range, ::std::vector<T> & output)
			{
				using value_type = std::decay_t<std::ranges::range_value_t<Rng>>;
				if constexpr (std::ranges::range<value_type>)
				{
					for (auto&& subrange : range)
					{
						deep_flatten_impl(subrange);
					}
				}
				else
				{
					for (const auto& element : range)
					{
						//std::cout << element << ' ';
						output.push_back(element);
					}
				}
			}


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
			
			template<std::ranges::range Rng>
			auto deep_flaten(const Rng& range)
			{
				using value_type = std::decay_t<std::ranges::range_value_t<Rng>>;
				auto vec = std::vector<inner_type_t<Rng>>{};
				deep_flatten_impl(range, vec);

				return vec;
			}


			/*		template <std::size_t Size, typename Type>
					struct nested_vec_impl
					{
						using real_vec = Vector<typename nested_vec_impl<Size - 1, Type>::real_vec>;
					};

					template<typename Type>
					struct nested_vec_impl<1, Type>
					{
						using real_vec = Vector<Type>;
					};


					template<std::size_t Size, class Type>
					using Vector_Arithmetic = typename nested_vec_impl<Size, Type>::real_vec;*/

			template <typename T>
			class Vector
			{
			public:

				//using value_type = Scalar<T>;
				//using pointer_type = Scalar<T>*;
				//using reference_type = Scalar<T>&;
				//using size_type = std::size_t;

				using value_type = T;
				using pointer_type = T*;
				using reference_type = T&;
				using size_type = std::size_t;

			private:

				std::vector<value_type> vector;

			public:
				constexpr Vector();
				constexpr Vector(const std::initializer_list<value_type>& elems);
				constexpr Vector(std::size_t init_size);

				void push_back(const value_type& scalar) noexcept;
				void push_back(value_type& scalar) noexcept;
				template <typename... Elems>
				void emplace_back(Elems&& ... elems) noexcept;
				void clear() noexcept;
				bool empty() noexcept;
				NODISCARD constexpr auto index_of(const typename std::vector<value_type>::iterator& elem) noexcept;
				NODISCARD constexpr auto begin() noexcept;
				NODISCARD constexpr auto end() noexcept;
				NODISCARD constexpr auto size() const noexcept;

				NODISCARD T& operator[](size_type elem_pos) noexcept;
				NODISCARD const T& operator[](size_type elem_pos) const noexcept;
			};

			template <typename T>
			constexpr Vector<T>::Vector() :
				vector({})
			{
			}

			template <typename T>
			constexpr Vector<T>::Vector(const std::initializer_list<value_type>& elems) :
				vector(elems)
			{
			}

			template <typename T>
			constexpr Vector<T>::Vector(const std::size_t init_size) :
				vector(init_size)
			{
			}

			template <typename T>
			void Vector<T>::push_back(const value_type& scalar) noexcept
			{
				vector.push_back(scalar);
			}

			template <typename T>
			void Vector<T>::push_back(value_type& scalar) noexcept
			{
				vector.push_back(scalar);
			}

			template <typename T>
			template <typename ... Elems>
			void Vector<T>::emplace_back(Elems&&... elems) noexcept
			{
				vector.emplace_back(std::forward<Elems>(elems)...);
			}

			template <typename T>
			void Vector<T>::clear() noexcept
			{
				vector.clear();
			}

			template <typename T>
			bool Vector<T>::empty() noexcept
			{
				return vector.empty();
			}

			template <typename T>
			constexpr auto Vector<T>::index_of(const typename std::vector<value_type>::iterator& elem) noexcept
			{
				return std::distance(vector.begin(), elem);
			}

			template <typename T>
			constexpr auto Vector<T>::begin() noexcept
			{
				return vector.begin();
			}

			template <typename T>
			constexpr auto Vector<T>::end() noexcept
			{
				return vector.end();
			}

			template <typename T>
			constexpr auto Vector<T>::size() const noexcept
			{
				return vector.size();
			}

			template <typename T>
			T& Vector<T>::operator[](const size_type elem_pos) noexcept
			{
#if _CONTAINER_DEBUG_LEVEL > 0
				_STL_VERIFY(
					elem_pos < vector.size(), "vector subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0
				return vector[elem_pos];
			}

			template <typename T>
			const T& Vector<T>::operator[](const size_type elem_pos) const noexcept
			{
#if _CONTAINER_DEBUG_LEVEL > 0
				_STL_VERIFY(
					elem_pos < vector.size(), "vector subscript out of range");
#endif // _CONTAINER_DEBUG_LEVEL > 0
				return vector[elem_pos];
			}
		}
	}
}

#undef HAS_ATTRIBUTES
#endif /* VECTOR_HPP_INCLUDED */
