//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <array>
//#include <iomanip>
//
//
//#include "Math/Algebra/Scalar.hpp"
//#include "Math/Algebra/Tensor.hpp"
//#include "Math/Utils/Math_Utils.hpp"
//#include "Math/Utils/Random.hpp"
//
//#include "Core/Layers/Dense/Dense.hpp"
//#include "Model.hpp"
//#include "Math/Activation_Functions/Identity_Function.hpp"
//#include "Math/Loss_Functions/SEF.hpp"
//
//
////void foo(NN::Math::Scalar<int> param)
////{
////	std::cout << param;
////}
////
////int (foo1)()
////{
////	return 1;
////}
////
////
////
////struct Point
////{
//////private:
////	int x;
////	int y;
////
////public:
////	constexpr friend bool operator==(Point a, Point b)
////	{
////		return a.x == b.x && a.y == b.y;
////	}
////};
//
//template <typename T, typename U, typename = std::enable_if_t<std::is_arithmetic_v<T> && std::is_arithmetic_v<U>>>
//struct my_pair
//{
//	T first;
//	U second;
//
//	my_pair() = default;
//
//	my_pair(T first, U second) :
//		first(first),
//		second(second)
//	{
//	}
//};
//
//float halton(const int32_t index, const int32_t base)
//{
//	float result = 0.f;
//	float f = 1.f;
//	std::size_t i = index;
//
//	while (i > 0)
//	{
//		f /= static_cast<float>(base);
//		result += f * static_cast<float>((i % base));
//		i /= static_cast<std::size_t>(base);
//	}
//
//	return result;
//}
//
//using type = float_t;
//
//my_pair<type, type> halton_idx(const int32_t idx, const int32_t scale)
//{
//	//return my_pair<type, type>(static_cast<type>(scale * halton(idx, 2)), static_cast<type>(scale * halton(idx, 3)));
//	return my_pair<type, type>(static_cast<type>(halton(idx, 2)), static_cast<type>(halton(idx, 3)));
//}
//
//std::vector<my_pair<type, type>> halton_seq(const int32_t length, const int32_t scale)
//{
//	type idx = 0;
//	std::vector<my_pair<type, type>> halton_sequence(length); //DAndrysiak: Vector of halton sequence (x,y)
//	std::generate_n(halton_sequence.begin(), length, [&]()
//	{
//		idx++;
//		return halton_idx(idx, scale);
//	}); //DAndrysiak: idx++, We start from 1st element of halton, not 0th
//	return halton_sequence;
//}
//
//
//int main(int argc, char* argv[])
//{
//	////halton_seq(8, 6);
//	//auto d =  halton_seq(8, 6);
//
//	//for (const auto& elem : d)
//	//{
//	//	std::cout << elem.first/6 << ' ' << elem.second/6 << '\n';
//	//}
//
//	using current_type = float;
//
//	NN::Math::Algebra::Tensor_Arithmetic<current_type> weights = {
//		0.15f, 0.20f, 0.25f, 0.30f, 0.40f, 0.45f, 0.50f, 0.55f
//	};
//	
//	NN::Math::Algebra::Tensor_Arithmetic_2D<current_type> train_data = { {0.05f, 0.10f} };
//	NN::Math::Algebra::Tensor_Arithmetic_2D<current_type> test_data = { {0.01f, 0.99f} };
//	
//
//	//NN::Model::Model<current_type> Mod;
//
//	//Mod.add_layer(NN::Core::Layers::Dense<current_type>(
//	//	2, NN::Math::Activation_Functions::Identity_Function<current_type>(), {0.15f, 0.20f, 0.25f, 0.30f}));
//	//Mod.add_layer(NN::Core::Layers::Dense<current_type>(
//	//	2, NN::Math::Activation_Functions::Identity_Function<current_type>(), {0.40f, 0.45f, 0.50f, 0.55f},
//	//	{0.35f, 0.35f}));
//	//Mod.add_layer(
//	//	NN::Core::Layers::Dense<current_type>(2, NN::Math::Activation_Functions::Identity_Function<current_type>(), {},
//	//	                                      {0.6f, 0.6f}));
//
//	////Mod.add_layer(NN::Core::Layers::Dense<current_type>(2, NN::Math::Activation_Functions::Identity_Function<current_type>()));
//	////Mod.add_layer(NN::Core::Layers::Dense<current_type>(2, NN::Math::Activation_Functions::Identity_Function<current_type>()));
//	////Mod.add_layer(NN::Core::Layers::Dense<current_type>(2, NN::Math::Activation_Functions::Identity_Function<current_type>()));
//
//	//Mod.compile(NN::Math::Loss_Functions::SEF<current_type>());
//
//	//Mod.learn(&train_data, &test_data);
//
//
//	//auto dddd = NN::Core::Layers::Dense<current_type>(2, NN::Math::Activation_Functions::Sigmoid<current_type>{});
//	//Mod.compile(NN::Math::Loss_Functions::)
//
//	//#include "Math/Utils/Math_Utils.hpp"
//	//
//	//	auto d = NN::Math::Utils::pow(NN::Math::Scalar<int>(10), 2);
//	//	//auto d = NN::Math::Utils::pow(0, 2);
//	//
//	//	int c = NN::Math::Scalar<int>(10);
//	//
//	//	int a{};
//
//
//	//auto out = halton_seq(8, 3);
//
//	//for (const auto& elem : out)
//	//{
//	//	std::cout << "[ " << elem.first << " , " << elem.second << " ]\n";
//	//}
//
//
//	//NN::Math::Scalar<int> a(10);
//	//NN::Math::Scalar<int> v = a / 2;
//
//	////a + 2;
//
//	//NN::Math::Vector<int> vec = { 1,2,3,4,5,5,6,7 };
//	////NN::Math::Vector<int> vec;
//	//std::vector dddddd{ 1,2,3,4,5,5 };
//
//	//auto dadad = dddddd[3];
//	//auto dsd = NN::Math::Utils::min(vec);
//	//dsd = NN::Math::Utils::max(vec);
//
//	//auto ddd = vec.begin();
//
//	//std::vector<NN::Math::Scalar<int>> aaa;
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
//
//	//NN::Math::Scalar<float> scalar_f = NN::Math::Utils::generate_random_numberF(0.f, 10.f);
//	//NN::Math::Vector<float> vec_f = NN::Math::Utils::generate_random_numbersF(0.f, 10.f,10);
//
//	//NN::Math::Scalar<int> scalar_i = NN::Math::Utils::generate_random_numberI(0, 10);
//	//NN::Math::Vector<int> vec_i = NN::Math::Utils::generate_random_numbersI(0, 10, 10);
//	//NN::Math::Vector<int> vec{};
//
//
//	//	//Creating a circle
//	//	//Rotate around the origin point 0.0
//	//#include <cmath>
//	//
//	//#define PI 3.14159265f
//	//
//	//	constexpr float radius = 5.f;
//	//	constexpr float angle = 20.f;
//	//	constexpr std::size_t points_amount = 10;
//	//
//	//	std::pair<float, float> vec{ 0.f, radius };
//	//	std::vector<std::pair<float, float>> points;
//	//
//	//	for (size_t i = 0; i < points_amount; ++i)
//	//	{
//	//		if (i == 0)
//	//		{
//	//			points.emplace_back(vec);
//	//		}
//	//		else
//	//		{
//	//			const float a = std::cos((angle * PI) / 180.f) * vec.first + ((-1 * std::sin((angle * PI) / 180.f)) * vec.second);
//	//			const float b = std::sin((angle * PI) / 180.f) * vec.first + (std::cos((angle * PI) / 180.f) * vec.second);
//	//			vec.first = a;
//	//			vec.second = b;
//	//			points.emplace_back(vec);
//	//		}
//	//	}
//	//
//	//	for (size_t i = 0; i < points_amount; ++i)
//	//	{
//	//		std::cout << "X: " << points[i].first << " Y: " << points[i].second << '\n';
//	//	}
//
//
//	system("pause");
//	return EXIT_SUCCESS;
//}

