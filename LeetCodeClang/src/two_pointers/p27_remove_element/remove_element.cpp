#include "remove_element.h"

// Time:  O()
// Space: O()
int Solution027::removeElement(std::vector<int>& nums, int val)
{
	int slow = 0, fast = 0;

	while (fast < nums.size())
	{
		if (nums[fast] != val)
		{
			nums[slow] = nums[fast];
			slow++;
		}

		fast++;
	}

	return slow;
}
