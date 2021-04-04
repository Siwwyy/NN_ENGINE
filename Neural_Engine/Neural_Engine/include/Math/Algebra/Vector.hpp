#ifndef _VECTOR_HPP_INCLUDED_
#define _VECTOR_HPP_INCLUDED_
#pragma once

#include <vector>
#include <xutility>

#include "Scalar.hpp"

namespace Math
{

	template<typename T>
	class Vector : private Scalar<T>
	{
	public:
		
		using value_type = Scalar<T>;
		using pointer_type = Scalar<T>*;
		using reference_type = Scalar<T>&;

	private:
		
		std::vector<value_type> vector;
	
	public:
		Vector() = delete;

	};

}

#endif /* _VECTOR_HPP_INCLUDED */