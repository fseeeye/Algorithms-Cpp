// 动态规划（背包问题）
// OJ: https://leetcode-cn.com/problems/partition-equal-subset-sum/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution416 {
public:
	bool canPartition(std::vector<int>& nums);

	void test() {
		std::vector<int> nums = { 1, 5, 11, 5 };
		ASSERT(canPartition(nums) == true);

		nums = { 1, 2, 3, 5 };
		ASSERT(canPartition(nums) == false);
		
		std::cout << "Solution 416 passed!\n";
	}
};
