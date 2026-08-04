// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/word-search/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC79
{

class Solution79 {
public:
	bool exist(std::vector<std::vector<char>>& board, std::string word);
	void existBackTracking(const std::vector<std::vector<char>>& board, const std::string& word, std::vector<std::vector<bool>>& visited, int word_pos, int i, int j, bool& rst);

private:
	const std::vector<int> dirs = { -1, 0, 1, 0, -1 };
};

} // namespace AlgoCpp::Problem::Algorithm::LC79
