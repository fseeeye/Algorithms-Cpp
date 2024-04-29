// 分配问题
// OJ: https://leetcode-cn.com/problems/assign-cookies/
#pragma once

#include <vector>
#include <iostream>

#include "common.h"

class Solution455 {
public:
	int findContentChildren(std::vector<int>& g, std::vector<int>& s);

	void test() {
		std::vector test1_g = { 1, 2, 3 };
		std::vector test1_s = { 1, 1 };
		ASSERT(findContentChildren(test1_g, test1_s) == 1);

		std::vector test2_g = { 1, 2 };
		std::vector test2_s = { 1, 2, 3 };
		ASSERT(findContentChildren(test2_g, test2_s) == 2);

		std::cout << "Solution 455 passed!\n";
	}
};