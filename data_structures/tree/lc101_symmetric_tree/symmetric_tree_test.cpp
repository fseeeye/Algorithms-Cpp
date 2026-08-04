#include "symmetric_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC101
{

TEST_CASE("LC101 Symmetric Tree", "[problem][data_structure][tree][lc101]")
{
	TreeNode left_left(3);
	TreeNode left_right(4);
	TreeNode right_left(4);
	TreeNode right_right(3);
	TreeNode left(2, &left_left, &left_right);
	TreeNode right(2, &right_left, &right_right);
	TreeNode root(1, &left, &right);
	Solution101 solution;
	REQUIRE(solution.isSymmetric(&root));
}

} // namespace AlgoCpp::Problem::DataStructure::LC101
