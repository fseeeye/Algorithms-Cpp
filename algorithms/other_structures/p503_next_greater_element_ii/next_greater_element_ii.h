// 单调栈
// OJ: https://leetcode.cn/problems/next-greater-element-ii
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution503 {
public:
	static std::vector<int> nextGreaterElements(std::vector<int>& nums);

public:
	static void test() {
		std::vector<int> nums = { -2, 1 };
		std::vector<int> rst = nextGreaterElements(nums);
		ASSERT(rst == std::vector({ 1, -1 }));
		
		std::cout << "Solution 503 passed!\n";
	}
};
