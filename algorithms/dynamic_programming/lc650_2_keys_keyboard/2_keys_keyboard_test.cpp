#include "2_keys_keyboard.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC650
{

	TEST_CASE("LC650 2 Keys Keyboard", "[problem][algorithm][dynamic_programming][lc650]")
	{
		Solution650 solution;
		int rst = solution.minSteps(3);
		REQUIRE(rst == 3);

		rst = solution.minSteps(1);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC650
