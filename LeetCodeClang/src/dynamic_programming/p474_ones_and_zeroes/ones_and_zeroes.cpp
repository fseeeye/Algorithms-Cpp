#include "ones_and_zeroes.h"

// Time:  O()
// Space: O()
int Solution474::findMaxForm(std::vector<std::string>& strs, int m, int n)
{
	std::vector<std::vector<int>> dp(m + 1, std::vector(n + 1, 0));

	for (auto& str : strs)
	{
		auto [count_0, count_1] = countStr01(str);

		for (int i = m; i >= count_0; --i)
		{
			for (int j = n; j >= count_1; --j)
			{
				dp[i][j] = std::max(dp[i][j], dp[i - count_0][j - count_1] + 1);
			}
		}
	}

	return dp[m][n];
}

std::pair<int, int> Solution474::countStr01(std::string& str)
{
	int count_0 = 0, count_1 = 0;

	for (auto& c : str)
	{
		if (c == '1')
			++count_1;
		else
			++count_0;
	}

	return { count_0, count_1 };
}
