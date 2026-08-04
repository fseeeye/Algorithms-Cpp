#include "input_nums_count.h"

#include <iomanip>
#include <iostream>

namespace AlgoCpp::Problem::Review::HJ97
{

std::pair<std::size_t, double> AnalyzeNumbers(const std::vector<int>& numbers)
{
	std::size_t negativeCount = 0;
	std::size_t positiveCount = 0;
	double positiveSum = 0.0;
	for (const int number : numbers) {
		if (number < 0) ++negativeCount;
		else if (number > 0) {
			++positiveCount;
			positiveSum += number;
		}
	}
	return {negativeCount, positiveCount == 0 ? 0.0 : positiveSum / static_cast<double>(positiveCount)};
}

void native_main()
{
	std::size_t count = 0;
	std::cin >> count;
	std::vector<int> numbers(count);
	for (int& number : numbers) std::cin >> number;
	const auto [negativeCount, positiveAverage] = AnalyzeNumbers(numbers);
	std::cout << negativeCount << ' ' << std::fixed << std::setprecision(1) << positiveAverage;
}

} // namespace AlgoCpp::Problem::Review::HJ97
