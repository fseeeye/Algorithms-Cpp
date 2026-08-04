#include "assign_cookies.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC455
{

	TEST_CASE("LC455 Assign Cookies", "[problem][algorithm][greedy_algorithm][lc455]")
	{
		Solution455 solution;
		std::vector test1_g = { 1, 2, 3 };
		std::vector test1_s = { 1, 1 };
		REQUIRE(solution.findContentChildren(test1_g, test1_s) == 1);

		std::vector test2_g = { 1, 2 };
		std::vector test2_s = { 1, 2, 3 };
		REQUIRE(solution.findContentChildren(test2_g, test2_s) == 2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC455
