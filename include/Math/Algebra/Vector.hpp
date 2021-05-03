#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED


#include <vector>

#include "Scalar.hpp"

#define HAS_ATTRIBUTES 1


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

		private:

			std::vector<value_type> vector;

		public:
			Vector();
			constexpr Vector(const std::initializer_list<value_type>& elems);

			NODISCARD constexpr const pointer_type begin() noexcept;
			NODISCARD constexpr const pointer_type end() noexcept;

			NODISCARD constexpr size_t size() const noexcept;
			
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
		constexpr const typename Vector<T>::pointer_type Vector<T>::begin() noexcept
		{
			return &(*vector.begin());
		}

		template <typename T>
		constexpr const typename Vector<T>::pointer_type Vector<T>::end() noexcept
		{
			return vector.end();
		}

		template <typename T>
		constexpr size_t Vector<T>::size() const noexcept
		{
			return vector.size();
		}

	}
}

#undef HAS_ATTRIBUTES

#endif /* VECTOR_HPP_INCLUDED */