#include "longest_substring_without_repeating_characters.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC3
{

	TEST_CASE("LC3 Longest Substring Without Repeating Characters", "[problem][algorithm][two_pointers][lc3]")
	{
		Solution03 solution;
		std::string s = "abcabcbb";
		int rst = solution.lengthOfLongestSubstring(s);
		REQUIRE(rst == 3);

		s = "bbbbb";
		rst = solution.lengthOfLongestSubstring(s);
		REQUIRE(rst == 1);

		s = "pwwkew";
		rst = solution.lengthOfLongestSubstring(s);
		REQUIRE(rst == 3);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC3
