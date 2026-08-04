#include "brick_wall.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::LC554
{

TEST_CASE("LC554 Brick Wall", "[problem][review][huawei][lc554]")
{
	std::vector<std::vector<int>> wall{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
	REQUIRE(Solution554::leastBricks(wall) == 2);
	wall = {{1}, {1}, {1}};
	REQUIRE(Solution554::leastBricks(wall) == 3);
}

} // namespace AlgoCpp::Problem::Review::LC554
