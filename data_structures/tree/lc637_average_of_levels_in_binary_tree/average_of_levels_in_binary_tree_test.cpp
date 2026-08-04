#include "average_of_levels_in_binary_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC637
{

TEST_CASE("LC637 Average Of Levels In Binary Tree", "[problem][data_structure][tree][lc637]")
{
	TreeNode n15(15);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n20(20, &n15, &n7);
	TreeNode root(3, &n9, &n20);
	Solution637 solution;
	REQUIRE(solution.averageOfLevels(&root) == std::vector<double>{3.0, 14.5, 11.0});
}

} // namespace AlgoCpp::Problem::DataStructure::LC637
