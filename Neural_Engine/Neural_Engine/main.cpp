#include <iostream>
#include <vector>
#include <array>


#include "Math/Algebra/Scalar.hpp"
#include "Math/Algebra/Vector.hpp"
#include "Math/Utils/Math_Utils.hpp"


void foo(NN::Math::Scalar<int> param)
{
	std::cout << param;
}

int (foo1)()
{
	return 1;
}

int main(int argc, char* argv[])
{
	NN::Math::Scalar<int> a(10);
	NN::Math::Scalar<int> v = a / 2;

	//a + 2;

	//NN::Math::Vector<int> vec = {1,2,3,4,5,5,6,7};
	NN::Math::Vector<int> vec;

	NN::Math::Utils::min(vec);
	
	//std::vector<NN::Math::Scalar<int>> aaa;

	//auto hhhh = &*aaa.begin();

	//auto h = NN::Math::Utils::min(vec);

	auto hhh = vec.begin();

	//auto d = foo1;

	//std::begin()
	//std::array<>
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