// 动态规划问题（二维）
// OJ: https://leetcode-cn.com/problems/01-matrix/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution542 {
public:
	std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat);

	void test() {
		std::vector<std::vector<int>> mat = {
			{ 0, 0, 0 },
			{ 0, 1, 0 },
			{ 0, 0, 0 },
		};
		std::vector<std::vector<int>> rst = updateMatrix(mat);
		std::vector<std::vector<int>> target = {
			{ 0, 0, 0 },
			{ 0, 1, 0 },
			{ 0, 0, 0 },
		};
		ASSERT(rst == target);

		mat = {
			{ 0, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 1 }
		};
		rst = updateMatrix(mat);
		target = {
			{ 0, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 2, 1 }
		};
		ASSERT(rst == target);
		
		std::cout << "Solution 542 passed!\n";
	}
};
