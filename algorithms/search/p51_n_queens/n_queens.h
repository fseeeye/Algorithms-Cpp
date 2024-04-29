// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/n-queens/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution51 {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n);
	void solveNQueensBackTracking(int n, std::vector<std::vector<std::string>>& rst, std::vector<bool>& visited_columns, std::vector<bool>& visited_ldiag, std::vector<bool>& visited_rdiag, std::vector<std::string>& current_board, int current_row);

	void test() {
		std::vector<std::vector<std::string>> rst1 = solveNQueens(4);
		std::vector<std::vector<std::string>> target1 = {
			{".Q..","...Q","Q...","..Q."},
			{"..Q.","Q...","...Q",".Q.."}
		};
		ASSERT(rst1 == target1);

		std::cout << "Solution 51 passed!\n";
	}
};