#include "ip_to_int.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJT02
{

TEST_CASE("HJT02 Ip To Int", "[problem][review][huawei][hjt02]")
{
	REQUIRE(HJT02::handle("100#101#1#5") == 1684340997U);
	REQUIRE(HJT02::handle("129#0#0#1") == 0U);
}

} // namespace AlgoCpp::Problem::Review::HJT02
