#include "my_calendar_i.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::DataStructure::LC729
{

	TEST_CASE("LC729 My Calendar I", "[problem][data_structure][other][lc729]")
	{
		MyCalendar solution;
		MyCalendar* c = new MyCalendar();
		REQUIRE(c->book(10, 20) == true);
		REQUIRE(c->book(15, 25) == false);
		REQUIRE(c->book(20, 30) == true);
	}

} // namespace AlgoCpp::Problem::DataStructure::LC729
