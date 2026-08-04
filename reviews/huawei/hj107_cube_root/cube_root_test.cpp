#include "cube_root.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ107
{

TEST_CASE("HJ107 Cube Root", "[problem][review][huawei][hj107]")
{
	REQUIRE(std::abs(CubeRoot(19.0) - 2.7) < 0.05);
	REQUIRE(std::abs(CubeRoot(-8.0) + 2.0) < 0.05);
}

} // namespace AlgoCpp::Problem::Review::HJ107
