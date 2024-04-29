// 单链表
// OJ: https://leetcode-cn.com/problems/3sum-closest/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution016 {
public:
	static int threeSumClosest(std::vector<int>& nums, int target);
	static int closed(int target, int num1, int num2);

	static void test() {
		std::vector<int> nums = { -1, 2, 1, -4 };
		int target = 1;
		int rst = threeSumClosest(nums, target);
		ASSERT(rst == 2);

		nums = { 0, 0, 0 };
		target = 1;
		rst = threeSumClosest(nums, target);
		ASSERT(rst == 0);
		
		std::cout << "Solution 016 passed!\n";
	}
};
