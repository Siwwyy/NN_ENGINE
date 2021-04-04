#include <iostream>
#include <vector>
#include <array>


#include "Math/Algebra/Scalar.hpp"


void foo(Math::Scalar<int> param)
{
	std::cout << param;
}


int main(int argc, char* argv[])
{
	Math::Scalar<int> a(10);
	Math::Scalar<int> v = a / 2;


	if(a == v)
	{
		
	}

	if (a != v)
	{

	}
	
	if (a > v)
	{

	}
	//Math::Scalar<int> b = a + 2;

	//foo(Math::Scalar<int>(10) - Math::Scalar<int>(10));

	//std::array<int, 10> ddd{};
	//
	////int g = static_cast<int>(a);

	//std::vector<int> h{};

	//a = 2 * 2;

	system("pause");
	return EXIT_SUCCESS;
}