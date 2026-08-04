#include "mini_path_sum.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC64
{

	TEST_CASE("LC64 Minimum Path Sum", "[problem][algorithm][dynamic_programming][lc64]")
	{
		Solution64 solution;
		std::vector<std::vector<int>> grid = {
		    { 1, 3, 1 },
		    { 1, 5, 1 },
		    { 4, 2, 1 }
		};
		int rst = solution.minPathSum(grid);
		REQUIRE(rst == 7);

		grid = {
		    { 1, 2, 3 },
		    { 4, 5, 6 }
		};
		rst = solution.minPathSum(grid);
		REQUIRE(rst == 12);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC64
