#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <iomanip>



#include "Math/Algebra/Scalar.hpp"
#include "Math/Algebra/Vector.hpp"
#include "Math/Utils/Math_Utils.hpp"
#include "Math/Utils/Random.hpp"

#include "Layers/Dense/Dense.hpp"
#include "Model.hpp"


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

template<typename T, typename U, typename = std::enable_if_t<std::is_arithmetic_v<T>&& std::is_arithmetic_v<U>>>
struct my_pair
{
	T first;
	U second;

	my_pair() = default;
	my_pair(T first, U second) :
		first(first),
		second(second)
	{ }
};

float halton(const int32_t index, const int32_t base)
{
	float result = 0.f;
	float f = 1.f;
	std::size_t i = index;

	while (i > 0)
	{
		f /= static_cast<float>(base);
		result += f * static_cast<float>((i % base));
		i /= static_cast<std::size_t>(base);
	}

	return result;
}

my_pair<int32_t, int32_t> halton_idx(const int32_t idx, const int32_t scale)
{
	using type = int32_t;
	return my_pair<type, type>(static_cast<type>(scale * halton(idx, 2)), static_cast<type>(scale * halton(idx, 3)));
}

std::vector<my_pair<int32_t, int32_t>> halton_seq(const int32_t length, const int32_t scale)
{
	using type = int32_t;
	type idx = 0;
	std::vector<my_pair<type, type>> halton_sequence(length); //DAndrysiak: Vector of halton sequence (x,y)
	std::generate_n(halton_sequence.begin(), length, [&]() { idx++; return halton_idx(idx, scale); });	//DAndrysiak: idx++, We start from 1st element of halton, not 0th
	return halton_sequence;
}



int main(int argc, char* argv[])
{
	using current_type = float;
	NN::Model::Model<current_type> Mod{};

	Mod.add_layer(NN::Layers::Dense<current_type>(3));
	Mod.add_layer(NN::Layers::Dense<current_type>(3));
	Mod.add_layer(NN::Layers::Dense<current_type>(3));
	

//#include "Math/Utils/Math_Utils.hpp"
//
//	auto d = NN::Math::Utils::pow(NN::Math::Scalar<int>(10), 2);
//	//auto d = NN::Math::Utils::pow(0, 2);
//
//	int c = NN::Math::Scalar<int>(10);
//
//	int a{};


	//auto out = halton_seq(8, 3);

	//for (const auto& elem : out)
	//{
	//	std::cout << "[ " << elem.first << " , " << elem.second << " ]\n";
	//}



	//NN::Math::Scalar<int> a(10);
	//NN::Math::Scalar<int> v = a / 2;

	////a + 2;

	//NN::Math::Vector<int> vec = { 1,2,3,4,5,5,6,7 };
	////NN::Math::Vector<int> vec;
	//std::vector dddddd{ 1,2,3,4,5,5 };

	//auto dadad = dddddd[3];
	//auto dsd = NN::Math::Utils::min(vec);
	//dsd = NN::Math::Utils::max(vec);

	//auto ddd = vec.begin();

	//std::vector<NN::Math::Scalar<int>> aaa;

	////auto hhhh = &*aaa.begin();

	////auto h = NN::Math::Utils::min(vec);

	//auto hhh = vec.begin();

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


	//NN::Math::Scalar<float> scalar_f = NN::Math::Utils::generate_random_numberF(0.f, 10.f);
	//NN::Math::Vector<float> vec_f = NN::Math::Utils::generate_random_numbersF(0.f, 10.f,10);

	//NN::Math::Scalar<int> scalar_i = NN::Math::Utils::generate_random_numberI(0, 10);
	//NN::Math::Vector<int> vec_i = NN::Math::Utils::generate_random_numbersI(0, 10, 10);
	//NN::Math::Vector<int> vec{};




//	//Creating a circle
//	//Rotate around the origin point 0.0
//#include <cmath>
//
//#define PI 3.14159265f
//
//	constexpr float radius = 5.f;
//	constexpr float angle = 20.f;
//	constexpr std::size_t points_amount = 10;
//
//	std::pair<float, float> vec{ 0.f, radius };
//	std::vector<std::pair<float, float>> points;
//
//	for (size_t i = 0; i < points_amount; ++i)
//	{
//		if (i == 0)
//		{
//			points.emplace_back(vec);
//		}
//		else
//		{
//			const float a = std::cos((angle * PI) / 180.f) * vec.first + ((-1 * std::sin((angle * PI) / 180.f)) * vec.second);
//			const float b = std::sin((angle * PI) / 180.f) * vec.first + (std::cos((angle * PI) / 180.f) * vec.second);
//			vec.first = a;
//			vec.second = b;
//			points.emplace_back(vec);
//		}
//	}
//
//	for (size_t i = 0; i < points_amount; ++i)
//	{
//		std::cout << "X: " << points[i].first << " Y: " << points[i].second << '\n';
//	}




	system("pause");
	return EXIT_SUCCESS;
}


