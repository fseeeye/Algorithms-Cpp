#include "edit_distance.h"

#include <vector>

// Time:  O()
// Space: O()
int Solution72::minDistance(std::string word1, std::string word2)
{
	int word1_size = static_cast<int>(word1.length()), word2_size = static_cast<int>(word2.length());
	std::vector<std::vector<int>> dp(word1_size + 1, std::vector<int>(word2_size + 1, 0));

	for (int i = 0; i <= word1_size; ++i)
	{
		for (int j = 0; j <= word2_size; ++j)
		{
			if (i == 0)
			{
				dp[i][j] = j;
			}
			else if (j == 0)
			{
				dp[i][j] = i;
			}
			else
			{
				dp[i][j] = std::min(dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1),
					std::min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
			}
		}
	}

	return dp[word1_size][word2_size];
}
