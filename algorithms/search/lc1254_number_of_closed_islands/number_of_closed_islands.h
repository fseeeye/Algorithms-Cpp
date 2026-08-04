// 深度优先搜索
// OJ: https://leetcode-cn.com/problems/number-of-closed-islands/

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC1254
{

class Solution1254 {
public:
	static int closedIsland(std::vector<std::vector<int>>& grid);
	static bool closedIslandDFS(std::vector<std::vector<int>>& grid, int x, int y);

private:
	constexpr static int dir[5] = { -1, 0, 1, 0, -1 };
};

} // namespace AlgoCpp::Problem::Algorithm::LC1254
