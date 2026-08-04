#include "number_of_closed_islands.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC1254
{

	TEST_CASE("LC1254 Number Of Closed Islands", "[problem][algorithm][search][lc1254]")
	{
		Solution1254 solution;
		std::vector<std::vector<int>> grid = {
		    {1,1,1,1,1,1,1,0} ,{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}
		};
		int rst = solution.closedIsland(grid);
		REQUIRE(rst == 2);

		grid = {
		    {0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}
		};
		rst = solution.closedIsland(grid);
		REQUIRE(rst == 5);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC1254
