#include "corporate_flight_bookings.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC1109
{

TEST_CASE("LC1109 Corporate Flight Bookings", "[problem][data_structure][other][lc1109]")
{
	std::vector<std::vector<int>> bookings{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
	REQUIRE(Solution1109::corpFlightBookings(bookings, 5) == std::vector<int>{10, 55, 45, 25, 25});
}

} // namespace AlgoCpp::Problem::DataStructure::LC1109
