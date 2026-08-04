#include "balanced_binary_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC110
{

TEST_CASE("LC110 Balanced Binary Tree", "[problem][data_structure][tree][lc110]")
{
	TreeNode n4(4);
	TreeNode n3(3, &n4, nullptr);
	TreeNode n2(2, &n3, nullptr);
	TreeNode root(1, &n2, nullptr);
	Solution110 solution;
	REQUIRE_FALSE(solution.isBalanced(&root));
}

} // namespace AlgoCpp::Problem::DataStructure::LC110
