#include "delete_nodes_and_return_forest.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC1110
{

TEST_CASE("LC1110 Delete Nodes And Return Forest", "[problem][data_structure][tree][lc1110]")
{
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);
	TreeNode n2(2, &n4, &n5);
	TreeNode n3(3, &n6, &n7);
	TreeNode root(1, &n2, &n3);
	std::vector<int> removed{3, 5};
	Solution1110 solution;
	const auto forest = solution.delNodes(&root, removed);
	std::vector<int> roots;
	for (const TreeNode* node : forest) roots.push_back(node->val);
	std::sort(roots.begin(), roots.end());
	REQUIRE(roots == std::vector<int>{1, 6, 7});
}

} // namespace AlgoCpp::Problem::DataStructure::LC1110
