#include "linked_list_last_k.h"

#include <iostream>

namespace AlgoCpp::Problem::Review::HJ51
{

std::optional<int> FindLastKValue(const std::vector<int>& values, const std::size_t k)
{
	if (k == 0 || k > values.size()) return std::nullopt;
	return values[values.size() - k];
}

void native_main()
{
	std::size_t count = 0;
	while (std::cin >> count) {
		std::vector<int> values(count);
		for (int& value : values) std::cin >> value;
		std::size_t k = 0;
		std::cin >> k;
		if (const auto value = FindLastKValue(values, k)) std::cout << *value << '\n';
	}
}

} // namespace AlgoCpp::Problem::Review::HJ51
