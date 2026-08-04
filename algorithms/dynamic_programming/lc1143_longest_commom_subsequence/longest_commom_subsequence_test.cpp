#include "longest_commom_subsequence.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC1143
{

	TEST_CASE("LC1143 Logest Common Subsequence", "[problem][algorithm][dynamic_programming][lc1143]")
	{
		Solution1143 solution;
		std::string text1 = "abcde";
		std::string text2 = "ace";
		int rst = solution.longestCommonSubsequence(text1, text2);
		REQUIRE(rst == 3);

		text1 = "abc";
		text2 = "abc";
		rst = solution.longestCommonSubsequence(text1, text2);
		REQUIRE(rst == 3);

		text1 = "abc";
		text2 = "def";
		rst = solution.longestCommonSubsequence(text1, text2);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC1143
