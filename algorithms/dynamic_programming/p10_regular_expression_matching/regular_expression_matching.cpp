#include "regular_expression_matching.h"

#include <vector>

// Time:  O(M * N)
// Space: O(M * N)
bool Solution10::isMatch(std::string s, std::string p)
{
	int s_size = static_cast<int>(s.size()), p_size = static_cast<int>(p.size());

	// init dp[0]
	std::vector<std::vector<bool>> dp(s_size + 1, std::vector<bool>(p_size + 1));
	dp[0][0] = true;
	for (int j = 1; j <= p_size; ++j)
	{
		if (p[j - 1] == '*')
		{
			dp[0][j] = dp[0][j - 2];
		}
	}

	for (int i = 1; i <= s_size; ++i)
	{
		for (int j = 1; j <= p_size; ++j)
		{
			if (p[j - 1] == '*')
			{
				if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
				{
					// s[i] match * pattern
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
				}
				else
				{
					// s[i] don't match * pattern
					dp[i][j] = dp[i][j - 2];
				}
			}
			else if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
			{
				// s[i] & p[j] common match
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				// s[i] & p[j] don't match
				dp[i][j] = false;
			}
		}
	}

	return dp[s_size][p_size];
}
