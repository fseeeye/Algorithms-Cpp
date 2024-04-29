#include "best_time_to_buy_and_sell_stock_iv.h"

#include <algorithm>

// Time:  O()
// Space: O()
int Solution188::maxProfit(int k, std::vector<int>& prices)
{
	int days = static_cast<int>(prices.size());
	if (days < 2)
		return 0;
	else if (2 * k >= days)
		// var `k` is useless
		return maxProfitUnlimited(prices);

	std::vector<int> dp_buy(k + 1, INT_MIN), dp_sell(k + 1, 0);
	
	for (auto& price: prices)
	{
		for (int j = 1; j <= k; ++j)
		{
			dp_buy[j] = std::max(dp_sell[j - 1] - price, dp_buy[j]);
			dp_sell[j] = std::max(dp_buy[j] + price, dp_sell[j]);
		}
	}

	return *std::max_element(dp_sell.begin(), dp_sell.end());
}

int Solution188::maxProfitUnlimited(std::vector<int>& prices)
{
	int max_profit = 0;

	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] > prices[i - 1])
		{
			max_profit += prices[i] - prices[i - 1];
		}
	}

	return max_profit;
}
