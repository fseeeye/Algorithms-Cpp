#include "shortest_path_in_binary_matrix.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC1091
{

	TEST_CASE("LC1091 Shortest Path In Binary Matrix", "[problem][algorithm][search][lc1091]")
	{
		Solution1091 solution;
		std::vector<std::vector<int>> grid = {
		    { 0, 0, 0},
		    { 1, 0, 0},
		    { 1, 1, 0}
		};
		int rst = solution.shortestPathBinaryMatrix(grid);
		REQUIRE(rst == 3);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC1091
