#ifndef SCALAR_HPP_INCLUDED
#define SCALAR_HPP_INCLUDED

#include <ostream>

#define HAS_ATTRIBUTES 1
#include "Core/Defines/Defines_Func_Attributes.hpp"

namespace NN
{

	namespace Math
	{
		
		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Scalar
		{
		private:

			T scalar_value;

		public:

			using value_type = T;
			using const_type = const T;
			using reference_type = T&;
			using const_reference_type = const T&;

		public:
			
			constexpr Scalar(const value_type scalar_value);
			
			NODISCARD constexpr explicit operator value_type() const noexcept;

			constexpr Scalar& operator+=(const_type rhs) noexcept;
			constexpr Scalar& operator-=(const_type rhs) noexcept;
			constexpr Scalar& operator*=(const_type rhs) noexcept;
			constexpr Scalar& operator/=(const_type rhs) noexcept;
			NODISCARD constexpr bool operator<(const_type rhs) const noexcept;
			NODISCARD constexpr bool operator>(const_type rhs) const noexcept;
			NODISCARD constexpr bool operator<=(const_type rhs) const noexcept;
			NODISCARD constexpr bool operator>=(const_type rhs) const noexcept;
			NODISCARD constexpr bool operator==(const_type rhs) const noexcept;
			NODISCARD constexpr bool operator!=(const_type rhs) const noexcept;

			constexpr Scalar& operator+=(const Scalar rhs) noexcept;
			constexpr Scalar& operator-=(const Scalar rhs) noexcept;
			constexpr Scalar& operator*=(const Scalar rhs) noexcept;
			constexpr Scalar& operator/=(const Scalar rhs) noexcept;
			NODISCARD constexpr bool operator<(const Scalar rhs) const noexcept;
			NODISCARD constexpr bool operator>(const Scalar rhs) const noexcept;
			NODISCARD constexpr bool operator<=(const Scalar rhs) const noexcept;
			NODISCARD constexpr bool operator>=(const Scalar rhs) const noexcept;
			NODISCARD constexpr bool operator==(const Scalar rhs) const noexcept;
			NODISCARD constexpr bool operator!=(const Scalar rhs) const noexcept;

			NODISCARD friend constexpr Scalar operator+(Scalar lhs, const_type rhs) noexcept { return lhs += rhs; }
			NODISCARD friend constexpr Scalar operator-(Scalar lhs, const_type rhs) noexcept { return lhs -= rhs; }
			NODISCARD friend constexpr Scalar operator*(Scalar lhs, const_type rhs) noexcept { return lhs *= rhs; }
			NODISCARD friend constexpr Scalar operator/(Scalar lhs, const_type rhs) noexcept { return lhs /= rhs; }

			NODISCARD friend constexpr Scalar operator+(const_type lhs, Scalar rhs) noexcept { return rhs += lhs; }
			NODISCARD friend constexpr Scalar operator-(const_type lhs, Scalar rhs) noexcept { return rhs -= lhs; }
			NODISCARD friend constexpr Scalar operator*(const_type lhs, Scalar rhs) noexcept { return rhs *= lhs; }
			NODISCARD friend constexpr Scalar operator/(const_type lhs, Scalar rhs) noexcept { return rhs /= lhs; }

			NODISCARD friend constexpr Scalar operator+(Scalar lhs, Scalar rhs) noexcept { return lhs += rhs; }
			NODISCARD friend constexpr Scalar operator-(Scalar lhs, Scalar rhs) noexcept { return lhs -= rhs; }
			NODISCARD friend constexpr Scalar operator*(Scalar lhs, Scalar rhs) noexcept { return lhs *= rhs; }
			NODISCARD friend constexpr Scalar operator/(Scalar lhs, Scalar rhs) noexcept { return lhs /= rhs; }

			friend std::ostream& operator<<(std::ostream& lhs, const Scalar& rhs) { return lhs << rhs.scalar_value << '\n'; }

			NODISCARD constexpr value_type Get_Scalar_Value() const;

		};

		template <typename T, typename T0>
		constexpr Scalar<T, T0>::Scalar(const T scalar_value) :
			scalar_value(scalar_value)
		{ }

		template <typename T, typename T0>
		constexpr Scalar<T, T0>::operator T() const noexcept
		{
			return scalar_value;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator+=(const_type rhs) noexcept
		{
			scalar_value = scalar_value + rhs;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator-=(const_type rhs) noexcept
		{
			scalar_value = scalar_value - rhs;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator*=(const_type rhs) noexcept
		{
			scalar_value = scalar_value * rhs;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator/=(const_type rhs) noexcept
		{
			scalar_value = scalar_value / rhs;
			return *this;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator<(const_type rhs) const noexcept
		{
			return scalar_value < rhs;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator>(const_type rhs) const noexcept
		{
			return scalar_value > rhs;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator<=(const_type rhs) const noexcept
		{
			return scalar_value <= rhs;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator>=(const_type rhs) const noexcept
		{
			return scalar_value >= rhs;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator==(const_type rhs) const noexcept
		{
			return scalar_value == rhs;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator!=(const_type rhs) const noexcept
		{
			return !(scalar_value == rhs);
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator+=(const Scalar rhs) noexcept
		{
			scalar_value = scalar_value + rhs.scalar_value;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator-=(const Scalar rhs) noexcept
		{
			scalar_value = scalar_value - rhs.scalar_value;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator*=(const Scalar rhs) noexcept
		{
			scalar_value = scalar_value * rhs.scalar_value;
			return *this;
		}

		template <typename T, typename T0>
		constexpr Scalar<T, T0>& Scalar<T, T0>::operator/=(const Scalar rhs) noexcept
		{
			scalar_value = scalar_value / rhs.scalar_value;
			return *this;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator<(const Scalar rhs) const noexcept
		{
			return scalar_value < rhs.scalar_value;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator>(const Scalar rhs) const noexcept
		{
			return scalar_value > rhs.scalar_value;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator<=(const Scalar rhs) const noexcept
		{
			return scalar_value <= rhs.scalar_value;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator>=(const Scalar rhs) const noexcept
		{
			return scalar_value >= rhs.scalar_value;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator==(const Scalar rhs) const noexcept
		{
			return scalar_value == rhs.scalar_value;
		}

		template <typename T, typename T0>
		constexpr bool Scalar<T, T0>::operator!=(const Scalar rhs) const noexcept
		{
			return !(scalar_value == rhs.scalar_value);
		}
		
		template <typename T, typename T0>
		constexpr T Scalar<T, T0>::Get_Scalar_Value() const
		{
			return scalar_value;
		}

	}

}

#undef HAS_ATTRIBS
#endif /* SCALAR_HPP_INCLUDED */