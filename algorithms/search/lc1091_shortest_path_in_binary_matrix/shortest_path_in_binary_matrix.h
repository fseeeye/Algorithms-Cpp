// BFS
// OJ: https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC1091
{

class Solution1091 {
public:
	static int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid);

private:
	constexpr static int dirs[8][2] = {
		{-1, -1}, {0, -1}, {1, -1},
		{-1, 0}, {1, 0},
		{-1, 1}, {0, 1}, {1, 1},
	};
};

} // namespace AlgoCpp::Problem::Algorithm::LC1091
