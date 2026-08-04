#include "lcof.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LCOF45
{

	TEST_CASE("LCOF45 arranges values into the smallest number", "[problem][algorithm][greedy_algorithm][lcof45]")
	{
		std::vector<int> values{3, 30, 34, 5, 9};

		REQUIRE(SolutionO45::minNumber(values) == "3033459");
	}

} // namespace AlgoCpp::Problem::Algorithm::LCOF45
