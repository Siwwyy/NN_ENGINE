
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <random>
#include <numeric>
#include <Windows.h>


#define assertm(exp, msg) assert((msg, exp))


using type = float_t;
using container_type = std::pair<type, type>;
using container = std::vector<container_type>;
using type_precision = std::numeric_limits<type>;



auto sigm(const type x)->type;
auto d_sigm(const type x)->type;

auto MSE(const std::vector<type>& y, const std::vector<type>& Y)->std::vector<type>;
auto d_MSE(const std::vector<type>& y, const std::vector<type>& Y)->std::vector<type>;

type id(const type x);
type d_id(const type x);

type generate_weight_value();
std::vector<type> generate_weight_list(const size_t size);


std::vector<type> Grad_E;

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
	type(*d_activation_function_ptr)(const type) {}; //currently hardcoded, but in future, it will work with polymorphism

public:
	Linear();
	Linear(const std::size_t amount_of_neurons, type(*activation_function_ptr)(const type) = &id, std::initializer_list<type> w = {}, std::initializer_list<type> b = {});

	Linear(const Linear& Object) = default;
	Linear(Linear&& Object) = default;
	Linear& operator=(const Linear& Object) = default;
	Linear& operator=(Linear&& Object) = default;

	void generate_connections(const std::size_t new_amount);

	[[nodiscard]] auto forward(const std::vector<type>* const input_ptr)->std::vector<type>;
	//[[nodiscard]] auto backward(std::vector<type>&& deltas = { 0.f })->std::vector<type>;
	std::vector<type> backward(std::vector<type>&& deltas = { 0.f });

	inline std::size_t Get_n_neurons() const;
	inline std::size_t Get_n_connections() const;

	~Linear() = default;
};


class Model
{
private:
	std::vector<Linear> layers;	//currently only FeedForward network, soon add polymorphism based architecture, add CNN etc.

	void validate_connections();

public:
	Model() = delete;
	Model(std::initializer_list<Linear> layers);

	Model(const Model& Object) = default;
	Model(Model&& Object) = default;
	Model& operator=(const Model& Object) = default;
	Model& operator=(Model&& Object) = default;

	[[nodiscard]] auto forward(const std::vector<type>* const input_ptr)->std::vector<type>;
	//[[nodiscard]] auto backward(const std::vector<type>* const input_ptr)->std::vector<type>;
	void backward(std::vector<type>&& deltas = { 0.f });

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
		//custom weights and biases to check correctness of results
		Linear(2, &sigm, { 0.15f, 0.20f, 0.25f, 0.30f }, { 0.35f, 0.35f }),
		Linear(2, &sigm, {0.40f, 0.45f, 0.50f, 0.55f }, { 0.60f, 0.60f })
		////weights and biases generated automatically
		//Linear(2, &sigm),	//Add weights connection correctness checking
		//Linear(2, &sigm)
		});

	const auto out = obj.forward(&in);

	std::cout << "Y0: [ " << out[0] << " ] , Y1: [ " << out[1] << " ]\n";

	auto Error = MSE(out, targets);
	const auto total_error = std::accumulate(Error.begin(), Error.end(), 0.f);
	std::cout << "Error: " << total_error << '\n';

	//auto init_delta = d_MSE(out, targets) * d_sigm(out);
	//obj.backward(init_delta);

	system("pause");
	return EXIT_SUCCESS;
}




///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//Utils

/// <summary>
/// f(x) for sigmoid/logistic function
/// </summary>
/// <param name="x"> argument value </param>
/// <returns> value of sigmoid/logistic function for specified x argument </returns>
auto sigm(const type x) -> type
{
	return 1 / (1 + std::exp(-1 * x));
}

/// <summary>
/// f_prim(x) for sigmoid/logistic function
/// </summary>
/// <param name="x"> argument value </param>
/// <returns> value of sigmoid/logistic function derivative for specified x argument </returns>
auto d_sigm(const type x) -> type
{
	return x * (1 - x);
}

/// <summary>
/// Mean Squared Error (MSE) = 1/n * ( Sum of [ (y_pred - y_true)^2 ] )
/// </summary>
/// <param name="y"> predicted values </param>
/// <param name="Y"> target values </param>
/// <returns> n-size (where n is equal to y and Y sizes, which are equal) vector with calculated loss between each of y and Y values </returns>
auto MSE(const std::vector<type>& y, const std::vector<type>& Y) -> std::vector<type>
{
	//y -> output/ of neural network
	//Y -> target value/s
	assertm(y.size() == Y.size(), "Output size has to be equal to Targets Size");

	const std::size_t vec_size = y.size();
	const type mean_divider = 1.f / static_cast<type>(vec_size); // 1/n
	std::vector<type> output(vec_size);

	for (std::size_t i = 0; i < vec_size; ++i)
	{
		output[i] = mean_divider * std::powf((y[i] - Y[i]), 2);
	}

	return output;
}

