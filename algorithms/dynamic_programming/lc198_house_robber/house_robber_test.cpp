#include "house_robber.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC198
{

	TEST_CASE("LC198 Hourse Robber", "[problem][algorithm][dynamic_programming][lc198]")
	{
		Solution198 solution;
		std::vector nums = { 1, 2, 3, 1 };
		int rst = solution.rob(nums);
		REQUIRE(rst == 4);

		nums = { 2, 7, 9, 3, 1 };
		rst = solution.rob(nums);
		REQUIRE(rst == 12);

		nums = {};
		rst = solution.rob(nums);
		REQUIRE(rst == 0);

		nums = { 7 };
		rst = solution.rob(nums);
		REQUIRE(rst == 7);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC198
