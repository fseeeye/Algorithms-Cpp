#include "merge_sorted_array.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC88
{

	TEST_CASE("LC88 Merge Sorted Array", "[problem][algorithm][two_pointers][lc88]")
	{
		Solution88 solution;
		std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
		std::vector<int> nums2 = { 2, 5, 6 };
		solution.merge(nums1, 3, nums2, 3);
		std::vector<int> answer = { 1, 2, 2, 3, 5, 6 };
		REQUIRE(nums1 == answer);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC88
