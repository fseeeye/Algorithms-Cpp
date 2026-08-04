#include "longest_increasing_subsequence.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC300
{

	TEST_CASE("LC300 Logest Increasing Subsequence", "[problem][algorithm][dynamic_programming][lc300]")
	{
		Solution300 solution;
		std::vector nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
		int rst = solution.lengthOfLIS(nums);
		REQUIRE(rst == 4);
		rst = solution.lengthOfLIS2(nums);
		REQUIRE(rst == 4);

		nums = { 0, 1, 0, 3, 2, 3 };
		rst = solution.lengthOfLIS(nums);
		REQUIRE(rst == 4);
		rst = solution.lengthOfLIS2(nums);
		REQUIRE(rst == 4);

		nums = { 7, 7, 7 };
		rst = solution.lengthOfLIS(nums);
		REQUIRE(rst == 1);
		rst = solution.lengthOfLIS2(nums);
		REQUIRE(rst == 1);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC300
