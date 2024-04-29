#include "coin_change.h"

// Time:  O()
// Space: O()
int Solution322::coinChange(std::vector<int>& coins, int amount)
{
	std::vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;

	for (auto& coin : coins)
	{
		for (int i = coin; i <= amount; ++i)
		{
			dp[i] = std::min(dp[i], dp[i - coin] + 1);
		}
	}

	return dp[amount] >= amount + 1 ? -1 : dp[amount];
}
