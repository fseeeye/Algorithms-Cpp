#include "coin_change.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC322
{

	TEST_CASE("LC322 Coin Change", "[problem][algorithm][dynamic_programming][lc322]")
	{
		Solution322 solution;
		std::vector<int> coins = { 1, 2, 5 };
		int rst = solution.coinChange(coins, 11);
		REQUIRE(rst == 3);

		coins = { 2 };
		rst = solution.coinChange(coins, 3);
		REQUIRE(rst == -1);

		coins = { 1 };
		rst = solution.coinChange(coins, 0);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC322
