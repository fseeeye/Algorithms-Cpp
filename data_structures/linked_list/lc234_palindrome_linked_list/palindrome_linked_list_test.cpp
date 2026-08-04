#include "palindrome_linked_list.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC234
{

TEST_CASE("LC234 Palindrome Linked List", "[problem][data_structure][linked_list][lc234]")
{
	ListNode fourth(1);
	ListNode third(2, &fourth);
	ListNode second(2, &third);
	ListNode first(1, &second);
	Solution234 solution;
	REQUIRE(solution.isPalindrome(&first));
}

} // namespace AlgoCpp::Problem::DataStructure::LC234
