// 旋转数组问题
// OJ: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution081 {
public:
	bool search(std::vector<int>& nums, int target);

	void test() {
		std::vector<int> nums = { 2, 5, 6, 0, 0, 1, 2 };
		bool rst1 = search(nums, 0);
		ASSERT(rst1 == true);
		bool rst2 = search(nums, 3);
		ASSERT(rst2 == false);

		std::cout << "Solution 081 passed!\n";
	}
};