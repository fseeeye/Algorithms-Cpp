#include "subarray_sum_equals_k.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC560
{

TEST_CASE("LC560 Subarray Sum Equals K", "[problem][data_structure][other][lc560]")
{
	std::vector<int> nums{1, 1, 1};
	REQUIRE(Solution560::subarraySum(nums, 2) == 2);
}

} // namespace AlgoCpp::Problem::DataStructure::LC560
