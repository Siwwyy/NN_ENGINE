
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <random>
#include <numeric>
#include <Windows.h>


using type = float_t;
using container_type = std::pair<type, type>;
using container = std::vector<container_type>;
using type_precision = std::numeric_limits<type>;


template<typename T, std::size_t N>
constexpr std::size_t arr_size(T(&array)[N]) noexcept
{
	return N;
}


auto sigm(const type x)->type;
auto d_sigm(const type x)->type;

auto MSE(const std::vector<type>& y, const std::vector<type>& Y)->std::vector<type>;

type id(const type x);
type d_id(const type x);

type generate_weight_value();
std::vector<type> generate_weight_list(const size_t size);



class AutoGrad
{
	//TBD
private:

	std::vector<float> weights;
	std::vector<float> biases;

public:
	AutoGrad() = default;
};


class Linear
{
private:

	std::vector<type> weights{};
	std::vector<type> biases{};
	std::size_t n_neurons{};
	type(*activation_function_ptr)(const type) {};

public:
	Linear() :
		weights({ 0.5f }),
		biases({ 1.f }),
		n_neurons(1),
		activation_function_ptr(&id)
	{ }

	Linear(const std::size_t amount_of_neurons, type(*activation_function_ptr)(const type) = &id, std::initializer_list<type> w = {}, std::initializer_list<type> b = {}) :
		weights(w.size() ? w : generate_weight_list(amount_of_neurons)),	//make weights/connections creation by model, here it is hardcoded, but in future, it should be generated automatically by model, e.g., 2 neurons -> 3 neurons, then 2*3 weights. In Model: init_weights() -> for loop (n_layers - 1), avoid connections inside the output layer, e.g., Linear(layer[i+1].n_neurons * layer[i].n_neurons <- current)
		biases(b.size() ? b : std::vector<type>(amount_of_neurons, -1.f)),
		n_neurons(amount_of_neurons),
		activation_function_ptr(activation_function_ptr)
	{ }

	Linear(const Linear& Object) = default;
	Linear(Linear&& Object) = default;
	Linear& operator=(const Linear& Object) = default;
	Linear& operator=(Linear&& Object) = default;

	void generate_connections(const std::size_t new_value);

	[[nodiscard]] auto forward(std::vector<type>&& input)->std::vector<type>;
	//auto backward()->std::vector<type>; //TBD

	std::size_t Get_n_neurons() const;

	~Linear() = default;
};


class Model
{
private:
	std::vector<Linear> layers;	//currently only FeedForward network, soon add polymorphism based architecture, add CNN etc.

	void initialize_connections();

public:
	Model() = delete;

	Model(std::initializer_list<Linear> layers) :
		layers(layers)
	{
		assert( layers.size() > 0, "Model can't be empty! No Layers added");
		initialize_connections();
	}

	Model(const Model& Object) = default;
	Model(Model&& Object) = default;
	Model& operator=(const Model& Object) = default;
	Model& operator=(Model&& Object) = default;

	[[nodiscard]] auto forward(const std::vector<type>* const input_ptr)->std::vector<type>;

	~Model() = default;
};


