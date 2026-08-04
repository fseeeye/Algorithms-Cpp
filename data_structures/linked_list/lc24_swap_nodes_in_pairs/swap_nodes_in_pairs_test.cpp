#include "swap_nodes_in_pairs.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC24
{

TEST_CASE("LC24 Swap Nodes In Pairs", "[problem][data_structure][linked_list][lc24]")
{
	ListNode fourth(4);
	ListNode third(3, &fourth);
	ListNode second(2, &third);
	ListNode first(1, &second);
	Solution24 solution;
	ListNode* result = solution.swapPairs(&first);
	REQUIRE(result == &second);
	REQUIRE(result->next == &first);
	REQUIRE(first.next == &fourth);
	REQUIRE(fourth.next == &third);
	REQUIRE(third.next == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC24
