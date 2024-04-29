// 动态规划（子序列）问题
// OJ: https://leetcode-cn.com/problems/longest-increasing-subsequence/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution300 {
public:
	int lengthOfLIS(std::vector<int>& nums);
	int lengthOfLIS2(std::vector<int>& nums);

	void test() {
		std::vector nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
		int rst = lengthOfLIS(nums);
		ASSERT(rst == 4);
		rst = lengthOfLIS2(nums);
		ASSERT(rst == 4);

		nums = { 0, 1, 0, 3, 2, 3 };
		rst = lengthOfLIS(nums);
		ASSERT(rst == 4);
		rst = lengthOfLIS2(nums);
		ASSERT(rst == 4);

		nums = { 7, 7, 7 };
		rst = lengthOfLIS(nums);
		ASSERT(rst == 1);
		rst = lengthOfLIS2(nums);
		ASSERT(rst == 1);
		
		std::cout << "Solution 300 passed!\n";
	}
};
