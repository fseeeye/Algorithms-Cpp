#include "permutations.h"

#include <algorithm>

// Time:  O(n * n!), n 为数组长度
// Space: O(n), 答案数组 + 递归栈 所占空间
std::vector<std::vector<int>> Solution46::permute(std::vector<int>& nums)
{
	std::vector<std::vector<int>> rst;
	permuteBacktracking(nums, 0, rst);

	return rst;
}

void Solution46::permuteBacktracking(std::vector<int>& nums, int level, std::vector<std::vector<int>>& rst)
{
	int nums_size = static_cast<int>(nums.size());

	if (level == nums_size - 1)
	{
		rst.push_back(nums);
		return;
	}

	// 回溯法递归求解
	for (int i = level; i < nums_size; ++i)
	{
		std::swap(nums[level], nums[i]);
		permuteBacktracking(nums, level + 1, rst);
		std::swap(nums[level], nums[i]);
	}
}
