#include "best_time_to_buy_and_sell_stock_iv.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC188
{

	TEST_CASE("LC188 Best Time to Buy and Sell Stock IV", "[problem][algorithm][dynamic_programming][lc188]")
	{
		Solution188 solution;
		int k = 2;
		std::vector<int> prices = { 2, 4, 1 };
		int rst = solution.maxProfit(k, prices);
		REQUIRE(rst == 2);

		k = 2;
		prices = { 3, 2, 6, 5, 0, 3 };
		rst = solution.maxProfit(k, prices);
		REQUIRE(rst == 7);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC188
