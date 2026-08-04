#include "sqrtx.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC69
{

	TEST_CASE("LC69 Sqrt(x)", "[problem][algorithm][binary_search][lc69]")
	{
		Solution69 solution;
		int rst1 = solution.mySqrt(0);
		REQUIRE(rst1 == 0);
		int rst2 = solution.mySqrt(4);
		REQUIRE(rst2 == 2);
		int rst3 = solution.mySqrt(8);
		REQUIRE(rst3 == 2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC69
