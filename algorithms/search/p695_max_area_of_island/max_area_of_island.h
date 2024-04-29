// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/max-area-of-island/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution695 {
public:
	int maxAreaOfIslandStack(std::vector<std::vector<int>>& grid);

	int maxAreaOfIslandRecurse(std::vector<std::vector<int>>& grid);
	int maxAreaDFS(std::vector<std::vector<int>>& grid, int x, int y);

	void test() {
		std::vector<std::vector<int>> grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
		int rst1 = maxAreaOfIslandStack(grid);
		ASSERT(rst1 == 6);

		grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
		int rst2 = maxAreaOfIslandRecurse(grid);
		ASSERT(rst2 == 6);

		std::cout << "Solution 695 passed!\n";
	}
private:
	static std::vector<int> dirs; // 上下左右方向向量
};