#include "maximum_depth_of_binary_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC104
{

TEST_CASE("LC104 Maximum Depth Of Binary Tree", "[problem][data_structure][tree][lc104]")
{
	TreeNode n15(15);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n20(20, &n15, &n7);
	TreeNode root(3, &n9, &n20);
	Solution104 solution;
	REQUIRE(solution.maxDepth(&root) == 3);
}

} // namespace AlgoCpp::Problem::DataStructure::LC104
