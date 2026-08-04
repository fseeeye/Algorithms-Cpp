#include "redundant_connection.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC684
{

TEST_CASE("LC684 Redundant Connection", "[problem][data_structure][other][lc684]")
{
	std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
	REQUIRE(Solution684::findRedundantConnection(edges) == std::vector<int>{2, 3});
}

} // namespace AlgoCpp::Problem::DataStructure::LC684
