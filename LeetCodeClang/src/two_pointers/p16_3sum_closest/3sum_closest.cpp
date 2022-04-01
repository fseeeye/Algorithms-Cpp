#include "3sum_closest.h"

#include <algorithm>

// Time:  O()
// Space: O()
int Solution016::threeSumClosest(std::vector<int>& nums, int target)
{
	int rst = 3001;

	// sort
	std::sort(nums.begin(), nums.end());

	// traverse a
	for (int i = 0; i < nums.size(); ++i)
	{
		// two point b / c
		int l = i + 1;
		int r = static_cast<int>(nums.size()) - 1;

		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];

			if (sum == target)
				return sum;

			rst = closed(target, rst, sum);

			if (sum < target)
				++l;
			else
				--r;
		}
	}

	return rst;
}

int Solution016::closed(int target, int num1, int num2)
{
	return std::abs(num1 - target) < std::abs(num2 - target) ? num1 : num2;
}
