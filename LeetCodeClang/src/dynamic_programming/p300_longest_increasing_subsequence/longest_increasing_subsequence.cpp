#include "longest_increasing_subsequence.h"

#include <algorithm>

// Time:  O(n^2)
// Space: O(n)
int Solution300::lengthOfLIS(std::vector<int>& nums)
{
	int nums_size = static_cast<int>(nums.size());
	if (nums_size <= 1)
		return nums_size;
	std::vector<int> dp(nums_size, 1);

	int max_length = 0;

	for (int i = 0; i < nums_size; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
				dp[i] = std::max(dp[i], dp[j] + 1);
		}

		max_length = std::max(max_length, dp[i]);
	}

	return max_length;
}

// Time:  O(n * log(n))
// Space: O(n)
int Solution300::lengthOfLIS2(std::vector<int>& nums)
{
	int nums_size = static_cast<int>(nums.size());
	if (nums_size <= 1)
		return nums_size;

	std::vector<int> dp = { nums[0] };
	for (int i = 1; i < nums_size; ++i)
	{
		if (nums[i] > dp.back())
		{
			dp.push_back(nums[i]);
		}
		else
		{
			auto it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
			*it = nums[i];
		}
	}

	return static_cast<int>(dp.size());
}
