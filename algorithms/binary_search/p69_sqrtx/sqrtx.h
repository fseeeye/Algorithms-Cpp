// 求开方问题
// OJ: https://leetcode-cn.com/problems/sqrtx/
#pragma once

#include <iostream>

#include "common.h"

class Solution69 {
public:
	int mySqrt(int x);

	void test() {
		int rst1 = mySqrt(0);
		ASSERT(rst1 == 0);
		int rst2 = mySqrt(4);
		ASSERT(rst2 == 2);
		int rst3 = mySqrt(8);
		ASSERT(rst3 == 2);

		std::cout << "Solution 069 passed!\n";
	}
};