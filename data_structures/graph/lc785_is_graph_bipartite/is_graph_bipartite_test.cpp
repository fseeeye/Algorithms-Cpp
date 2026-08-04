#include "is_graph_bipartite.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC785
{

TEST_CASE("LC785 Is Graph Bipartite", "[problem][data_structure][graph][lc785]")
{
	Solution785 solution;
	std::vector<std::vector<int>> bipartite{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
	std::vector<std::vector<int>> not_bipartite{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
	REQUIRE(solution.isBipartite(bipartite));
	REQUIRE_FALSE(solution.isBipartite(not_bipartite));
}

} // namespace AlgoCpp::Problem::DataStructure::LC785
