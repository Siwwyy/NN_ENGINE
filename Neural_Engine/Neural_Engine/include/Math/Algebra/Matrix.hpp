#ifndef _MATRIX_HPP_INCLUDED_
#define _MATRIX_HPP_INCLUDED_
#pragma once

#include <xutility>

namespace Math
{

	template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Matrix
	{
	public:
		Matrix();

	};

}

#endif /* _MATRIX_HPP_INCLUDED_ */