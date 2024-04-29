// 动态规划-分割问题
// OJ: https://leetcode-cn.com/problems/perfect-squares/
#pragma once

#include <iostream>

#include "common.h"

class Solution279 {
public:
	int numSquares(int n);

	void test() {
		int rst = numSquares(12);
		ASSERT(rst == 3);

		rst = numSquares(13);
		ASSERT(rst == 2);
		
		std::cout << "Solution 279 passed!\n";
	}
};
