#include "regular_expression_matching.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC10
{

	TEST_CASE("LC10 Regular Expression Matching", "[problem][algorithm][dynamic_programming][lc10]")
	{
		Solution10 solution;
		std::string s = "aa";
		std::string p = "a";
		REQUIRE(solution.isMatch(s, p) == false);

		s = "aa";
		p = "a*";
		REQUIRE(solution.isMatch(s, p) == true);

		s = "ab";
		p = ".*";
		REQUIRE(solution.isMatch(s, p) == true);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC10
