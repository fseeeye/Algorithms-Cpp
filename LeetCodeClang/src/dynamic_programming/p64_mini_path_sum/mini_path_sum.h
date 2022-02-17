// 动态规划问题（二维）
// OJ: https://leetcode-cn.com/problems/minimum-path-sum/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution64 {
public:
	int minPathSum(std::vector<std::vector<int>>& grid);

	void test() {
		std::vector<std::vector<int>> grid = {
			{ 1, 3, 1 },
			{ 1, 5, 1 },
			{ 4, 2, 1 }
		};
		int rst = minPathSum(grid);
		ASSERT(rst == 7);

		grid = {
			{ 1, 2, 3 },
			{ 4, 5, 6 }
		};
		rst = minPathSum(grid);
		ASSERT(rst == 12);
		
		std::cout << "Solution 64 passed!\n";
	}
};
