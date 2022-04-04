// BFS
// OJ: https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution1091 {
public:
	static int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid);

	static void test() {
		std::vector<std::vector<int>> grid = {
			{ 0, 0, 0},
			{ 1, 0, 0},
			{ 1, 1, 0}
		};
		int rst = shortestPathBinaryMatrix(grid);
		ASSERT(rst == 3);
		
		std::cout << "Solution 1091 passed!\n";
	}
private:
	constexpr static int dirs[8][2] = { 
		{-1, -1}, {0, -1}, {1, -1},
		{-1, 0}, {1, 0},
		{-1, 1}, {0, 1}, {1, 1},
	};
};
