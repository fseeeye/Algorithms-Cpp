#include "diameter_of_binary_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC543
{

TEST_CASE("LC543 Diameter Of Binary Tree", "[problem][data_structure][tree][lc543]")
{
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n2(2, &n4, &n5);
	TreeNode n3(3);
	TreeNode root(1, &n2, &n3);
	Solution543 solution;
	REQUIRE(solution.diameterOfBinaryTree(&root) == 3);
}

} // namespace AlgoCpp::Problem::DataStructure::LC543
