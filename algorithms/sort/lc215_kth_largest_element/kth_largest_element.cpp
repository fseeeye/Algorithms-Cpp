#include "kth_largest_element.h"

#include <utility>

namespace AlgoCpp::Problem::Algorithm::LC215
{

	// Time:  O(N)
	// Space: O(1)
	int Solution::findKthLargest(std::vector<int>& nums, const int k)
	{
		int left = 0;
		int right = static_cast<int>(nums.size()) - 1;
		const int targetPosition = static_cast<int>(nums.size()) - k;

		while (left < right)
		{
			const int pivotPosition = QuickSelect(nums, left, right);

			if (pivotPosition == targetPosition)
			{
				return nums[pivotPosition];
			}
			if (pivotPosition < targetPosition)
			{
				left = pivotPosition + 1;
			}
			else
			{
				right = pivotPosition - 1;
			}
		}

		return nums[left];
	}

	int Solution::QuickSelect(std::vector<int>& nums, const int left, const int right)
	{
		const int pivot = nums[left];
		int first = left + 1;
		int last = right;

		while (true)
		{
			while (first < right && nums[first] <= pivot)
			{
				++first;
			}
			while (last > left && nums[last] >= pivot)
			{
				--last;
			}
			if (first >= last)
			{
				break;
			}
			std::swap(nums[first], nums[last]);
		}
		std::swap(nums[left], nums[last]);

		return last;
	}

} // namespace AlgoCpp::Problem::Algorithm::LC215
