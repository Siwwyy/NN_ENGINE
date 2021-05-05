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
		class Vector /*: private Scalar<T>*/
		{
		public:

			using value_type = Scalar<T>;
			using pointer_type = Scalar<T>*;
			using reference_type = Scalar<T>&;
			using size_type = std::size_t;

		private:

			std::vector<value_type> vector;

		public:
			Vector();
			constexpr Vector(const std::initializer_list<value_type>& elems);

			void clear() noexcept;
			NODISCARD constexpr auto index_of(const typename std::vector<value_type>::iterator& elem) noexcept;
			NODISCARD constexpr auto begin() noexcept;
			NODISCARD constexpr auto end() noexcept;
			NODISCARD constexpr auto size() const noexcept;

			NODISCARD constexpr auto& operator[](const size_type elem_pos) noexcept;
		};

		template <typename T>
		Vector<T>::Vector() :
			vector({})
		{ }

		template <typename T>
		constexpr Vector<T>::Vector(const std::initializer_list<value_type>& elems) :
			vector(elems)
		{ }

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