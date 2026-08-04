#include "minimum_window_substring.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC76
{

	TEST_CASE("LC76 Minimum Window Substring", "[problem][algorithm][two_pointers][lc76]")
	{
		Solution76 solution;
		std::string rst1 = solution.minWindow("ADOBECODEBANC", "ABC");
		REQUIRE(rst1 == "BANC");

		std::string rst2 = solution.minWindow("a", "a");
		REQUIRE(rst2 == "a");

		std::string rst3 = solution.minWindow("a", "aa");
		REQUIRE(rst3.empty());

		rst1 = solution.minWindow_2("ADOBECODEBANC", "ABC");
		REQUIRE(rst1 == "BANC");

		rst2 = solution.minWindow_2("a", "a");
		REQUIRE(rst2 == "a");

		rst3 = solution.minWindow_2("a", "aa");
		REQUIRE(rst3.empty());
	}

} // namespace AlgoCpp::Problem::Algorithm::LC76
