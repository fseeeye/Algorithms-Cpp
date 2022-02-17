// 动态规划问题（二维）
// OJ: https://leetcode-cn.com/problems/maximal-square/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution221 {
public:
	int maximalSquare(std::vector<std::vector<char>>& matrix);

	void test() {
		std::vector<std::vector<char>> matrix = {
			{'1','0','1','0','0'},
			{'1','0','1','1','1'},
			{'1','1','1','1','1'},
			{'1','0','0','1','0'}
		};
		int rst = maximalSquare(matrix);
		ASSERT(rst == 4);

		matrix = {
			{'0','1'},
			{'1','0'}
		};
		rst = maximalSquare(matrix);
		ASSERT(rst == 1);

		matrix = {
			{'0'}
		};
		rst = maximalSquare(matrix);
		ASSERT(rst == 0);
		
		std::cout << "Solution 221 passed!\n";
	}
};
