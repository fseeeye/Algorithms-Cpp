#include "binary_tree_preorder_traversal.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC144
{

TEST_CASE("LC144 Binary Tree Preorder Traversal", "[problem][data_structure][tree][lc144]")
{
	TreeNode n3(3);
	TreeNode n2(2, &n3, nullptr);
	TreeNode root(1, nullptr, &n2);
	Solution144 solution;
	REQUIRE(solution.preorderTraversal(&root) == std::vector<int>{1, 2, 3});
}

} // namespace AlgoCpp::Problem::DataStructure::LC144
