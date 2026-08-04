#include "two_sum_ii.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC167
{

	TEST_CASE("LC167 Two Sum II", "[problem][algorithm][two_pointers][lc167]")
	{
		Solution167 solution;
		std::vector<int> numbers1 = { 2, 7, 11, 15 };
		std::vector<int> answer1 = { 1, 2 };
		std::vector<int> rst1 = solution.twoSum(numbers1, 9);
		REQUIRE(rst1 == answer1);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC167
