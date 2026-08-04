#include "shortest_path_with_alternating_colors.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC1129
{

	TEST_CASE("LC1129 finds shortest alternating paths", "[problem][algorithm][search][lc1129]")
	{
		std::vector<std::vector<int>> redEdges{{0, 1}};
		std::vector<std::vector<int>> blueEdges{{1, 2}};

		REQUIRE(Solution1129::shortestAlternatingPaths(3, redEdges, blueEdges) == std::vector<int>{0, 1, 2});
	}

	TEST_CASE("LC1129 rejects consecutive edges of one color", "[problem][algorithm][search][lc1129]")
	{
		std::vector<std::vector<int>> redEdges{{0, 1}, {1, 2}};
		std::vector<std::vector<int>> blueEdges;

		REQUIRE(Solution1129::shortestAlternatingPaths(3, redEdges, blueEdges) == std::vector<int>{0, 1, -1});
	}

} // namespace AlgoCpp::Problem::Algorithm::LC1129
