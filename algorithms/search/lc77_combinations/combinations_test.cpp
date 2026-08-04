#include "combinations.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC77
{

	TEST_CASE("LC77 Combinations", "[problem][algorithm][search][lc77]")
	{
		Solution77 solution;
		int n1 = 4, k1 = 2;
		std::vector<std::vector<int>> rst1 = solution.combine(n1, k1);
		std::vector<std::vector<int>> target1 = { {1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };
		REQUIRE(rst1 == target1);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC77
