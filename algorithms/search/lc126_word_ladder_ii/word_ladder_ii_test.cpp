#include "word_ladder_ii.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC126
{

	TEST_CASE("LC126 Word Ladder II", "[problem][algorithm][search][lc126]")
	{
		Solution126 solution;
		std::string beginWord = "hit";
		std::string endWord = "cog";
		std::vector<std::string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
		std::vector<std::vector<std::string>> target = {
		    { "hit", "hot", "dot", "dog", "cog" },
		    { "hit", "hot", "lot", "log", "cog" },
		};
		std::vector<std::vector<std::string>> rst = solution.findLadders(beginWord, endWord, wordList);
		REQUIRE(rst == target);

		wordList = { "hot", "dot", "dog", "lot", "log" };
		std::vector<std::vector<std::string>> target2 = {};
		std::vector<std::vector<std::string>> rst2 = solution.findLadders(beginWord, endWord, wordList);
		REQUIRE(rst2 == target2);

		wordList = { "a", "b", "c" };
		beginWord = "a";
		endWord = "c";
		std::vector<std::vector<std::string>> target3 = { { "a", "c" } };
		std::vector<std::vector<std::string>> rst3 = solution.findLadders(beginWord, endWord, wordList);
		REQUIRE(rst3 == target3);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC126
