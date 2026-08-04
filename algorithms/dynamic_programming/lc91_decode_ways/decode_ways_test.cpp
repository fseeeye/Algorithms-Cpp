#include "decode_ways.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC91
{

	TEST_CASE("LC91 Decode Ways", "[problem][algorithm][dynamic_programming][lc91]")
	{
		Solution91 solution;
		std::string s1 = "12";
		int rst = solution.numDecodings(s1);
		REQUIRE(rst == 2);

		std::string s2 = "226";
		rst = solution.numDecodings(s2);
		REQUIRE(rst == 3);

		std::string s3 = "0";
		rst = solution.numDecodings(s3);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC91
