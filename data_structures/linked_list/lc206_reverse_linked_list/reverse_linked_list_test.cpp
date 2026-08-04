#include "reverse_linked_list.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC206
{

TEST_CASE("LC206 Reverse Linked List", "[problem][data_structure][linked_list][lc206]")
{
	ListNode third(3);
	ListNode second(2, &third);
	ListNode first(1, &second);
	Solution206 solution;
	ListNode* reversed = solution.reverseListNonRecursive(&first);
	REQUIRE(reversed == &third);
	REQUIRE(reversed->next == &second);
	REQUIRE(second.next == &first);
	REQUIRE(first.next == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC206