////SIMPLE PERCEPTRON
//
//
//#include <iostream>
//#include <string>
//#include <iterator>
//#include <type_traits>
//#include <vector>
//#include <random>
//
//using type = float_t;
//using container_type = std::pair<type, type>;
//using container = std::vector<container_type>;
//
//template<typename T = type>
//container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max);
//template<typename T = type>
//container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::true_type);
//template<typename T = type>
//container_type data_point(const T x_min, const T x_max, const T y_min, const T y_max, std::false_type);
//
//container_type generate_data_point(const type x_min, const type x_max, const type y_min, const type y_max);
//container generate_dataset(const size_t size);
//
//type sign(const type value);
//float generate_weight_value();
//bool validation(const float* const values, const bool* const true_values);
//
//int main(int argc, char* argv[])
//{
//
//	container training_dataset = generate_dataset(200);
//	auto w1 = generate_weight_value();
//	auto w2 = generate_weight_value();
//
//
//	//auto a = std::min_element(training_dataset.begin(), training_dataset.end(), [](auto lhs, auto rhs)
//	//	{
//	//		return std::get<1>(lhs) > std::get<1>(rhs);
//	//	});
//
//
//	constexpr float E = 0.0001f;
//	constexpr float learning_rate = 0.1f;
//	bool learning = true;
//
//	while (learning)
//	{
//		learning = false;
//
//		for (size_t i = 0; i < training_dataset.size(); ++i)
//		{
//			auto point = training_dataset[i];
//			float u = (w1 * point.first) + (w2 * point.second);
//			float y = sign(u);
//
//			if (point.second < 0.f && y > 0.f)
//			{
//				w1 = w1 - learning_rate * point.first;
//				w2 = w2 - learning_rate * point.second;
//				learning = true;
//			}
//			else if (point.second > 0.f && y < 0.f)
//			{
//				w1 = w1 + learning_rate * point.first;
//				w2 = w2 + learning_rate * point.second;
//				learning = true;
//			}
//		}
//
//
//	}
//
//	std::cout << "Learned first weight: " << w1 << '\n';
//	std::cout << "Learned second weight: " << w2 << '\n';
//
//
//	container test_dataset = { std::make_pair(1.f, 1.f), std::make_pair(1.f, -1.f), std::make_pair(1.f, 2.f), std::make_pair(1.f, -2.f) };
//
//	const float test_values[] = { test_dataset[0].second * w2, test_dataset[1].second * w2,test_dataset[2].second * w2, test_dataset[3].second * w2 };
//	const bool true_values[] = { 1, 0, 1, 0 };
//	bool values_dataset[] = { 0,0,0,0 };
//
//
//	for (size_t i = 0; i < 4; ++i)
//	{
//		if (test_dataset[i].second * w2 <= 0)
//		{
//			values_dataset[i] = false;
//		}
//		else
//		{
//			values_dataset[i] = true;
//		}
//	}
//
//	auto ddd = 0.00001f * w2;
//	system("pause");
//	return EXIT_SUCCESS;
//}
//


