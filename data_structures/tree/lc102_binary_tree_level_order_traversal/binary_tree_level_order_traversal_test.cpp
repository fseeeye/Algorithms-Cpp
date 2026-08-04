#include "binary_tree_level_order_traversal.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC102
{

TEST_CASE("LC102 Binary Tree Level Order Traversal", "[problem][data_structure][tree][lc102]")
{
	TreeNode n15(15);
	TreeNode n7(7);
	TreeNode n9(9);
	TreeNode n20(20, &n15, &n7);
	TreeNode root(3, &n9, &n20);
	REQUIRE(Solution102::levelOrder(&root) == std::vector<std::vector<int>>{{3}, {9, 20}, {15, 7}});
}

} // namespace AlgoCpp::Problem::DataStructure::LC102
