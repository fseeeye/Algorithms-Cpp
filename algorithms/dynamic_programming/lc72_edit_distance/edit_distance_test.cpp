#include "edit_distance.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC72
{

	TEST_CASE("LC72 Edit Distance", "[problem][algorithm][dynamic_programming][lc72]")
	{
		Solution72 solution;
		std::string word1 = "horse";
		std::string word2 = "ros";
		int rst = solution.minDistance(word1, word2);
		REQUIRE(rst == 3);

		word1 = "intention";
		word2 = "execution";
		rst = solution.minDistance(word1, word2);
		REQUIRE(rst == 5);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC72
