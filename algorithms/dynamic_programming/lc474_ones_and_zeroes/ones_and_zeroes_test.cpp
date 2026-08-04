#include "ones_and_zeroes.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC474
{

	TEST_CASE("LC474 Ones and Zeros", "[problem][algorithm][dynamic_programming][lc474]")
	{
		Solution474 solution;
		std::vector<std::string> strs = { "10", "0001", "111001", "1", "0" };
		int rst = solution.findMaxForm(strs, 5, 3);
		REQUIRE(rst == 4);

		strs = { "10", "0", "1" };
		rst = solution.findMaxForm(strs, 1, 1);
		REQUIRE(rst == 2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC474
