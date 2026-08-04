#include "max_area_of_island.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC695
{

	TEST_CASE("LC695 Max Area of Island", "[problem][algorithm][search][lc695]")
	{
		Solution695 solution;
		std::vector<std::vector<int>> grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
		int rst1 = solution.maxAreaOfIslandStack(grid);
		REQUIRE(rst1 == 6);

		grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
		int rst2 = solution.maxAreaOfIslandRecurse(grid);
		REQUIRE(rst2 == 6);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC695