/// <summary>
/// Mean Squared Error derivative(MSE) = 1/n * ( Sum of [ 2*(y_pred - y_true) ] )
/// </summary>
/// <param name="y"> predicted values </param>
/// <param name="Y"> target values </param>
/// <returns> n-size (where n is equal to y and Y sizes, which are equal) vector with calculated loss between each of y and Y values </returns>
auto d_MSE(const std::vector<type>& y, const std::vector<type>& Y) -> std::vector<type>
{	//y -> output/ of neural network
	//Y -> target value/s
	assertm(y.size() == Y.size(), "Output size has to be equal to Targets Size");

	const std::size_t vec_size = y.size();
	const type mean_divider = 1.f / static_cast<type>(vec_size); // 1/n
	std::vector<type> output(vec_size);

	for (std::size_t i = 0; i < vec_size; ++i)
	{
		output[i] = mean_divider * 2 * (y[i] - Y[i]);
	}

	return output;
}

/// <summary>
/// f(x) for identity function
/// </summary>
/// <param name="x"> argument value </param>
/// <returns> value of identity function for specified x argument </returns>
type id(const type x)
{
	return x;
}

/// <summary>
/// f_prim(x) for identity function
/// </summary>
/// <param name="x"> argument value </param>
/// <returns> value of identity function derivative for specified x argument </returns>
type d_id(const type x)
{
	return x;
}

/// <summary>
/// Generates one float32 random value in range of (0.f, 1.f)
/// </summary>
/// <returns> Randomly generated float32 value </returns>
type generate_weight_value()
{
	std::random_device random_seed;
	std::mt19937 random_generator(random_seed());
	const std::uniform_real_distribution<float> distribution(0.01f, 0.99f);
	return distribution(random_generator);
}

/// <summary>
///	Generates n random float32 values in range of (0.f, 1.f) each
/// </summary>
/// <param name="size"> amount of random values </param>
/// <returns> vector with n randomly generated values </returns>
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


/// <summary>
/// Default constructor of Linear (Feed Forward) layer.
///	Initializes Linear layer to default values. Not recommended to use object initialized to default state!
/// </summary>
Linear::Linear() :
	weights({ 0.5f }),
	biases({ 1.f }),
	n_neurons(1),
	activation_function_ptr(&id)
{ }

//make weights/connections creation by model, here it is hardcoded, but in future, it should be generated automatically by model, e.g., 2 neurons -> 3 neurons, then 2*3 weights. In Model: init_weights() -> for loop (n_layers - 1), avoid connections inside the output layer, e.g., Linear(layer[i+1].n_neurons * layer[i].n_neurons <- current)
//If I create weights n1*n2 -> 4 inputs, then 4 hidden layers -> 4*4 = 16 connections, n1*n2 by default!



/// <summary>
/// Parametrized constructor of Linear (Feed Forward) layer.
/// </summary>
/// <param name="amount_of_neurons"> Amount of neurons for given Linear's layer </param>
/// <param name="activation_function_ptr"> function pointer to activation function. F(x) = x by default (identity function) </param>
/// <param name="w"> custom weights values. If not specified, weights will be generated automatically in range of (0.f : 1.f), in amount of amount_of_neurons * amount_of_neurons </param>
/// <param name="b"> custom biases values. If not specified, biases will be set to 1.f, in amount of amount_of_neurons </param>
Linear::Linear(const std::size_t amount_of_neurons, type(*activation_function_ptr)(const type),
	std::initializer_list<type> w, std::initializer_list<type> b) :

	weights(w.size() ? w : generate_weight_list(amount_of_neurons * amount_of_neurons)),
	biases(b.size() ? b : std::vector<type>(amount_of_neurons, -1.f)),
	n_neurons(amount_of_neurons),
	activation_function_ptr(activation_function_ptr)
{
	//HACK!! Remove later!
	if (activation_function_ptr == sigm)
	{
		d_activation_function_ptr = &d_sigm;
	}
	else
	{
		d_activation_function_ptr = &d_id;
	}
}