////SIMPLE BACKPROP NETWORK 2-2-2
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <random>
//#include <numeric>
//#include <Windows.h>
//
//using type = float_t;
//using container_type = std::pair<type, type>;
//using container = std::vector<container_type>;
//
//using type_precision = std::numeric_limits<type>;
//
//
//
//auto sigm(const type x) -> type
//{
//	return 1 / (1 + std::exp(-1 * x));
//}
//
//auto d_sigm(const type x) -> type
//{
//	return x * (1 - x);
//}
//
//type id(const type x)
//{
//	return x;
//}
//
//type d_id(const type x)
//{
//	return x;
//}
//
//template<typename T, std::size_t N>
//constexpr std::size_t arr_size(T(&array)[N]) noexcept
//{
//	return N;
//}
//
//type generate_weight_value()
//{
//	std::random_device random_seed;
//	std::mt19937 random_generator(random_seed());
//	const std::uniform_real_distribution<float> distribution(0.05f, 0.95f);
//	return distribution(random_generator);
//}
//
//std::unique_ptr<type[]> generate_weight_list(const size_t size)
//{
//	std::random_device random_seed;
//	std::mt19937 random_generator(random_seed());
//	const std::uniform_real_distribution<float> distribution(0.05f, 0.95f);
//
//	auto weights = std::unique_ptr<type[]>(new type[size]);
//	auto random_float = [&] { return distribution(random_generator); };
//	std::generate_n(weights.get(), size, random_float);
//	return weights;
//}
//
//type accumulate_weight(const type* const weights, const type value, const std::size_t amount)
//{
//	//return static_cast<type>(std::accumulate(weights, weights + amount, 0));
//	type sum{};
//	for (std::size_t i = 0; i < amount; ++i)
//	{
//		sum += value * weights[i];
//	}
//	return sum;
//}
//
//int main(int argc, char* argv[])
//{
//	//Inputs
//	type input[][2] = { {0.05f, 0.10f} };
//	constexpr size_t T = arr_size(input); //amount of associations
//	//Targets
//	type targets[][2] = { {0.01f, 0.99f} };
//	//Amounts of layer in network, network properties
//	constexpr size_t I = 2;	//2 Input layers
//	constexpr size_t J = 2;	//2 Hidden layers
//	constexpr size_t K = 2;	//2 Output layers
//	constexpr size_t iterations = 200;
//	constexpr type lr = 0.1f;
//
//	constexpr std::size_t w_size = 8;
//	//type w[] = { 0.15f, 0.20f, 0.25f, 0.30f, 0.40f, 0.45f, 0.50f, 0.55f };
//	auto w = generate_weight_list(w_size);
//	//type w[] = { 21.15f, 22.2250f, 23.25f, 24.3250f, 25.4250f, 26.45f, 27.5250f, 28.55f };
//	type biases[] = { 0.35f, 0.60f };
//
//
//	type EEEE{};
//	for (size_t iter = 0; iter < iterations; ++iter)
//	{
//		type E_Iter{};
//
//		type* grad_E_total_w = new type[w_size]{};
//		for (size_t t = 0; t < T; ++t)
//		{
//			//Forwardpropagation
//			//const type net_h1 = w[0] * i[0][0] + w[1] * i[0][1] + biases[0] * 1;
//			//const type out_h1 = sigm(net_h1);
//
//			//const type net_h2 = w[2] * i[0][0] + w[3] * i[0][1] + biases[0] * 1;
//			//const type out_h2 = sigm(net_h2);
//
//			//const type net_o1 = w[4] * out_h1 + w[5] * out_h2 + biases[1] * 1;
//			//const type out_o1 = sigm(net_o1);
//
//			//const type net_o2 = w[6] * out_h1 + w[7] * out_h2 + biases[1] * 1;
//			//const type out_o2 = sigm(net_o2);
//
//			type* out_h = new type[J]{};
//			type* out_o = new type[K]{};
//			for (std::size_t o = 0; o < K; ++o)
//			{
//				type net_o{};
//				for (std::size_t h = 0; h < J; ++h)
//				{
//					type net_h{};
//					for (std::size_t i = 0; i < I; ++i)
//					{
//						const std::size_t w_id_i = i + h * J;
//						net_h += w[w_id_i] * input[t][i];
//					}
//					net_h += biases[0];
//					out_h[h] = sigm(net_h);
//
//					const std::size_t w_id_h = o * K + (K * J + h);
//					net_o += w[w_id_h] * out_h[h];
//				}
//				net_o += biases[1];
//				out_o[o] = sigm(net_o);
//
//				E_Iter += 0.5f * std::powf((targets[0][o] - out_o[o]), 2);
//			}
//
//			//const type E_o1 = 0.5f * std::powf((targets[0][0] - out_o[0]), 2);
//			//const type E_o2 = 0.5f * std::powf((targets[0][1] - out_o[1]), 2);
//
//			//const type E_total = E_o1 + E_o2;
//			//E_Iter += E_total;
//
//
//
//			//Backpropagation
//			type* delta_o = new type[K]{};
//
//			//Calculate delta terms for Output units
//			for (std::size_t o = 0; o < K; ++o)
//			{
//				delta_o[o] = -1 * (targets[0][o] - out_o[o]) * d_sigm(out_o[o]);
//
//				//calculate gradient of weights between hidden and output layer/s
//				for (std::size_t h = 0; h < J; ++h)
//				{
//					const std::size_t w_id_h = o * J + (J * J + h);
//					grad_E_total_w[w_id_h] += delta_o[o] * out_h[h];
//				}
//			}
//
//			type* delta_h = new type[J]{};
//			//Calculate delta terms for Hidden units
//			for (std::size_t h = 0; h < J; ++h)
//			{
//				for (std::size_t o = 0; o < K; ++o)
//				{
//					const std::size_t w_id_h = o * J + (J * J + h);
//					delta_h[h] += delta_o[o] * w[w_id_h];
//				}
//				delta_h[h] *= d_sigm(out_h[h]);
//
//				//calculate gradient of weights between input and hidden layer/s
//				for (std::size_t i = 0; i < I; ++i)
//				{
//					const std::size_t w_id_i = i + h * J;
//					grad_E_total_w[w_id_i] += delta_h[h] * input[t][i];
//				}
//			}
//
//
//
//			//Output layer weights
//			//const type E_total_out_o1 = -1 * (targets[0][0] - out_o[0]);
//			//const type E_total_out_o2 = -1 * (targets[0][1] - out_o[1]);
//
//			//const type delta_o1 = E_total_out_o1 * d_sigm(out_o[0]);
//			//const type delta_o2 = E_total_out_o2 * d_sigm(out_o[1]);
//
//			////const type E_total_w5 = delta_o1 * out_h1;
//			////const type E_total_w6 = delta_o1 * out_h1;
//			////const type E_total_w7 = delta_o2 * out_h2;
//			////const type E_total_w8 = delta_o2 * out_h2;
//			//grad_E_total_w[4] += delta_o1 * out_h[0];
//			//grad_E_total_w[5] += delta_o1 * out_h[1];
//			//grad_E_total_w[6] += delta_o2 * out_h[0];
//			//grad_E_total_w[7] += delta_o2 * out_h[1];
//			////const type E_total_b1 = delta_o1 * delta_o2;
//
//			////w[4] = w[4] - lr * E_total_w5;
//			////w[5] = w[5] - lr * E_total_w6;
//			////w[6] = w[6] - lr * E_total_w7;
//			////w[7] = w[7] - lr * E_total_w8;
//			////biases[1] = biases[1] - lr * E_total_b1;
//
//			////GIT
//
//			////Hidden Layer weights
//			//const type E_o1_net_o1 = delta_o1;
//			//const type E_o2_net_o2 = delta_o2;
//
//
//			////w1
//			//const type net_o1_out_h1 = w[4];
//			//const type net_o2_out_h1 = w[5];
//			//const type E_o1_out_h1 = delta_o1 * net_o1_out_h1;
//			//const type E_o2_out_h1 = delta_o2 * net_o2_out_h1;
//
//			//const type E_total_out_h1 = E_o1_out_h1 + E_o2_out_h1;
//			//const type out_h1_net_h1 = d_sigm(out_h[0]);
//			//const type net_h1_w1 = input[0][0];
//			//const type delta_h1 = E_total_out_h1 * out_h1_net_h1;
//			////const type E_total_w1 = E_total_out_h1 * out_h1_net_h1 * net_h1_w1;
//			//grad_E_total_w[0] += delta_h1 * net_h1_w1;
//
//
//			////w2
//			//const type net_o1_out_h2 = w[6];
//			//const type net_o2_out_h2 = w[7];
//			//const type E_o1_out_h2 = E_o1_net_o1 * net_o1_out_h2;
//			//const type E_o2_out_h2 = E_o2_net_o2 * net_o2_out_h2;
//
//			//const type E_total_out_h2 = E_o1_out_h2 + E_o2_out_h2;
//			//const type out_h2_net_h2 = d_sigm(out_h[1]);
//			//const type net_h2_w2 = input[0][0];
//
//			////const type E_total_w2 = E_total_out_h2 * out_h2_net_h2 * net_h2_w2;
//			//grad_E_total_w[1] += E_total_out_h2 * out_h2_net_h2 * net_h2_w2;
//
//
//			////w3
//			//const type net_h1_w3 = input[0][1];
//			////const type E_total_w3 = E_total_out_h1 * out_h1_net_h1 * net_h1_w3;
//			//grad_E_total_w[2] += E_total_out_h1 * out_h1_net_h1 * net_h1_w3;
//
//			////w4
//			//const type net_h2_w4 = input[0][1];
//			////const type E_total_w4 = E_total_out_h2 * out_h2_net_h2 * net_h2_w4;
//			//grad_E_total_w[3] += E_total_out_h2 * out_h2_net_h2 * net_h2_w4;
//
//			//w[0] = w[0] - lr * E_total_w1;
//			//w[1] = w[1] - lr * E_total_w2;
//			//w[2] = w[2] - lr * E_total_w3;
//			//w[3] = w[3] - lr * E_total_w4;
//
//			//w[4] = w[4] - lr * E_total_w5;
//			//w[5] = w[5] - lr * E_total_w6;
//			//w[6] = w[6] - lr * E_total_w7;
//			//w[7] = w[7] - lr * E_total_w8;
//
//			delete[] out_h;
//			delete[] out_o;
//			delete[] delta_o;
//			delete[] delta_h;
//		}
//
//
//		//std::cout.precision(type_precision::max_digits10);
//		//std::cout << "Total error: " << E_Iter << '\n';
//		//for (const auto& i : w)
//		//{
//		//	std::cout << i << ' ';
//		//}
//		//Sleep(100);
//		//system("cls");
//		EEEE = E_Iter;
//
//		for (std::size_t w_idx = 0; w_idx < w_size; w_idx++)
//		{
//			w[w_idx] = w[w_idx] - lr * grad_E_total_w[w_idx];
//		}
//
//		delete[] grad_E_total_w;
//	}
//
//
//	//for (const auto& i : w)
//	//{
//	//	std::cout << i << ' ';
//	//}
//
//
//	std::cout << EEEE << '\n';
//
//	system("pause");
//	return EXIT_SUCCESS;
//}