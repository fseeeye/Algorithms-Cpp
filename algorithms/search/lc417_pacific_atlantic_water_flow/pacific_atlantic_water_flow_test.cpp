#include "pacific_atlantic_water_flow.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC417
{

	TEST_CASE("LC417 Pacific Atlantic Waterflow", "[problem][algorithm][search][lc417]")
	{
		Solution417 solution;
		std::vector<std::vector<int>> heights = {
		    {1,2,2,3,5},
		    {3,2,3,4,4},
		    {2,4,5,3,1},
		    {6,7,1,4,5},
		    {5,1,1,2,4}
		};
		std::vector<std::vector<int>> rst = solution.pacificAtlantic(heights);
		std::vector<std::vector<int>> target = { {0, 4},{1, 3},{1, 4},{2, 2},{3, 0},{3, 1},{4, 0} };
		REQUIRE(rst == target);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC417
