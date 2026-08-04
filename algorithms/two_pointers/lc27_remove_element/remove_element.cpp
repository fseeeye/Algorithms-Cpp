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

} // namespace AlgoCpp::Problem::Algorithm::LC27
