#include "search_in_rotated_sorted_array_ii.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC81
{

	TEST_CASE("LC81 Search In Rotated Sorted Array II", "[problem][algorithm][binary_search][lc81]")
	{
		Solution081 solution;
		std::vector<int> nums = { 2, 5, 6, 0, 0, 1, 2 };
		bool rst1 = solution.search(nums, 0);
		REQUIRE(rst1 == true);
		bool rst2 = solution.search(nums, 3);
		REQUIRE(rst2 == false);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC81