////
////////SIMPLE PERCEPTRON
//////
//////
//////#include <iostream>
//////#include <string>
//////#include <iterator>
//////#include <type_traits>
//////#include <vector>
//////#include <random>
//////
//////using type = float_t;
//////using container_type = std::pair<type, type>;
//////using container = std::vector<container_type>;
//////
//////template<typename T = type>
//////container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max);
//////template<typename T = type>
//////container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::true_type);
//////template<typename T = type>
//////container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::false_type);
//////
//////container_type generate_data_point(const type x_min, const type x_max, const type y_min, const type y_max);
//////container generate_dataset(const size_t size);
//////
//////type sign(const type value);
//////float generate_weight_value();
//////bool validation(const float* const values, const bool* const true_values);
//////
//////int main(int argc, char* argv[])
//////{
//////
//////	container training_dataset = generate_dataset(200);
//////	auto w1 = generate_weight_value();
//////	auto w2 = generate_weight_value();
//////
//////
//////	//auto a = std::min_element(training_dataset.begin(), training_dataset.end(), [](auto lhs, auto rhs)
//////	//	{
//////	//		return std::get<1>(lhs) > std::get<1>(rhs);
//////	//	});
//////
//////
//////	constexpr float E = 0.0001f;
//////	constexpr float learning_rate = 0.1f;
//////	bool learning = true;
//////
//////	while (learning)
//////	{
//////		learning = false;
//////
//////		for (size_t i = 0; i < training_dataset.size(); ++i)
//////		{
//////			auto point = training_dataset[i];
//////			float u = (w1 * point.first) + (w2 * point.second);
//////			float y = sign(u);
//////
//////			if (point.second < 0.f && y > 0.f)
//////			{
//////				w1 = w1 - learning_rate * point.first;
//////				w2 = w2 - learning_rate * point.second;
//////				learning = true;
//////			}
//////			else if (point.second > 0.f && y < 0.f)
//////			{
//////				w1 = w1 + learning_rate * point.first;
//////				w2 = w2 + learning_rate * point.second;
//////				learning = true;
//////			}
//////		}
//////
//////
//////	}
//////
//////	std::cout << "Learned first weight: " << w1 << '\n';
//////	std::cout << "Learned second weight: " << w2 << '\n';
//////
//////
//////	container test_dataset = { std::make_pair(1.f, 1.f), std::make_pair(1.f, -1.f), std::make_pair(1.f, 2.f), std::make_pair(1.f, -2.f) };
//////
//////	const float test_values[] = { test_dataset[0].second * w2, test_dataset[1].second * w2,test_dataset[2].second * w2, test_dataset[3].second * w2 };
//////	const bool true_values[] = { 1, 0, 1, 0 };
//////	bool values_dataset[] = { 0,0,0,0 };
//////
//////
//////	for (size_t i = 0; i < 4; ++i)
//////	{
//////		if (test_dataset[i].second * w2 <= 0)
//////		{
//////			values_dataset[i] = false;
//////		}
//////		else
//////		{
//////			values_dataset[i] = true;
//////		}
//////	}
//////
//////	auto ddd = 0.00001f * w2;
//////	system("pause");
//////	return EXIT_SUCCESS;
//////}
//////
////
////
//SIMPLE BACKPROP NETWORK 2-2-2


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>
#include <Windows.h>

