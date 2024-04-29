// XX问题
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <vector>
#include <iostream>

#include "common.h"

class Solution167 {
public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target);

	void test() {
		std::vector<int> numbers1 = { 2, 7, 11, 15 };
		std::vector<int> answer1 = { 1, 2 };
		std::vector<int> rst1 = twoSum(numbers1, 9);
		ASSERT(rst1 == answer1);

		std::cout << "Solution 167 passed!\n";
	}
};