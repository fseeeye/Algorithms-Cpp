#include "substring_with_concatenation_of_all_words.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC30
{

	TEST_CASE("LC30 Substring With Concatenation Of All Words", "[problem][algorithm][two_pointers][lc30]")
	{
		Solution30 solution;
		std::string s = "barfoothefoobarman";
		std::vector<std::string> words = { "foo", "bar" };
		std::vector<int> rst = solution.findSubstring(s, words);
		auto target = std::vector<int>{ 0, 9 };
		REQUIRE(rst == target);

		s = "wordgoodgoodgoodbestword";
		words = { "word","good","best","word" };
		rst = solution.findSubstring(s, words);
		target = std::vector<int>{ };
		REQUIRE(rst == target);

		s = "barfoofoobarthefoobarman";
		words = { "bar","foo","the" };
		rst = solution.findSubstring(s, words);
		target = std::vector<int>{ 6, 9, 12 };
		REQUIRE(rst == target);

		s = "wordgoodgoodgoodbestword";
		words = { "word", "good", "best", "good" };
		rst = solution.findSubstring(s, words);
		target = std::vector<int>{ 8 };
		REQUIRE(rst == target);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC30
