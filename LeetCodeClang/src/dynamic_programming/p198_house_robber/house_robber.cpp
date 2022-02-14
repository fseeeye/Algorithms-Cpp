#include "house_robber.h"

// Time:  O()
// Space: O()
int Solution198::rob(std::vector<int>& nums)
{
	int nums_size = nums.size();
	//if (nums_size == 0)
	//	return 0;
	//if (nums_size == 1)
	//	return nums[0];

	int pre1 = 0, pre2 = 0, current_rst = 0;
	for (int i = 0; i < nums_size; ++i)
	{
		current_rst = std::max(pre1, pre2 + nums[i]);
		pre2 = pre1;
		pre1 = current_rst;
	}

	return current_rst;
}
