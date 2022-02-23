#include "decode_ways.h"

#include <vector>

// Time:  O()
// Space: O()
int Solution91::numDecodings(std::string s)
{
	int s_size = static_cast<int>(s.size());
	if (s_size == 0)
		return 0;
	int prev = s[0] - '0';
	if (prev == 0)
		return 0;
	if (s_size == 1)
		return 1;

	
	std::vector<int> dp(s_size + 1, 1);
	for (int i = 2; i <= s_size; ++i)
	{
		int current = s[i - 1] - '0';

		if (current == 0 && prev != 1 && prev != 2)
			return 0;
		if (prev == 1 || (prev == 2 && current < 7))
		{
			if (current == 0)
				dp[i] = dp[i - 2];
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		else
			dp[i] = dp[i - 1];

		prev = current;
	}

	return dp[s_size];
}