/// <summary>
/// Generates new connections (weights amount)
/// </summary>
/// <param name="new_amount"> new amount of weights for given Linear layer </param>
void Linear::generate_connections(const std::size_t new_amount)
{
	weights = generate_weight_list(new_amount);
}

/// <summary>
/// Forward propagation of Linear layer (dot product)
/// </summary>
/// <param name="input_ptr"> input vector pointer. Size of vector has to be equal to amount_of_neurons! </param>
/// <returns> Forward propagated input: [Sum of ( weights * input )] + bias </returns>
auto Linear::forward(const std::vector<type>* const input_ptr) -> std::vector<type>
{
	assertm(input_ptr->size() * n_neurons == weights.size(), "Check connections amount! Input vector size != layer weights/connections amount");
	std::vector<type> output(n_neurons);

	for (std::size_t i = 0; i < n_neurons; ++i)
	{
		for (std::size_t j = 0; j < input_ptr->size(); ++j)
		{
			const std::size_t w_idx = input_ptr->size() * i + j;
			output[i] += (*input_ptr)[j] * weights[w_idx];
		}
		if (!biases.empty())
		{
			output[i] += biases[i];
		}
		output[i] = activation_function_ptr(output[i]);
	}

	return output;
}

auto Linear::backward(std::vector<type>&& deltas) -> std::vector<type>
{
	std::vector<type> output_deltas(n_neurons);

	for (std::size_t i = 0; i < n_neurons; ++i)
	{
		for (std::size_t j = 0; j < deltas.size(); ++j)
		{
			//output_deltas[i] += deltas[j] * d_activation_function_ptr()
		}
	}
	return output_deltas;
}

/// <summary>
/// Get amount of neurons for Linear layer
/// </summary>
/// <returns> Amount of neurons in Linear layer </returns>
inline std::size_t Linear::Get_n_neurons() const
{
	return n_neurons;
}

/// <summary>
///	Get amount of connections/weights for Linear layer
/// </summary>
/// <returns> Amount of connections to current Linear layer </returns>
inline std::size_t Linear::Get_n_connections() const
{
	return weights.size();
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Model class methods definitions


/// <summary>
///	Validates connections and if amount of connections/weights is incorrect, then changing their amount
/// </summary>
void Model::validate_connections()
{
	const std::size_t layer_amount = layers.size();
	for (std::size_t i = 1; i < layer_amount; ++i)
	{
		const std::size_t amount_of_connections = layers[i - 1].Get_n_neurons() * layers[i].Get_n_neurons();
		if (layers[i].Get_n_connections() != amount_of_connections)
		{
			layers[i].generate_connections(amount_of_connections);
		}
	}
}

/// <summary>
/// Parametrized constructor of Model.
/// </summary>
/// <param name="layers"> insert layers for model e.g., \n
///		Model obj = Model({ \n
///		//custom weights and biases \n
///		Linear(2, &sigm, { 0.15f, 0.20f, 0.25f, 0.30f }, { 0.35f, 0.35f }), \n
///		Linear(2, &sigm, {0.40f, 0.45f, 0.50f, 0.55f }, { 0.60f, 0.60f }) \n
///		//weights and biases generated automatically \n
///		Linear(2, &sigm), \n
///		Linear(2) \n
///		}); \n
/// </param>
Model::Model(std::initializer_list<Linear> layers) :
	layers(layers)
{
	assertm(layers.size() > 0, "Model can't be empty! No Layers added");
	validate_connections();
}

/// <summary>
/// Forward propagation of Model through each layer (dot product)
/// </summary>
/// <param name="input_ptr"> input vector pointer. Size of vector has to be equal to amount_of_neurons inside the first layer! </param>
/// <returns> Forward propagated input from first to last layer: [Sum of ( weights * input)] + bias </returns>
auto Model::forward(const std::vector<type>* const input_ptr) -> std::vector<type>
{
	auto out = *input_ptr;
	const std::size_t layer_amount = layers.size();
	if (layer_amount)
	{
		assertm(out.size() == layers[0].Get_n_neurons(), "Input vector size != First layer neuron's amount");
		for (std::size_t i = 0; i < layer_amount; ++i)
		{
			out = layers[i].forward(&out);
		}
	}
	return out;
}

void Model::backward(std::vector<type>&& deltas)
{
	auto out = std::vector<type>{};	//always initialize to 1.f!!!
	const std::size_t layer_amount = layers.size();
	for (std::size_t i = 0; i < layer_amount; ++i)
	{
		out = layers[i].backward(std::move(out));
	}
}