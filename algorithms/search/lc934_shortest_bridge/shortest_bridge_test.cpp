#include "shortest_bridge.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC934
{

	TEST_CASE("LC934 Shortest Bridge", "[problem][algorithm][search][lc934]")
	{
		Solution934 solution;
		std::vector<std::vector<int>> grid = {
		    {0,1},
		    {1,0}
		};
		int rst = solution.shortestBridge(grid);
		REQUIRE(rst == 1);

		grid = {
		    {0,1,0},
		    {0,0,0},
		    {0,0,1}
		};
		rst = solution.shortestBridge(grid);
		REQUIRE(rst == 2);

		grid = {
		    {1,1,1,1,1},
		    {1,0,0,0,1},
		    {1,0,1,0,1},
		    {1,0,0,0,1},
		    {1,1,1,1,1},
		};
		rst = solution.shortestBridge(grid);
		REQUIRE(rst == 1);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC934
