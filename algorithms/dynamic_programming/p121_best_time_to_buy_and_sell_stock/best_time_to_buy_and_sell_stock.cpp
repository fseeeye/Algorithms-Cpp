#include "best_time_to_buy_and_sell_stock.h"

// Time:  O()
// Space: O()
int Solution121::maxProfit(std::vector<int>& prices)
{
	int buy = INT_MAX, max_income = 0;

	for (auto& price : prices)
	{
		buy = std::min(buy, price);
		max_income = std::max(max_income, price - buy);
	}

	return max_income;
}
