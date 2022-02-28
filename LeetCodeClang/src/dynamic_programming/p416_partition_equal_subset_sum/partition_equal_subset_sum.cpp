#include "partition_equal_subset_sum.h"

#include <numeric>

// Time:  O(n x target)
// Space: O(target)
bool Solution416::canPartition(std::vector<int>& nums)
{
	int sum = std::accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0)
		return false;
	int target = sum / 2;

	std::vector<bool> dp(target + 1, false);
	dp[0] = true;

	for (int i = 1; i <= nums.size(); ++i)
	{
		int num = nums[i - 1];
		for (int j = target; j >= num; --j)
		{
			dp[j] = dp[j] || dp[j - num];
		}
	}

	return dp[target];
}
