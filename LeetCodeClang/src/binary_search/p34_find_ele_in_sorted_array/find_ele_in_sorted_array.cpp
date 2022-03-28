#include "find_ele_in_sorted_array.h"

int my_lower_bound(std::vector<int>& nums, int target)
{
	int l = 0, r = static_cast<int>(nums.size()), mid;

	while (l < r) // 左闭右开
	{
		mid = l + (r - l) / 2;

		if (nums[mid] >= target) // 值与 target 相同时向左移动，最终获得最小边界
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}

	return r; // or l
}

int my_upper_bound(std::vector<int>& nums, int target)
{
	int l = 0, r = static_cast<int>(nums.size()), mid;

	while (l < r) // 左闭右开
	{
		mid = l + (r - l) / 2;

		if (nums[mid] <= target) // 值与 target 相同时向右移动，最终获得最大边界
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}

	return l - 1; // or r
}

// Time:  O(log(N))
// Space: O(1)
std::vector<int> Solution034::searchRange(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) 
		return { -1, -1 };

	int lower_bound = my_lower_bound(nums, target);
	int upper_bound = my_upper_bound(nums, target);

	if (lower_bound >= nums.size() || nums[lower_bound] != target || nums[upper_bound] != target)
		return { -1, -1 };

	return { lower_bound, upper_bound };
}
