#include "rotate_list.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC61
{

TEST_CASE("LC61 Rotate List", "[problem][data_structure][linked_list][lc61]")
{
	ListNode fifth(5);
	ListNode fourth(4, &fifth);
	ListNode third(3, &fourth);
	ListNode second(2, &third);
	ListNode first(1, &second);
	Solution061 solution;
	ListNode* result = solution.rotateRight(&first, 2);
	REQUIRE(result == &fourth);
	REQUIRE(fourth.next == &fifth);
	REQUIRE(fifth.next == &first);
	REQUIRE(third.next == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC61
