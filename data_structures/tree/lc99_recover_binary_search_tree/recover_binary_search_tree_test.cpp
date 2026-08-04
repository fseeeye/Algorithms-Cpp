#include "recover_binary_search_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC99
{

TEST_CASE("LC99 Recover Binary Search Tree", "[problem][data_structure][tree][lc99]")
{
	TreeNode n2(2);
	TreeNode n3(3, nullptr, &n2);
	TreeNode root(1, &n3, nullptr);
	Solution99 solution;
	solution.recoverTree(&root);
	REQUIRE(root.val == 3);
	REQUIRE(root.left->val == 1);
	REQUIRE(root.left->right->val == 2);
}

} // namespace AlgoCpp::Problem::DataStructure::LC99
