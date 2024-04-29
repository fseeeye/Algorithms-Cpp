#include "two_sum_ii.h"

// Time:  O(N) - 其中 n 是数组的长度，两个指针移动的总次数最多为 n 次
// Space: O(1)
std::vector<int> Solution167::twoSum(std::vector<int>& numbers, int target)
{
	// 定义左指针和右指针
	int left = 0, right = static_cast<int>(numbers.size() - 1), sum;

	while (left < right)
	{
		sum = numbers[left] + numbers[right];
		if (sum < target)
			// 如果两者之和小于 target，则左指针向右移动一位
			left++;
		else if (sum > target)
			// 如果两者之和大于 target，则右指针向左移动一位
			right--;
		else
			// 如果两者之和等于 target，则返回两个指针的地址
			break;
	}
	
	return { ++left, ++right };
}
