// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/word-search/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution79 {
public:
	bool exist(std::vector<std::vector<char>>& board, std::string word);
	void existBackTracking(const std::vector<std::vector<char>>& board, const std::string& word, std::vector<std::vector<bool>>& visited, int word_pos, int i, int j, bool& rst);

	void test() {
		std::vector<std::vector<char>> board = {
			{'A', 'B', 'C', 'E'},
			{'S', 'F', 'C', 'S'},
			{'A', 'D', 'E', 'E'},
		};
		ASSERT(exist(board, "ABCCED"));
		ASSERT(exist(board, "SEE"));
		ASSERT(!exist(board, "ABCB"));
		
		std::cout << "Solution 79 passed!\n";
	}
private:
	const std::vector<int> dirs = { -1, 0, 1, 0, -1 };
};