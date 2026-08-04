#include "perfect_squares.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC279
{

	TEST_CASE("LC279 Perfect Square", "[problem][algorithm][dynamic_programming][lc279]")
	{
		Solution279 solution;
		int rst = solution.numSquares(12);
		REQUIRE(rst == 3);

		rst = solution.numSquares(13);
		REQUIRE(rst == 2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC279
