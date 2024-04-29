#include "kth_largest_element.h"

// Time:  O(N)
// Space: O(1)
int Solution215::findKthLargest(std::vector<int>& nums, int k)
{
	int l = 0, r = static_cast<int>(nums.size() - 1), mid;
	int target_pos = static_cast<int>(nums.size() - k);

	while (l < r)
	{
		mid = quickSelection(nums, l, r);

		if (mid == target_pos)
		{
			return nums[mid];
		} 
		else if (mid < target_pos)
		{
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return nums[l];
}

int Solution215::quickSelection(std::vector<int>& nums, int l, int r)
{
	int pivot = nums[l], first = l + 1, last = r;

	while (true)
	{
		while (first < r && nums[first] <= pivot)
		{
			++first;
		}
		while (last > l && nums[last] >= pivot)
		{
			--last;
		}
		if (first >= last)
		{
			break;
		}
		std::swap(nums[first], nums[last]);
	}
	std::swap(nums[l], nums[last]);

	return last; // last is pivot position
}

