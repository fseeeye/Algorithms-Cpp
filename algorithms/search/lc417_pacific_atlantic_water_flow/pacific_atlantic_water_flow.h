// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC417
{

class Solution417 {
public:
	std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);
	void pacificAtlanticDFS(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& can_reach, int x, int y);

private:
	static std::vector<int> dirs;
};

} // namespace AlgoCpp::Problem::Algorithm::LC417
