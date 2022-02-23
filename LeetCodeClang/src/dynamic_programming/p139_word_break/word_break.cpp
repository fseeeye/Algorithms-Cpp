#include "word_break.h"

// Time:  O()
// Space: O()
bool Solution139::wordBreak(std::string s, std::vector<std::string>& wordDict)
{
	int s_size = static_cast<int>(s.size());
	if (s_size == 0)
		return false;

	std::vector<bool> dp(s_size + 1, false);
	dp[0] = true;

	for (int i = 1; i <= s_size; ++i)
	{
		for (const std::string& word : wordDict)
		{
			int word_size = static_cast<int>(word.size());
			if (i >= word_size && (word == s.substr(i - word_size, word_size)))
			{
				dp[i] = dp[i - word_size];

				if (dp[i])
					break;
			}
		}
	}

	return dp[s_size];
}
