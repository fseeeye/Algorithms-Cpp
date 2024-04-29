#include "01_matrix.h"

// Time:  O()
// Space: O()
std::vector<std::vector<int>> Solution542::updateMatrix(std::vector<std::vector<int>>& mat)
{
	if (mat.empty() || mat[0].empty())
		return {};

	int m = static_cast<int>(mat.size()), n = static_cast<int>(mat[0].size());
	std::vector<std::vector<int>> dp(m, std::vector(n, INT_MAX - 1));

	// Step1: traverse from top-left
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mat[i][j] == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (i != 0)
			{
				dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j]);
			}
			if (j != 0)
			{
				dp[i][j] = std::min(dp[i][j - 1] + 1, dp[i][j]);
			}
		}
	}

	// Step2: traverse from bottom-right
	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			if (mat[i][j] == 0)
				continue;

			if (i != m - 1)
			{
				dp[i][j] = std::min(dp[i + 1][j] + 1, dp[i][j]);
			}
			if (j != n - 1)
			{
				dp[i][j] = std::min(dp[i][j + 1] + 1, dp[i][j]);
			}
		}
	}

	return dp;
}
