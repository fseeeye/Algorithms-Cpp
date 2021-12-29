// 分配问题
// OJ: https://leetcode-cn.com/problems/candy/
#pragma once

#include <vector>
#include <cassert>
#include <iostream>

#include "Tester.h"

class Solution135 {
public:
	int candy(std::vector<int>& ratings);

	void test() {
		std::vector test1_ratings = { 1, 0, 2 };
		ASSERT(candy(test1_ratings) == 5);

		std::vector test2_ratings = { 1, 2, 2 };
		ASSERT(candy(test2_ratings) == 4);

		std::vector test3_ratings = { 1, 2, 1 };
		ASSERT(candy(test3_ratings) == 4);

		std::vector test4_ratings = { 2, 3, 2, 1 };
		int rst = candy(test4_ratings);
		ASSERT(rst == 7);

		std::cout << "Solution 135 passed!\n";
	}
};