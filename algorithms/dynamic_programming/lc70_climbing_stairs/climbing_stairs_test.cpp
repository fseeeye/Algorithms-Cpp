#include "climbing_stairs.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC70
{

	TEST_CASE("LC70 Climbing Stairs", "[problem][algorithm][dynamic_programming][lc70]")
	{
		Solution70 solution;
		int rst1 = solution.climbStairs(2);
		int rst2 = solution.climbStairs(3);

		REQUIRE(rst1 == 2);
		REQUIRE(rst2 == 3);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC70
