#include "intersection_of_two_linked_list.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC160
{

TEST_CASE("LC160 Intersection Of Two Linked List", "[problem][data_structure][linked_list][lc160]")
{
	ListNode common2(5);
	ListNode common1(4, &common2);
	ListNode a2(1, &common1);
	ListNode a1(8, &a2);
	ListNode b1(6, &common1);
	Solution160 solution;
	REQUIRE(solution.getIntersectionNode(&a1, &b1) == &common1);
}

} // namespace AlgoCpp::Problem::DataStructure::LC160
