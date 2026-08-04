#include "min_swap.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJT03
{

TEST_CASE("HJT03 Min Swap", "[problem][review][huawei][hjt03]")
{
	std::vector<int> values{1, 3, 1, 4, 0};
	REQUIRE(HJT03::minTimes(values, 2) == 1);
	values = {0, 0, 0, 1, 0};
	REQUIRE(HJT03::minTimes(values, 2) == 0);
}

} // namespace AlgoCpp::Problem::Review::HJT03
