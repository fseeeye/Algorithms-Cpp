#include "course_schedule_ii.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC210
{

TEST_CASE("LC210 Course Schedule Ii", "[problem][data_structure][graph][lc210]")
{
	std::vector<std::vector<int>> prerequisites{{1, 0}};
	Solution210 solution;
	REQUIRE(solution.findOrder(2, prerequisites) == std::vector<int>{0, 1});
}

} // namespace AlgoCpp::Problem::DataStructure::LC210
