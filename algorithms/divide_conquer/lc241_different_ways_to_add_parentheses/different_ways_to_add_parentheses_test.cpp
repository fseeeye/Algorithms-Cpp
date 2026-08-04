#include "different_ways_to_add_parentheses.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC241
{

	TEST_CASE("LC241 Different Ways to Add Parentheses", "[problem][algorithm][divide_conquer][lc241]")
	{
		Solution241 solution;
		std::string expression = "2-1-1";
		std::vector<int> rst = solution.diffWaysToCompute(expression);
		std::vector<int> target = { 2, 0 };
		REQUIRE(rst == target);
		rst = solution.diffWaysToCompute2(expression);
		REQUIRE(rst == target);

		expression = "2*3-4*5";
		rst = solution.diffWaysToCompute(expression);
		target = { -34, -10, -14, -10, 10 };
		REQUIRE(rst == target);
		rst = solution.diffWaysToCompute2(expression);
		REQUIRE(rst == target);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC241