int main(int argc, char* argv[])
{
	//Self made model
	////Inputs
	//const std::vector<type> in = { 0.05f, 0.10f };
	////Targets
	//const std::vector<type> targets = { 0.01f, 0.99f };

	//std::vector<Linear> model
	//{
	//	//custom weights and biases to check correctness of results
		//Linear(2, &sigm, { 0.15f, 0.20f, 0.25f, 0.30f }, { 0.35f, 0.35f }),
		//Linear(2, &sigm, {0.40f, 0.45f, 0.50f, 0.55f }, { 0.60f, 0.60f })
	//};

	//auto out = in;
	//for (std::size_t i = 0; i < 2; ++i)
	//{
	//	out = model[i].forward(std::move(out));
	//}

	//std::cout << "Y0: [ " << out[0] << " ] , Y1: [ " << out[1] << " ]\n";

	//auto Error = MSE(out, targets);
	//std::cout << "Error: " << std::accumulate(Error.begin(), Error.end(), 0.f);


	//Model by class
		//Inputs
	const std::vector<type> in = { 0.05f, 0.10f };
	//Targets
	const std::vector<type> targets = { 0.01f, 0.99f };

	Model obj = Model({
		////custom weights and biases to check correctness of results
		//Linear(2, &sigm, { 0.15f, 0.20f, 0.25f, 0.30f }, { 0.35f, 0.35f }),
		//Linear(2, &sigm, {0.40f, 0.45f, 0.50f, 0.55f }, { 0.60f, 0.60f })
		//weights and biases generated automatically
		Linear(2, &sigm),	//Add weights connection correctness checking
		Linear(2, &sigm)
		});

	const auto out = obj.forward(&in);

	std::cout << "Y0: [ " << out[0] << " ] , Y1: [ " << out[1] << " ]\n";

	auto Error = MSE(out, targets);
	std::cout << "Error: " << std::accumulate(Error.begin(), Error.end(), 0.f) << '\n';

	system("pause");
	return EXIT_SUCCESS;
}




///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//Utils


auto sigm(const type x) -> type
{
	return 1 / (1 + std::exp(-1 * x));
}

auto d_sigm(const type x) -> type
{
	return x * (1 - x);
}

auto MSE(const std::vector<type>& y, const std::vector<type>& Y) -> std::vector<type>
{
	//y -> output/ of neural network
	//Y -> target value/s
	assert(y.size() == Y.size(), "Output size has to be equal to Targets Size");

	const std::size_t vec_size = y.size();
	const type mean_divider = 1.f / static_cast<type>(vec_size); // 1/n
	std::vector<type> output(vec_size);

	for (std::size_t i = 0; i < vec_size; ++i)
	{
		output[i] = mean_divider * std::powf((y[i] - Y[i]), 2);
	}

	return output;
}

type id(const type x)
{
	return x;
}

type d_id(const type x)
{
	return x;
}

type generate_weight_value()
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<float> distribution(0.01f, 0.99f);
	return distribution(random_generator);
}

std::vector<type> generate_weight_list(const size_t size)
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<float> distribution(0.01f, 0.99f);

	auto weights = std::vector<type>(size);
	auto random_float = [&] { return distribution(random_generator); };
	std::generate(weights.begin(), weights.end(), random_float);
	return weights;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Linear class methods definitions

void Linear::generate_connections(const std::size_t new_value)
{
	weights = generate_weight_list(new_value);
}

auto Linear::forward(std::vector<type>&& input) -> std::vector<type>
{
	std::vector<type> output(n_neurons);

	for (std::size_t i = 0; i < n_neurons; ++i)
	{
		for (std::size_t j = 0; j < input.size(); ++j)
		{
			const std::size_t w_idx = input.size() * i + j;
			output[i] += input[j] * weights[w_idx];
		}
		if (!biases.empty())
		{
			output[i] += biases[i];
		}
		output[i] = activation_function_ptr(output[i]);
	}

	return output;
}

std::size_t Linear::Get_n_neurons() const
{
	return n_neurons;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Model class methods definitions

void Model::initialize_connections()
{
	const std::size_t layer_amount = layers.size();
	layers[0].generate_connections(layers[0].Get_n_neurons() * layers[1].Get_n_neurons());
	for (std::size_t i = 1; i < layer_amount; ++i)
	{
		const std::size_t amount_of_connections = layers[i - 1].Get_n_neurons() * layers[i].Get_n_neurons();
		layers[i].generate_connections(amount_of_connections);
	}
}

auto Model::forward(const std::vector<type>* const input_ptr) -> std::vector<type>
{
	auto out = *input_ptr;
	const std::size_t layer_amount = layers.size();
	if (layer_amount)
	{
		assert(out.size() == layers[0].Get_n_neurons(), "Input vector size != First layer neuron's amount");
		for (std::size_t i = 0; i < layer_amount; ++i)
		{
			out = layers[i].forward(std::move(out));
		}
	}
	return out;
}