using type = float_t;
using container_type = std::pair<type, type>;
using container = std::vector<container_type>;

using type_precision = std::numeric_limits<type>;



auto sigm(const type x) -> type
{
	return 1 / (1 + std::exp(-1 * x));
}

auto d_sigm(const type x) -> type
{
	return x * (1 - x);
}

type id(const type x)
{
	return x;
}

type d_id(const type x)
{
	return x;
}

template<typename T, std::size_t N>
constexpr std::size_t arr_size(T(&array)[N]) noexcept
{
	return N;
}

type generate_weight_value()
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<float> distribution(0.05f, 0.95f);
	return distribution(random_generator);
}

std::unique_ptr<type[]> generate_weight_list(const size_t size)
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<float> distribution(0.05f, 0.95f);

	auto weights = std::unique_ptr<type[]>(new type[size]);
	auto random_float = [&] { return distribution(random_generator); };
	std::generate_n(weights.get(), size, random_float);
	return weights;
}

type accumulate_weight(const type* const weights, const type value, const std::size_t amount)
{
	//return static_cast<type>(std::accumulate(weights, weights + amount, 0));
	type sum{};
	for (std::size_t i = 0; i < amount; ++i)
	{
		sum += value * weights[i];
	}
	return sum;
}




bool gradient_correctness()
{
	return true;
}

