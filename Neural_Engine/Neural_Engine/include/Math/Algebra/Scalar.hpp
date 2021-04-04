#ifndef _SCALAR_HPP_INCLUDED_
#define _SCALAR_HPP_INCLUDED_
#pragma once

#include <ostream>
#include <xutility>

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

		constexpr explicit operator value_type() const;

		constexpr void operator+=(const_type rhs) noexcept;
		constexpr void operator-=(const_type rhs) noexcept;
		constexpr void operator*=(const_type rhs) noexcept;
		constexpr void operator/=(const_type rhs) noexcept;
		constexpr bool operator<(const_type rhs) const noexcept;
		constexpr bool operator>(const_type rhs) const noexcept;
		constexpr bool operator==(const_type rhs) const noexcept;
		constexpr bool operator!=(const_type rhs) const noexcept;

		constexpr void operator+=(const Scalar rhs) noexcept;
		constexpr void operator-=(const Scalar rhs) noexcept;
		constexpr void operator*=(const Scalar rhs) noexcept;
		constexpr void operator/=(const Scalar rhs) noexcept;
		constexpr bool operator<(const Scalar rhs) const noexcept;
		constexpr bool operator>(const Scalar rhs) const noexcept;
		constexpr bool operator==(const Scalar rhs) const noexcept;
		constexpr bool operator!=(const Scalar rhs) const noexcept;

		friend constexpr Scalar<value_type, void> operator+(const Scalar lhs, const_type rhs) noexcept { return Scalar(lhs.scalar_value + rhs); }
		friend constexpr Scalar<value_type, void> operator-(const Scalar lhs, const_type rhs) noexcept { return Scalar(lhs.scalar_value - rhs); }
		friend constexpr Scalar<value_type, void> operator*(const Scalar lhs, const_type rhs) noexcept { return Scalar(lhs.scalar_value * rhs); }
		friend constexpr Scalar<value_type, void> operator/(const Scalar lhs, const_type rhs) noexcept { return Scalar(lhs.scalar_value / rhs); }

		friend constexpr Scalar<value_type, void> operator+(const_type lhs, const Scalar rhs) noexcept { return Scalar(rhs.scalar_value + lhs); }
		friend constexpr Scalar<value_type, void> operator-(const_type lhs, const Scalar rhs) noexcept { return Scalar(rhs.scalar_value - lhs); }
		friend constexpr Scalar<value_type, void> operator*(const_type lhs, const Scalar rhs) noexcept { return Scalar(rhs.scalar_value * lhs); }
		friend constexpr Scalar<value_type, void> operator/(const_type lhs, const Scalar rhs) noexcept { return Scalar(rhs.scalar_value / lhs); }

		friend constexpr Scalar<value_type, void> operator+(const Scalar lhs, const Scalar rhs) noexcept { return Scalar(lhs.scalar_value + rhs.scalar_value); }
		friend constexpr Scalar<value_type, void> operator-(const Scalar lhs, const Scalar rhs) noexcept { return Scalar(lhs.scalar_value - rhs.scalar_value); }
		friend constexpr Scalar<value_type, void> operator*(const Scalar lhs, const Scalar rhs) noexcept { return Scalar(lhs.scalar_value * rhs.scalar_value); }
		friend constexpr Scalar<value_type, void> operator/(const Scalar lhs, const Scalar rhs) noexcept { return Scalar(lhs.scalar_value / rhs.scalar_value); }

		template <typename T, typename T0>
		friend std::ostream& operator<<(std::ostream& lhs, const Scalar<T, T0>& rhs);

		constexpr value_type Get_Scalar_Value() const&&;
		constexpr reference_type Get_Scalar_Value() const&;

	};

	template <typename T, typename T0>
	constexpr Scalar<T, T0>::Scalar(const T scalar_value) :
		scalar_value(scalar_value)
	{ }

	template <typename T, typename T0>
	constexpr Scalar<T, T0>::operator T() const
	{
		return scalar_value;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator+=(const_type rhs) noexcept
	{
		scalar_value = scalar_value + rhs;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator-=(const_type rhs) noexcept
	{
		scalar_value = scalar_value - rhs;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator*=(const_type rhs) noexcept
	{
		scalar_value = scalar_value * rhs;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator/=(const_type rhs) noexcept
	{
		scalar_value = scalar_value / rhs;
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
	constexpr void Scalar<T, T0>::operator+=(const Scalar rhs) noexcept
	{
		scalar_value = scalar_value + rhs.scalar_value;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator-=(const Scalar rhs) noexcept
	{
		scalar_value = scalar_value - rhs.scalar_value;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator*=(const Scalar rhs) noexcept
	{
		scalar_value = scalar_value * rhs.scalar_value;
	}

	template <typename T, typename T0>
	constexpr void Scalar<T, T0>::operator/=(const Scalar rhs) noexcept
	{
		scalar_value = scalar_value / rhs.scalar_value;
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
	inline std::ostream& operator<<(std::ostream& lhs, const Scalar<T, T0>& rhs)
	{
		lhs << rhs.scalar_value << '\n';
		return lhs;
	}

	template <typename T, typename T0>
	constexpr T Scalar<T, T0>::Get_Scalar_Value() const&&
	{
		return scalar_value;
	}

	template <typename T, typename T0>
	constexpr T& Scalar<T, T0>::Get_Scalar_Value() const&
	{
		return scalar_value;
	}

}

#endif /* _SCALAR_HPP_INCLUDED_ */