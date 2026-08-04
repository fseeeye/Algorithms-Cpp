#include "partition_list.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC86
{

TEST_CASE("LC86 Partition List", "[problem][data_structure][linked_list][lc86]")
{
	ListNode sixth(2);
	ListNode fifth(5, &sixth);
	ListNode fourth(2, &fifth);
	ListNode third(3, &fourth);
	ListNode second(4, &third);
	ListNode first(1, &second);
	Solution086 solution;
	ListNode* result = solution.partition(&first, 3);
	const std::vector<int> expected{1, 2, 2, 4, 3, 5};
	for (int value : expected) {
	    REQUIRE(result != nullptr);
	    REQUIRE(result->val == value);
	    result = result->next;
	}
	REQUIRE(result == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC86
