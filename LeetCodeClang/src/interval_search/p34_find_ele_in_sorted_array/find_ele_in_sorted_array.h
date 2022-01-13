// 查找区间问题
// OJ: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution034 {
public:
	std::vector<int> searchRange(std::vector<int>& nums, int target);

	void test() {
		std::vector<int> nums = { 5, 7, 7, 8, 8, 10 };
		auto rst1 = searchRange(nums, 8);
		auto comp1 = std::vector<int>{ 3, 4 };
		ASSERT(rst1 == comp1);

		auto rst2 = searchRange(nums, 6);
		auto comp2 = std::vector<int>{ -1, -1 };
		ASSERT(rst2 == comp2);
		
		std::cout << "Solution 034 passed!\n";
	}
};