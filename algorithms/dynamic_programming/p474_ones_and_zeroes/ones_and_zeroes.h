// 动态规划（背包问题）
// OJ: https://leetcode-cn.com/problems/ones-and-zeroes/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution474 {
public:
	int findMaxForm(std::vector<std::string>& strs, int m, int n);

	std::pair<int, int> countStr01(std::string& str);

	void test() {
		std::vector<std::string> strs = { "10", "0001", "111001", "1", "0" };
		int rst = findMaxForm(strs, 5, 3);
		ASSERT(rst == 4);

		strs = { "10", "0", "1" };
		rst = findMaxForm(strs, 1, 1);
		ASSERT(rst == 2);
		
		std::cout << "Solution 474 passed!\n";
	}
};
