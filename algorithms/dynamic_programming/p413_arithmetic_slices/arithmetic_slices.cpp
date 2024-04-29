#include "arithmetic_slices.h"

#include <numeric>

// Time:  O()
// Space: O()
int Solution413::numberOfArithmeticSlices(std::vector<int>& nums)
{
	int nums_size = static_cast<int>(nums.size());
	if (nums_size < 3)
		return 0;

	int pre1 = 0, rst = 0;

	for (int i = 2; i < nums_size; ++i)
	{
		(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) ? rst += ++pre1 : pre1 = 0;
	}

	return rst;
}
