// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution417 {
public:
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);
	void pacificAtlanticDFS(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& can_reach, int x, int y);

	void test() {
		std::vector<std::vector<int>> heights = {
			{1,2,2,3,5},
			{3,2,3,4,4},
			{2,4,5,3,1},
			{6,7,1,4,5},
			{5,1,1,2,4}
		};
		std::vector<std::vector<int>> rst = pacificAtlantic(heights);
		std::vector<std::vector<int>> target = { {0, 4},{1, 3},{1, 4},{2, 2},{3, 0},{3, 1},{4, 0} };
		ASSERT(rst == target);
		
		std::cout << "Solution 417 passed!\n";
	}
private:
	static std::vector<int> dirs;
};