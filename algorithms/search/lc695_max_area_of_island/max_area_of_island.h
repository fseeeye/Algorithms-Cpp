// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/max-area-of-island/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC695
{

class Solution695 {
public:
	int maxAreaOfIslandStack(std::vector<std::vector<int>>& grid);

	int maxAreaOfIslandRecurse(std::vector<std::vector<int>>& grid);
	int maxAreaDFS(std::vector<std::vector<int>>& grid, int x, int y);

private:
	static std::vector<int> dirs; // 上下左右方向向量
};

} // namespace AlgoCpp::Problem::Algorithm::LC695
