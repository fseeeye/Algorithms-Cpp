#include "target_sum.h"

// Time:  O()
// Space: O()
int Solution494::findTargetSumWays(std::vector<int>& nums, int target)
{
	int ways = 0;

	dfs(nums, target, 0, 0, ways);

	return ways;
}

void Solution494::dfs(std::vector<int>& nums, int target, int sum, int index, int& ways)
{
	if (index >= nums.size())
	{
		if (sum == target)
			ways++;
		return;
	}

	dfs(nums, target, sum + nums[index], index + 1, ways);
	dfs(nums, target, sum - nums[index], index + 1, ways);
}
