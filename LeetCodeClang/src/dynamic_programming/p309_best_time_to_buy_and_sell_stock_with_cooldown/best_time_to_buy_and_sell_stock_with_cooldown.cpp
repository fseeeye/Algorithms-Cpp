#include "best_time_to_buy_and_sell_stock_with_cooldown.h"

// Time:  O(N)
// Space: O(1)
int Solution309::maxProfit(std::vector<int>& prices)
{
	int days = static_cast<int>(prices.size());
	if (days < 1)
		return 0;

	int dp_buy = INT_MIN;
	int dp_cooldown = 0;
	int dp_sell = 0;

	for (auto& price : prices)
	{
		int new_buy = std::max(dp_buy, dp_sell - price);
		int new_cooldown = dp_buy + price;
		int new_sell = std::max(dp_cooldown, dp_sell);
		dp_buy = new_buy;
		dp_cooldown = new_cooldown;
		dp_sell = new_sell;
	}

	return std::max(dp_sell, dp_cooldown);
}
