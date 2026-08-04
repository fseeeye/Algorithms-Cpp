// 广度优先搜索问题
// OJ: https://leetcode-cn.com/problems/shortest-bridge/
#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC934
{

class Solution934 {
public:
	int shortestBridge(std::vector<std::vector<int>>& grid);
	void shortestBridgeDFS(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& seasides, int m, int n, int x, int y);


private:
	const std::vector<int> dirs = {-1, 0, 1, 0, -1};
};

} // namespace AlgoCpp::Problem::Algorithm::LC934
