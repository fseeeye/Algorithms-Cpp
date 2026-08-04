#include "best_time_to_buy_and_sell_stock_with_cooldown.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC309
{

	TEST_CASE("LC309 Best Time to Buy and Sell Stock with Cooldown", "[problem][algorithm][dynamic_programming][lc309]")
	{
		Solution309 solution;
		std::vector<int> prices = { 1, 2, 3, 0, 2 };
		int rst = solution.maxProfit(prices);
		REQUIRE(rst == 3);

		prices = { 1 };
		rst = solution.maxProfit(prices);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC309
