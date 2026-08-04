#include "3sum_closest.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC16
{

	TEST_CASE("LC16 3sum Closest", "[problem][algorithm][two_pointers][lc16]")
	{
		Solution016 solution;
		std::vector<int> nums = { -1, 2, 1, -4 };
		int target = 1;
		int rst = solution.threeSumClosest(nums, target);
		REQUIRE(rst == 2);

		nums = { 0, 0, 0 };
		target = 1;
		rst = solution.threeSumClosest(nums, target);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC16
