#include "queue_reconstruction_by_height.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::LC406
{

TEST_CASE("LC406 Queue Reconstruction By Height", "[problem][review][huawei][lc406]")
{
	std::vector<std::vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	REQUIRE(Solution406::reconstructQueue(people) == std::vector<std::vector<int>>{{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}});
}

} // namespace AlgoCpp::Problem::Review::LC406
