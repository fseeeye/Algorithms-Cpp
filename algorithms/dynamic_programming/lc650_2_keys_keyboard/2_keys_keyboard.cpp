#include "2_keys_keyboard.h"

#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC650
{

// Time:  O()
// Space: O()
int Solution650::minSteps(int n)
{
	std::vector<int> dp(n + 1);
	/*for (int i = 0; i <= n; ++i)
	{
		if (i > 1)
			dp[i] = i;
	}*/

	for (int i = 2; i<= n; ++i)
	{
		dp[i] = i;

		for (int j = 2; j * j <= i; ++j)
		{
			if (i % j == 0)
			{
				dp[i] = dp[j] + dp[i / j];
				break;
			}
		}
	}

	return dp[n];
}

} // namespace AlgoCpp::Problem::Algorithm::LC650
