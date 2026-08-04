#include "range_sum_query.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC303
{

TEST_CASE("LC303 Range Sum Query", "[problem][data_structure][other][lc303]")
{
	std::vector<int> nums{-2, 0, 3, -5, 2, -1};
	Solution303 sums(nums);
	REQUIRE(sums.sumRange(0, 2) == 1);
	REQUIRE(sums.sumRange(2, 5) == -1);
	REQUIRE(sums.sumRange(0, 5) == -3);
}

} // namespace AlgoCpp::Problem::DataStructure::LC303
