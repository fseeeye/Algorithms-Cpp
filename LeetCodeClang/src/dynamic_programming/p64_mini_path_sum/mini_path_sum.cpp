#include "mini_path_sum.h"

// Time:  O(n)
// Space: O(1)
int Solution64::minPathSum(std::vector<std::vector<int>>& grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;

	int n = static_cast<int>(grid[0].size());
	std::vector<int> dp(n, 0);

	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0)
			{
				dp[j] = grid[i][j];
			}
			else if (i == 0)
			{
				dp[j] = dp[j - 1] + grid[i][j];
			}
			else if (j == 0)
			{
				dp[j] = dp[j] + grid[i][j];
			}
			else
			{
				dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];
			}
		}
	}

	return dp[n - 1];
}
