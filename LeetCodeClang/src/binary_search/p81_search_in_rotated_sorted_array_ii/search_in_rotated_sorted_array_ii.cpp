#include "search_in_rotated_sorted_array_ii.h"

// Time:  O()
// Space: O()
bool Solution081::search(std::vector<int>& nums, int target)
{
	int l = 0, r = static_cast<int>(nums.size() - 1), mid;

	while (l <= r)
	{
		mid = l + (r - l) / 2;

		if (nums[mid] == target)
		{
			return true;
		}

		if (nums[l] == nums[mid]) // 无法判断左右两个区间哪个是单调递增
		{
			++l;
		}
		else if (nums[l] < nums[mid]) // 左区间单调递增
		{
			// 判断目标值是否存在于左区间中
			if (target >= nums[l] && target < nums[mid])
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		else // 右区间单调递增
		{
			// 判断目标值是否存在于右区间中
			if (target <= nums[r] && target > nums[mid])
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
	}

	return false;
}
