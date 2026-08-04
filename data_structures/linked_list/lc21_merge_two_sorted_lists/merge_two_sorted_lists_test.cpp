#include "merge_two_sorted_lists.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC21
{

TEST_CASE("LC21 Merge Two Sorted Lists", "[problem][data_structure][linked_list][lc21]")
{
	ListNode a3(4);
	ListNode a2(2, &a3);
	ListNode a1(1, &a2);
	ListNode b3(4);
	ListNode b2(3, &b3);
	ListNode b1(1, &b2);
	Solution21 solution;
	ListNode* merged = solution.mergeTwoListsNonRecursive(&a1, &b1);
	const std::vector<int> expected{1, 1, 2, 3, 4, 4};
	for (int value : expected) {
	    REQUIRE(merged != nullptr);
	    REQUIRE(merged->val == value);
	    merged = merged->next;
	}
	REQUIRE(merged == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC21
