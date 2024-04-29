// 分治问题
// OJ: https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution241 {
public:
	static std::vector<int> diffWaysToCompute(std::string expression);
	static std::vector<int> diffWaysToCompute2(std::string expression);

	static void test() {
		std::string expression = "2-1-1";
		std::vector<int> rst = diffWaysToCompute(expression);
		std::vector<int> target = { 2, 0 };
		ASSERT(rst == target);
		rst = diffWaysToCompute2(expression);
		ASSERT(rst == target);

		expression = "2*3-4*5";
		rst = diffWaysToCompute(expression);
		target = { -34, -10, -14, -10, 10 };
		ASSERT(rst == target);
		rst = diffWaysToCompute2(expression);
		ASSERT(rst == target);
		
		std::cout << "Solution 241 passed!\n";
	}
};
