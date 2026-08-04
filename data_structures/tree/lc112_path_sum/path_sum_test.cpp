#include "path_sum.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC112
{

TEST_CASE("LC112 Path Sum", "[problem][data_structure][tree][lc112]")
{
	TreeNode n7(7);
	TreeNode n2(2);
	TreeNode n11(11, &n7, &n2);
	TreeNode n4(4, &n11, nullptr);
	TreeNode n13(13);
	TreeNode n1(1);
	TreeNode n4b(4, nullptr, &n1);
	TreeNode n8(8, &n13, &n4b);
	TreeNode root(5, &n4, &n8);
	REQUIRE(Solution112::hasPathSum(&root, 22));
}

} // namespace AlgoCpp::Problem::DataStructure::LC112
