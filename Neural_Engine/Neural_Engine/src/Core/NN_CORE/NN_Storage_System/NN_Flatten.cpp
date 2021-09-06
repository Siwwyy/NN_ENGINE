#include "Core/NN_CORE/NN_Storage_System/NN_Flatten.hpp"

template <std::ranges::range Rng, typename T>
auto NN::Core::NN_CORE::NN_Storage_System::deep_flatten_impl(const Rng& range, NN::Math::Algebra::Tensor<T>& output)
{
	using value_type = std::decay_t<std::ranges::range_value_t<Rng>>;
	if constexpr (std::ranges::range<value_type>)
	{
		for (auto&& subrange : range)
		{
			deep_flatten_impl(subrange);
		}
	}
	else
	{
		for (const auto& element : range)
		{
			output.push_back(element);
		}
	}
}

template<std::ranges::range Rng>
auto NN::Core::NN_CORE::NN_Storage_System::flatten(const Rng& range)
{
	using value_type = std::decay_t<std::ranges::range_value_t<Rng>>;
	auto vec = std::vector<NN::Core::NN_CORE::NN_Storage_System::inner_type_t<Rng>>{};
	NN::Core::NN_CORE::NN_Storage_System::deep_flatten_impl(range, vec);

	return vec;
}