#include "remove_element.h"

namespace AlgoCpp::Problem::Algorithm::LC27
{

	// Time:  O(N)
	// Space: O(1)
	int Solution027::removeElement(std::vector<int>& nums, const int val)
	{
		std::size_t slow = 0;
		std::size_t fast = 0;

		while (fast < nums.size())
		{
			if (nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}

		return static_cast<int>(slow);
	}

	int Solution027::removeElementOpt(std::vector<int>& nums, int val)
	{
		int left = 0;
		int right = static_cast<int>(nums.size()) - 1;

		// 0. if right == left, end
		while (left <= right)
		{
			// 1. right find !val index
			if (nums[right] == val)
			{
				right--;
				continue;
			}
			// 2. left search -> replace with right
			if (nums[left] == val)
			{
				nums[left] = nums[right];
				right--;
			}
			left++;
		}

		return left;
	}

} // namespace AlgoCpp::Problem::Algorithm::LC27
