#include "construct_binary_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC105
{

TEST_CASE("LC105 Construct Binary Tree", "[problem][data_structure][tree][lc105]")
{
	std::vector<int> preorder{3, 9, 20, 15, 7};
	std::vector<int> inorder{9, 3, 15, 20, 7};
	Solution105 solution;
	TreeNode* root = solution.buildTree(preorder, inorder);
	REQUIRE(root->val == 3);
	REQUIRE(root->left->val == 9);
	REQUIRE(root->right->val == 20);
	REQUIRE(root->right->left->val == 15);
	REQUIRE(root->right->right->val == 7);
}

} // namespace AlgoCpp::Problem::DataStructure::LC105
