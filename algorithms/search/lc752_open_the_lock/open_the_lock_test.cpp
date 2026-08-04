#include "open_the_lock.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC752
{

	TEST_CASE("LC752 Open The Lock", "[problem][algorithm][search][lc752]")
	{
		Solution752 solution;
		std::vector<std::string> deadends = { "0201","0101","0102","1212","2002" };
		std::string target = "0202";
		int rst = solution.openLock(deadends, target);
		REQUIRE(rst == 6);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC752
