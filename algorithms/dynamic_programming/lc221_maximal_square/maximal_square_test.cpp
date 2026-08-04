#include "maximal_square.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC221
{

	TEST_CASE("LC221 Maximal Square", "[problem][algorithm][dynamic_programming][lc221]")
	{
		Solution221 solution;
		std::vector<std::vector<char>> matrix = {
		    {'1','0','1','0','0'},
		    {'1','0','1','1','1'},
		    {'1','1','1','1','1'},
		    {'1','0','0','1','0'}
		};
		int rst = solution.maximalSquare(matrix);
		REQUIRE(rst == 4);

		matrix = {
		    {'0','1'},
		    {'1','0'}
		};
		rst = solution.maximalSquare(matrix);
		REQUIRE(rst == 1);

		matrix = {
		    {'0'}
		};
		rst = solution.maximalSquare(matrix);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC221
