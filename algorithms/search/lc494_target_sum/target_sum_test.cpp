#include "target_sum.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC494
{

	TEST_CASE("LC494 Target Sum", "[problem][algorithm][search][lc494]")
	{
		Solution494 solution;
		std::vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int rst = solution.findTargetSumWays(nums, target);
		REQUIRE(rst == 5);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC494
