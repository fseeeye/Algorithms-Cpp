// 广度优先搜索问题
// OJ: https://leetcode-cn.com/problems/shortest-bridge/
#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#include "common.h"

class Solution934 {
public:
	int shortestBridge(std::vector<std::vector<int>>& grid);
	void shortestBridgeDFS(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& seasides, int m, int n, int x, int y);

	void test() {
		std::vector<std::vector<int>> grid = {
			{0,1},
			{1,0}
		};
		int rst = shortestBridge(grid);
		ASSERT(rst == 1);

		grid = {
			{0,1,0},
			{0,0,0},
			{0,0,1}
		};
		rst = shortestBridge(grid);
		ASSERT(rst == 2);

		grid = {
			{1,1,1,1,1},
			{1,0,0,0,1},
			{1,0,1,0,1},
			{1,0,0,0,1},
			{1,1,1,1,1},
		};
		rst = shortestBridge(grid);
		ASSERT(rst == 1);
		
		std::cout << "Solution 934 passed!\n";
	}

private:
	const std::vector<int> dirs = {-1, 0, 1, 0, -1};
};
