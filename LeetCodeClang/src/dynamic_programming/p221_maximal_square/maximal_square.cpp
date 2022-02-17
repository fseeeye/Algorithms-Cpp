#include "maximal_square.h"

// Time:  O(N)
// Space: O(N)
int Solution221::maximalSquare(std::vector<std::vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
		return 0;

	int m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size()), max_rst = 0;
	std::vector<std::vector<int>> dp(m, std::vector(n, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == '1')
			{
				if (i != 0 && j != 0)
				{
					dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
				else
				{
					dp[i][j] = 1;
				}

				max_rst = std::max(max_rst, dp[i][j]);
			}
		}
	}

	return max_rst * max_rst;
}
