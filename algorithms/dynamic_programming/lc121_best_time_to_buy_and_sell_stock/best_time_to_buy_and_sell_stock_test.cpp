#include "best_time_to_buy_and_sell_stock.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC121
{

	TEST_CASE("LC121 Best Time to Buy and Sell Stock", "[problem][algorithm][dynamic_programming][lc121]")
	{
		Solution121 solution;
		std::vector<int> prices = { 7, 1, 5, 3, 6, 4};
		int rst = solution.maxProfit(prices);
		REQUIRE(rst == 5);

		prices = { 7, 6, 4, 3, 1 };
		rst = solution.maxProfit(prices);
		REQUIRE(rst == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC121
