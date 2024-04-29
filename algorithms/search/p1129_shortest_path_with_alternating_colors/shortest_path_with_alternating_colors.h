// BFS
// OJ: https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution1129 {
public:
	static std::vector<int> shortestAlternatingPaths(int n, std::vector<std::vector<int>>& redEdges, std::vector<std::vector<int>>& blueEdges);

	static void test() {
		
		std::cout << "Solution 1129 passed!\n";
	}
};
