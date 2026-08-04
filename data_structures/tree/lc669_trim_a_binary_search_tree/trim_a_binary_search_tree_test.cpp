#include "trim_a_binary_search_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC669
{

TEST_CASE("LC669 Trim A Binary Search Tree", "[problem][data_structure][tree][lc669]")
{
	TreeNode n2(2);
	TreeNode n1(1, nullptr, &n2);
	TreeNode n4(4);
	TreeNode root(3, &n1, &n4);
	Solution669 solution;
	TreeNode* trimmed = solution.trimBST(&root, 1, 3);
	REQUIRE(trimmed == &root);
	REQUIRE(trimmed->left == &n1);
	REQUIRE(n1.right == &n2);
	REQUIRE(trimmed->right == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC669
