#include "word_search.h"

// Time:  O(M * N * 3^L), L 为 word 长度
// Space: O(M * N), visited 数组 + 栈深度
bool Solution79::exist(std::vector<std::vector<char>>& board, std::string word)
{
	if (board.empty() || board[0].empty() || word.empty())
		return false;

	int m = static_cast<int>(board.size()), n = static_cast<int>(board[0].size());
	std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
	bool rst = false;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			existBackTracking(board, word, visited, 0, i, j, rst);
		}
	}

	return rst;
}

void Solution79::existBackTracking(const std::vector<std::vector<char>>& board, const std::string& word, std::vector<std::vector<bool>>& visited, int word_pos, int i, int j, bool& rst)
{
	// 验证边界
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
		return;
	// 验证当前矩阵位置与字符串字符是否相等
	if (visited[i][j] || rst == true || board[i][j] != word[word_pos])
		return;
	// 验证是否已经匹配完整个字符串
	if (word_pos == word.size() - 1)
	{
		rst = true;
		return;
	}

	// 回溯法递归搜索
	visited[i][j] = true;
	for (int k = 0; k < 4; ++k)
	{
		existBackTracking(board, word, visited, word_pos + 1, i + dirs[k], j + dirs[k + 1], rst);
	}
	visited[i][j] = false;
}
