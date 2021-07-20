#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#pragma once

#include <xutility>

namespace NN
{
	
	namespace Math
	{

		template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
		class Matrix
		{
		public:
			Matrix();

		};

	}

}

#endif /* MATRIX_HPP_INCLUDED */