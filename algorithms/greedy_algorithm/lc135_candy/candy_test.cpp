#include "candy.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC135
{

	TEST_CASE("LC135 Candy", "[problem][algorithm][greedy_algorithm][lc135]")
	{
		Solution135 solution;
		std::vector test1_ratings = { 1, 0, 2 };
		REQUIRE(solution.candy(test1_ratings) == 5);

		std::vector test2_ratings = { 1, 2, 2 };
		REQUIRE(solution.candy(test2_ratings) == 4);

		std::vector test3_ratings = { 1, 2, 1 };
		REQUIRE(solution.candy(test3_ratings) == 4);

		std::vector test4_ratings = { 2, 3, 2, 1 };
		int rst = solution.candy(test4_ratings);
		REQUIRE(rst == 7);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC135
