#include "path_sum_iii.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC437
{

TEST_CASE("LC437 Path Sum Iii", "[problem][data_structure][tree][lc437]")
{
	TreeNode n3(3);
	TreeNode nm2(-2);
	TreeNode n3a(3, &n3, &nm2);
	TreeNode n1(1);
	TreeNode n2(2, nullptr, &n1);
	TreeNode n11(11);
	TreeNode n5(5, &n3a, &n2);
	TreeNode nm3(-3, nullptr, &n11);
	TreeNode root(10, &n5, &nm3);
	Solution437 solution;
	REQUIRE(solution.pathSum(&root, 8) == 3);
}

} // namespace AlgoCpp::Problem::DataStructure::LC437
