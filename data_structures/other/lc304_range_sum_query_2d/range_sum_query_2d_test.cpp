#include "range_sum_query_2d.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC304
{

TEST_CASE("LC304 Range Sum Query 2d", "[problem][data_structure][other][lc304]")
{
	std::vector<std::vector<int>> matrix{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
	Solution304 sums(matrix);
	REQUIRE(sums.sumRegion(2, 1, 4, 3) == 8);
	REQUIRE(sums.sumRegion(1, 1, 2, 2) == 11);
	REQUIRE(sums.sumRegion(1, 2, 2, 4) == 12);
}

} // namespace AlgoCpp::Problem::DataStructure::LC304
