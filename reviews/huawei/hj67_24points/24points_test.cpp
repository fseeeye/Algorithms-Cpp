#include "24points.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ67
{

TEST_CASE("HJ67 24points", "[problem][review][huawei][hj67]")
{
	REQUIRE(HJ67::dfsRecurse({6, 6, 6, 6}, 0));
	REQUIRE_FALSE(HJ67::dfsRecurse({1, 1, 1, 1}, 0));
}

} // namespace AlgoCpp::Problem::Review::HJ67
