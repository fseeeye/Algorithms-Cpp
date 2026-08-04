#include "find_ele_in_sorted_array.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC34
{

	TEST_CASE("LC34 Find First and Last Position of Element in Sorted Array", "[problem][algorithm][binary_search][lc34]")
	{
		Solution034 solution;
		std::vector<int> nums = { 5, 7, 7, 8, 8, 10 };
		auto rst1 = solution.searchRange(nums, 8);
		auto comp1 = std::vector<int>{ 3, 4 };
		REQUIRE(rst1 == comp1);

		auto rst2 = solution.searchRange(nums, 6);
		auto comp2 = std::vector<int>{ -1, -1 };
		REQUIRE(rst2 == comp2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC34
