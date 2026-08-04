#include "partition_equal_subset_sum.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC416
{

	TEST_CASE("LC416 Partition Equal Subset Sum", "[problem][algorithm][dynamic_programming][lc416]")
	{
		Solution416 solution;
		std::vector<int> nums = { 1, 5, 11, 5 };
		REQUIRE(solution.canPartition(nums) == true);

		nums = { 1, 2, 3, 5 };
		REQUIRE(solution.canPartition(nums) == false);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC416