void forward(type * t, type output[1][2], const std::unique_ptr<type[]>& w, type * biases, type* out_h, type* out_o)
{
	constexpr size_t I = 2;	//2 Input layers
	constexpr size_t J = 2;	//2 Hidden layers
	constexpr size_t K = 2;	//2 Output layers
	type E_Iter{};
	
	for (std::size_t o = 0; o < K; ++o)
	{
		type net_o{};
		for (std::size_t h = 0; h < J; ++h)
		{
			type net_h{};
			for (std::size_t i = 0; i < I; ++i)
			{
				const std::size_t w_id_i = i + h * J;
				net_h += w[w_id_i] * t[i];
			}
			net_h += biases[h];
			out_h[h] = sigm(net_h);

			const std::size_t w_id_h = o * K + (K * J + h);
			net_o += w[w_id_h] * out_h[h];
		}
		net_o += biases[o + J];
		out_o[o] = sigm(net_o);

		E_Iter += 0.5f * std::powf((output[0][o] - out_o[o]), 2);
	}
}


int main(int argc, char* argv[])
{
	//Inputs
	type input[][2] = { {0.05f, 0.10f} };
	constexpr size_t T = arr_size(input); //amount of associations
	//Targets
	type targets[][2] = { {0.01f, 0.99f} };
	//Amounts of layer in network, net		ork properties
	constexpr size_t I = 2;	//2 Input layers
	constexpr size_t J = 2;	//2 Hidden layers
	constexpr size_t K = 2;	//2 Output layers
	constexpr size_t iterations = 1000;
	constexpr type lr = 0.01f;

	constexpr std::size_t w_size = 8;
	//type w[] = { 0.15f, 0.20f, 0.25f, 0.30f, 0.40f, 0.45f, 0.50f, 0.55f };
	auto w = generate_weight_list(w_size);
	//type w[] = { 21.15f, 22.2250f, 23.25f, 24.3250f, 25.4250f, 26.45f, 27.5250f, 28.55f };
	constexpr std::size_t b_size = 4;
	//type biases[] = { 0.35f, 0.35f, 0.60f, 0.60f };
	type biases[] = { 1.f, 1.f, 1.5f, 1.5f };

	
	type Total_Error{};
	for (size_t iter = 0; iter < iterations; ++iter)
	{
		type E_Iter{};

		type* grad_E_total_w = new type[w_size]{};
		type* grad_E_total_b = new type[b_size]{};
		for (auto& t : input)
		{
			//Forwardpropagation
			type* out_h = new type[J]{};
			type* out_o = new type[K]{};
			for (std::size_t o = 0; o < K; ++o)
			{
				type net_o{};
				for (std::size_t h = 0; h < J; ++h)
				{
					type net_h{};
					for (std::size_t i = 0; i < I; ++i)
					{
						const std::size_t w_id_i = i + h * J;
						net_h += w[w_id_i] * t[i];
					}
					net_h += biases[h];
					out_h[h] = sigm(net_h);

					const std::size_t w_id_h = o * K + (K * J + h);
					net_o += w[w_id_h] * out_h[h];
				}
				net_o += biases[o + J];
				out_o[o] = sigm(net_o);

				E_Iter += 0.5f * std::powf((targets[0][o] - out_o[o]), 2);
			}

			//forward(t, targets, w, biases, out_h, out_o);

			
			//Backpropagation
			type* delta_o = new type[K]{};

			//Calculate delta terms for Output units
			for (std::size_t o = 0; o < K; ++o)
			{
				delta_o[o] += -1 * (targets[0][o] - out_o[o]) * d_sigm(out_o[o]);

				//calculate gradient of weights between hidden and output layer/s
				for (std::size_t h = 0; h < J; ++h)
				{
					const std::size_t w_id_h = o * J + (J * J + h);
					grad_E_total_w[w_id_h] += delta_o[o] * out_h[h];
				}
				//calculate gradients of biases of output layers
				grad_E_total_b[o + J] += delta_o[o] * 1;
			}

			type* delta_h = new type[J]{};
			//Calculate delta terms for Hidden units
			for (std::size_t h = 0; h < J; ++h)
			{
				for (std::size_t o = 0; o < K; ++o)
				{
					const std::size_t w_id_h = o * J + (J * J + h);
					delta_h[h] += delta_o[o] * w[w_id_h];
				}
				delta_h[h] *= d_sigm(out_h[h]);

				//calculate gradient of weights between input and hidden layer/s
				for (std::size_t i = 0; i < I; ++i)
				{
					const std::size_t w_id_i = i + h * J;
					grad_E_total_w[w_id_i] += delta_h[h] * t[i];
				}
				//calculate gradients of biases of hidden layers
				grad_E_total_b[h] += delta_h[h] * 1;
			}


			//Gradient Checking









			
			delete[] out_h;
			delete[] out_o;
			delete[] delta_o;
			delete[] delta_h;
		}


		std::cout.precision(type_precision::max_digits10);
		//std::cout << "Total error: " << E_Iter << '\n';
		//for (const auto& i : w)
		//{
		//	std::cout << i << ' ';
		//}
		//Sleep(100);
		//system("cls");
		Total_Error = E_Iter;
		//Update weights
		for (std::size_t w_idx = 0; w_idx < w_size; w_idx++)
		{
			w[w_idx] = w[w_idx] - lr * grad_E_total_w[w_idx];
		}

		//Update biases
		for (std::size_t b_idx = 0; b_idx < b_size; b_idx++)
		{
			biases[b_idx] = biases[b_idx] - lr * grad_E_total_b[b_idx];
		}
		
		//for (const auto& i : w)
		//{
		//	std::cout << i << '\n';
		//}
		//system("pause");
		delete[] grad_E_total_w;
	}

	//std::cout << "Weights: \n";
	//for (std::size_t w_idx = 0; w_idx < w_size; w_idx++)
	//{
	//	std::cout << w[w_idx] << '\n';
	//}
	//std::cout << "Biases: \n";
	//for (std::size_t b_idx = 0; b_idx < b_size; b_idx++)
	//{
	//	std::cout << biases[b_idx] << '\n';
	//}

	std::cout << "Total error: " << Total_Error << '\n';

	
	system("pause");
	return EXIT_SUCCESS;
}


//
//#include <iostream>
//#include <vector>
//#include <ranges>
//#include <concepts>
//#include <type_traits>
//#include <vector>
//
//template <std::ranges::range Rng>
//auto deep_flatten_impl(Rng&& range)
//{
//	using value_type = std::decay_t<std::ranges::range_value_t<Rng>>;
//	if constexpr (std::ranges::range<value_type>)
//	{
//		for (auto&& subrange : range)
//		{
//			deep_flatten_impl(subrange);
//		}
//	}
//	else
//	{
//		std::cout << "D\n";
//		for (const auto& element : range)
//		{
//			std::cout << element << ' ';
//		}
//	}
//}
//
//int main()
//{
//	const auto vec = std::vector<std::vector<std::vector<std::vector<int>>>>{ {
//		{{1, 2}, {3, 4}},
//		{{5, 6}},
//		{{7, 8}, {9, 10, 11}},
//		{{12}}
//	} };
//
//	deep_flatten_impl(vec);
//
//	int a = 10;
//
//
//	system("pause");
//	return EXIT_SUCCESS;
//}