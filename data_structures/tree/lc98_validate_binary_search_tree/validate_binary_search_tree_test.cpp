#include "validate_binary_search_tree.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC98
{

TEST_CASE("LC98 Validate Binary Search Tree", "[problem][data_structure][tree][lc98]")
{
	TreeNode left(1);
	TreeNode right(3);
	TreeNode root(2, &left, &right);
	REQUIRE(Solution098::isValidBST(&root));
	right.val = 1;
	REQUIRE_FALSE(Solution098::isValidBST(&root));
}

} // namespace AlgoCpp::Problem::DataStructure::LC98
