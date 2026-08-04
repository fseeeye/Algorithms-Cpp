#include "number_of_provinces.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC547
{

	TEST_CASE("LC547 Number of Provinces", "[problem][algorithm][search][lc547]")
	{
		Solution547 solution;
		std::vector<std::vector<int>> isConnected1 =
		{
		    {1, 1, 0},
		    {1, 1, 0},
		    {0, 0, 1}
		};
		int rst1 = solution.findCircleNum(isConnected1);
		REQUIRE(rst1 == 2);

		std::vector<std::vector<int>> isConnected2 =
		{
		    {1, 0, 0},
		    {0, 1, 0},
		    {0, 0, 1}
		};
		int rst2 = solution.findCircleNum(isConnected2);
		REQUIRE(rst2 == 3);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC547
