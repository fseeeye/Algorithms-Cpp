#include "template.h"

// 搜索一个数：左闭右闭
int IntervalSearchTemp::binary_search(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = static_cast<int>(nums.size() - 1);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}

	return -1;
}

// 搜索左边界：左闭右闭
int IntervalSearchTemp::binary_search_left_bound2(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = static_cast<int>(nums.size() - 1);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			right = mid - 1; // 向左收缩边界
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}

	// 检查是否搜索到 target (left = [0, nums.size()], right = [-1, nums.size()-1])
	if (left >= nums.size() || nums[left] != target) 
		return -1;

	return left; // or return right + 1;
}

// 搜索右边界：左闭右闭
int IntervalSearchTemp::binary_search_right_bound2(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = static_cast<int>(nums.size() - 1);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			left = mid + 1; // 向右收缩边界
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}

	// 检查是否搜索到 target (left = [0, nums.size()], right = [-1, nums.size()-1])
	if (right < 0 || nums[right] != target) 
		return -1;

	return right; // or return left - 1;
}

// 搜索左边界：左闭右开
int IntervalSearchTemp::binary_search_left_bound(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = static_cast<int>(nums.size());

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			right = mid; // 向左收缩边界
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
	}
	
	// 检查是否搜索到 target (left = [0, nums.size()], right = [0, nums.size()-1])
	if (left == nums.size() || nums[left] != target) 
		return -1;

	return left; // or return right;
}

// 搜索右边界：左闭右开
int IntervalSearchTemp::binary_search_right_bound(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = static_cast<int>(nums.size());

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			left = mid + 1; // 向右收缩边界
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
	}

	// 检查是否搜索到 target (left = [0, nums.size()], right = [0, nums.size()-1])
	if (right <= 0 || nums[right - 1] != target) 
		return -1;

	return right - 1; // or return left - 1;
}
