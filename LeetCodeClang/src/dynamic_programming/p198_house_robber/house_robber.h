// 动态规划问题（一维）
// OJ: https://leetcode-cn.com/problems/house-robber/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution198 {
public:
	int rob(std::vector<int>& nums);

	void test() {
		std::vector nums = { 1, 2, 3, 1 };
		int rst = rob(nums);
		ASSERT(rst == 4);

		nums = { 2, 7, 9, 3, 1 };
		rst = rob(nums);
		ASSERT(rst == 12);

		nums = {};
		rst = rob(nums);
		ASSERT(rst == 0);

		nums = { 7 };
		rst = rob(nums);
		ASSERT(rst == 7);
		
		std::cout << "Solution 198 passed!\n";
	}
};
