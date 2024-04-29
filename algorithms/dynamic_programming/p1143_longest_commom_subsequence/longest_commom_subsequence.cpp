#include "longest_commom_subsequence.h"

#include <vector>

// Time:  O()
// Space: O()
int Solution1143::longestCommonSubsequence(std::string text1, std::string text2)
{
	int text1_size = static_cast<int>(text1.length()), text2_size = static_cast<int>(text2.length());
	if (text1_size == 0 || text2_size == 0)
		return 0;
	
	std::vector<std::vector<int>> dp(text1_size + 1, std::vector<int>(text2_size + 1, 0));

	for (int i = 1; i <= text1_size; ++i)
	{
		for (int j = 1; j <= text2_size; ++j)
		{
			if (text1[i-1] == text2[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[text1_size][text2_size];
}
