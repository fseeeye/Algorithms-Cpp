// 动态规划（字符串编辑问题）
// OJ: https://leetcode-cn.com/problems/2-keys-keyboard/
#pragma once

#include <iostream>

#include "common.h"

class Solution650 {
public:
	int minSteps(int n);

	void test() {
		int rst = minSteps(3);
		ASSERT(rst == 3);

		rst = minSteps(1);
		ASSERT(rst == 0);
		
		std::cout << "Solution 650 passed!\n";
	}
};
