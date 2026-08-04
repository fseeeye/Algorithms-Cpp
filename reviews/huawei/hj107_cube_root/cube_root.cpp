#include "cube_root.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

namespace AlgoCpp::Problem::Review::HJ107
{

double CubeRoot(const double value)
{
	double left = std::min(-1.0, value);
	double right = std::max(1.0, value);
	while (right - left >= 0.0001) {
		const double middle = left + (right - left) / 2.0;
		if (middle * middle * middle < value) left = middle;
		else right = middle;
	}
	return left + (right - left) / 2.0;
}

void native_main()
{
	double value = 0.0;
	std::cin >> value;
	std::cout << std::fixed << std::setprecision(1) << CubeRoot(value);
}

} // namespace AlgoCpp::Problem::Review::HJ107
