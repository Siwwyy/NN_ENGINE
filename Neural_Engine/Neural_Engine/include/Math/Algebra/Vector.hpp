#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <vector>

#define HAS_ATTRIBUTES 1
#include "Scalar.hpp"
#include "Core/Defines/Defines_Assert.hpp"


namespace NN
{
	namespace Math
	{
		template<typename T>
		class Vector;		//FORWARD DECLARATION

		template<typename T>
		using Vector_Arithmetic = Vector<Scalar<T>>;

		template<typename T>
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
			constexpr Vector(const std::size_t init_size);

			void push_back(const value_type& scalar) noexcept;
			void push_back(value_type& scalar) noexcept;
			template <typename... Elems>
			void emplace_back(Elems && ... elems) noexcept;
			void clear() noexcept;
			NODISCARD constexpr auto index_of(const typename std::vector<value_type>::iterator& elem) noexcept;
			NODISCARD constexpr auto begin() noexcept;
			NODISCARD constexpr auto end() noexcept;
			NODISCARD constexpr auto size() const noexcept;

			NODISCARD constexpr auto& operator[](const size_type elem_pos) noexcept;
		};

		template <typename T>
		constexpr Vector<T>::Vector() :
			vector({})
		{ }

		template <typename T>
		constexpr Vector<T>::Vector(const std::initializer_list<value_type>& elems) :
			vector(elems)
		{ }

		template <typename T>
		constexpr Vector<T>::Vector(const std::size_t init_size) :
			vector(init_size)
		{ }

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
		constexpr auto& Vector<T>::operator[](const size_type elem_pos) noexcept
		{
			static_assert(elem_pos >= vector.size(), "vector subscript out of range");
			return vector[elem_pos];
		}





	}
}

#undef HAS_ATTRIBUTES
#endif /* VECTOR_HPP_INCLUDED */