#include "daily_temperatures.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC739
{

TEST_CASE("LC739 Daily Temperatures", "[problem][data_structure][other][lc739]")
{
	std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
	REQUIRE(Solution739::dailyTemperatures(temperatures) == std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0});
}

} // namespace AlgoCpp::Problem::DataStructure::LC739
