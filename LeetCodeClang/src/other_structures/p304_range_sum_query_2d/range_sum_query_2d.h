// 前缀和
// OJ: https://leetcode.com/problems/range-sum-query-2d-immutable/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution304 {
public:
	Solution304(std::vector<std::vector<int>>& matrix)
	{
		// 初始化积分图
		int m = static_cast<int>(matrix.size()), n = m > 0 ? matrix[0].size() : 0;
		integral = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				integral[i + 1][j + 1] = matrix[i][j] + integral[i][j + 1] + integral[i + 1][j] - integral[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		// 返回范围和
		return integral[row2 + 1][col2 + 1] - integral[row1][col2 + 1] - integral[row2 + 1][col1] + integral[row1][col1];
	}
private:
	std::vector<std::vector<int>> integral;

public:
	static void test() {
		
		std::cout << "Solution 304 passed!\n";
	}
};
