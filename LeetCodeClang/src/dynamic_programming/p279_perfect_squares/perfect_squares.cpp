#include "perfect_squares.h"

#include <vector>

// Time:  O(n * √n)
// Space: O(n)
int Solution279::numSquares(int n)
{
	std::vector<int> dp(n + 1, INT_MAX);

	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k * k <= i; ++k)
		{
			dp[i] = std::min(dp[i], dp[i - k * k] + 1);
		}
	}

	return dp[n];
}
