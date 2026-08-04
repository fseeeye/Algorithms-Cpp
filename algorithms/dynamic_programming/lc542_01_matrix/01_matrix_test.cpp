#include "01_matrix.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC542
{

	TEST_CASE("LC542 0-1 Matrix", "[problem][algorithm][dynamic_programming][lc542]")
	{
		Solution542 solution;
		std::vector<std::vector<int>> mat = {
		    { 0, 0, 0 },
		    { 0, 1, 0 },
		    { 0, 0, 0 },
		};
		std::vector<std::vector<int>> rst = solution.updateMatrix(mat);
		std::vector<std::vector<int>> target = {
		    { 0, 0, 0 },
		    { 0, 1, 0 },
		    { 0, 0, 0 },
		};
		REQUIRE(rst == target);

		mat = {
		    { 0, 0, 0 },
		    { 0, 1, 0 },
		    { 1, 1, 1 }
		};
		rst = solution.updateMatrix(mat);
		target = {
		    { 0, 0, 0 },
		    { 0, 1, 0 },
		    { 1, 2, 1 }
		};
		REQUIRE(rst == target);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC542
