#include "next_greater_element_ii.h"

#include <stack>

// Time:  O()
// Space: O()
std::vector<int> Solution503::nextGreaterElements(std::vector<int>& nums)
{
	std::stack<int> s; // 单调栈中存储数组下标
	int numsSize = static_cast<int>(nums.size());
	std::vector<int> rst(numsSize, -1);

	for (int i = 0; i < numsSize * 2 - 1; i++) {
		int currentPos = i % numsSize;
		// 从单调栈中取出更小的数
		while (!s.empty() && nums[s.top()] < nums[currentPos]) {
			rst[s.top()] = nums[currentPos];
			s.pop();
		}

		s.push(currentPos);
	}

	return rst;
}
