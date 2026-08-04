#include "word_break.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC139
{

	TEST_CASE("LC139 Word Break", "[problem][algorithm][dynamic_programming][lc139]")
	{
		Solution139 solution;
		std::string s = "leetcode";
		std::vector<std::string> wordDict = { "leet", "code" };
		REQUIRE(solution.wordBreak(s, wordDict) == true);

		s = "applepenapple";
		wordDict = { "apple", "pen" };
		REQUIRE(solution.wordBreak(s, wordDict) == true);

		s = "catsandog";
		wordDict = { "cats", "dog", "sand", "and", "cat"};
		REQUIRE(solution.wordBreak(s, wordDict) == false);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC139
