// XX问题
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution77 {
public:
	std::vector<std::vector<int>> combine(int n, int k);
	void combineBackTracking(std::vector<std::vector<int>>& rst, std::vector<int>& current_comb, int current_pos, int count, int n, int k);

	void test() {
		int n1 = 4, k1 = 2;
		std::vector<std::vector<int>> rst1 = combine(n1, k1);
		std::vector<std::vector<int>> target1 = { {1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };
		ASSERT(rst1 == target1);

		std::cout << "Solution 77 passed!\n";
	}
};