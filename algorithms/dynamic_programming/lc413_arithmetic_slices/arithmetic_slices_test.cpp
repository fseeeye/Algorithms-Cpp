#include "arithmetic_slices.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC413
{

	TEST_CASE("LC413 Arithmetic Slices", "[problem][algorithm][dynamic_programming][lc413]")
	{
		Solution413 solution;
		std::vector<int> nums = { 1, 2, 3, 4 };
		int rst = solution.numberOfArithmeticSlices(nums);
		REQUIRE(rst == 3);

		nums = { 1 };
		rst = solution.numberOfArithmeticSlices(nums);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC413
