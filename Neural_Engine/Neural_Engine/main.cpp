//#include <iostream>
//#include <vector>
//#include <array>
//
//
//#include "Math/Algebra/Scalar.hpp"
//#include "Math/Algebra/Vector.hpp"
//#include "Math/Utils/Math_Utils.hpp"
//
//
//void foo(NN::Math::Scalar<int> param)
//{
//	std::cout << param;
//}
//
//int (foo1)()
//{
//	return 1;
//}
//
//
//
//struct Point
//{
////private:
//	int x;
//	int y;
//
//public:
//	constexpr friend bool operator==(Point a, Point b)
//	{
//		return a.x == b.x && a.y == b.y;
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	//NN::Math::Scalar<int> a(10);
//	//NN::Math::Scalar<int> v = a / 2;
//
//	////a + 2;
//
//	////NN::Math::Vector<int> vec = {1,2,3,4,5,5,6,7};
//	//NN::Math::Vector<int> vec;
//
//	//NN::Math::Utils::min(vec);
//	//
//	////std::vector<NN::Math::Scalar<int>> aaa;
//
//	////auto hhhh = &*aaa.begin();
//
//	////auto h = NN::Math::Utils::min(vec);
//
//	//auto hhh = vec.begin();
//
//	//auto d = foo1;
//
//	//std::begin()
//	//std::array<>
//	//Math::Scalar<int> b = a + 2;
//
//	//foo(Math::Scalar<int>(10) - Math::Scalar<int>(10));
//
//	//std::array<int, 10> ddd{};
//	//
//	////int g = static_cast<int>(a);
//
//	//std::vector<int> h{};
//
//	//a = 2 * 2;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}



//#include <iostream>
//#include <string>
//#include <iterator>
//#include <charconv>
//
//
//void format_str(std::string& left, std::string& right);
//void addition(const std::string& first, const std::string& second);
//
//
//int main(int argc, char* argv[])
//{
//	std::string first = "999";
//	std::string second = "111";
//	format_str(first, second);
//	std::string third{};
//	addition(first, second);
//	std::cout << '\n';
//
//
//
//	system("pause");
//	return EXIT_SUCCESS;
//}
//
//void format_str(std::string& left, std::string& right)
//{
//	if (left.size() == right.size())
//	{
//		return;
//	}
//	else if (left.size() > right.size())
//	{
//		const auto fill_length = left.size() - right.size();
//		for (auto i = 0; i < fill_length; ++i)
//		{
//			right.insert(std::cbegin(right), '0');
//		}
//	}
//	else if (left.size() < right.size())
//	{
//		const auto fill_length = right.size() - left.size();
//		for (auto i = 0; i < fill_length; ++i)
//		{
//			left.insert(std::cbegin(left), '0');
//		}
//	}
//}
//
//void addition(const std::string& first, const std::string& second)
//{
//	std::string result_string{};
//	bool in_memory{ false };
//
//	for (auto i = static_cast<int32_t>(first.size() - 1); i >= 0; --i)
//	{
//		auto first_int_val{ 0 };
//		auto second_int_val{ 0 };
//		std::from_chars(&first[i], &first[i] + 1, first_int_val);
//		std::from_chars(&second[i], &second[i] + 1, second_int_val);
//
//
//		auto addition_result = first_int_val + second_int_val;
//		if (static_cast<float>(addition_result) / 10.f < 1.f)
//		{
//			if (in_memory)
//			{
//				addition_result += 1;
//			}
//			if (addition_result > 9)
//			{
//				in_memory = true;
//			}
//			result_string.append(std::to_string(addition_result % 10));
//		}
//		else
//		{
//			addition_result %= 10;
//			if (in_memory)
//			{
//				addition_result += 1;
//			}
//			in_memory = true;
//			result_string.append(std::to_string(addition_result));
//		}
//	}
//	if (in_memory)
//	{
//		result_string.append(std::to_string(1));
//	}
//	std::reverse(result_string.begin(), result_string.end());
//
//	std::cout << "Addition result: " << result_string << '\n';
//}


//SIMPLE PERCEPTRON


#include <iostream>
#include <string>
#include <iterator>
#include <type_traits>
#include <vector>
#include <random>

using type = int8_t;
using container_type = std::pair<type, type>;
using container = std::vector<container_type>;

template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max);
template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::true_type);
template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::false_type);

container generate_dataset(const size_t size);


int main(int argc, char* argv[])
{

	container training_dataset = generate_dataset(200);


	system("pause");
	return EXIT_SUCCESS;
}

template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max)
{
	return data_point(x_min, x_max, y_min, y_max, std::conditional_t<std::is_floating_point_v<T>, std::true_type, std::false_type>{});
}

template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::true_type)
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<T> distribution_x(x_min, x_max);
	const std::uniform_real_distribution<T> distribution_y(y_min, y_max);

	return container_type(distribution_x(random_generator), distribution_y(random_generator));
}

template<typename T = type>
container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::false_type)
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_int_distribution<T> distribution_x(x_min, x_max);
	const std::uniform_int_distribution<T> distribution_y(y_min, y_max);

	return container_type(distribution_x(random_generator), distribution_y(random_generator));
}

container generate_dataset(const size_t size)
{
	container dataset{};

	for (size_t i = 0; i < size; ++i)
	{
		dataset.emplace_back(data_point(-2, 2, -2, 2));
	}

	return dataset;
}
