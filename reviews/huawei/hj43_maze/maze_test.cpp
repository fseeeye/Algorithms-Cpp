#include "maze.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ43
{

TEST_CASE("HJ43 Maze", "[problem][review][huawei][hj43]")
{
	std::vector<std::vector<int>> grid{{0, 1, 0}, {0, 0, 0}, {1, 1, 0}};
	REQUIRE(HJ43::bfs(grid, 3, 3) == std::vector<std::pair<int, int>>{{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 2}});
}

} // namespace AlgoCpp::Problem::Review::HJ43
