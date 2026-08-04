// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/n-queens/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC51
{

class Solution51 {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n);
	void solveNQueensBackTracking(int n, std::vector<std::vector<std::string>>& rst, std::vector<bool>& visited_columns, std::vector<bool>& visited_ldiag, std::vector<bool>& visited_rdiag, std::vector<std::string>& current_board, int current_row);

};

} // namespace AlgoCpp::Problem::Algorithm::LC51
