#include "link_list_cycle_ii.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC142
{

	TEST_CASE("LC142 Link List Cycle II", "[problem][algorithm][two_pointers][lc142]")
	{
		Solution142 solution;
		ListNode node1 = ListNode(3);
		ListNode node2 = ListNode(2);
		ListNode node3 = ListNode(0);
		ListNode node4 = ListNode(-4);
		node1.next = &node2;
		node2.next = &node3;
		node3.next = &node4;
		node4.next = &node2;

		ListNode* rst = solution.detectCycle(&node1);
		REQUIRE(rst == &node2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC142
