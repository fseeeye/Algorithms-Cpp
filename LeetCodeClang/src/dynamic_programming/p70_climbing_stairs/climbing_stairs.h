// 动态规划问题（一维）
// OJ: https://leetcode-cn.com/problems/climbing-stairs/
#pragma once

#include <iostream>

#include "Tester.h"

class Solution70 {
public:
	int climbStairs(int n);

	void test() {
		int rst1 = climbStairs(2);
		int rst2 = climbStairs(3);

		ASSERT(rst1 == 2);
		ASSERT(rst2 == 3);

		std::cout << "Solution 70 passed!\n";
	}
};
