// 动态规划问题（一维）
// OJ: https://leetcode-cn.com/problems/arithmetic-slices/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution413 {
public:
	int numberOfArithmeticSlices(std::vector<int>& nums);

	void test() {
		std::vector<int> nums = { 1, 2, 3, 4 };
		int rst = numberOfArithmeticSlices(nums);
		ASSERT(rst == 3);

		nums = { 1 };
		rst = numberOfArithmeticSlices(nums);
		ASSERT(rst == 0);
		
		std::cout << "Solution 413 passed!\n";
	}
};
