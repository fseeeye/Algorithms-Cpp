// 深度优先搜索
// OJ: https://leetcode-cn.com/problems/number-of-closed-islands/

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution1254 {
public:
	static int closedIsland(std::vector<std::vector<int>>& grid);
	static bool closedIslandDFS(std::vector<std::vector<int>>& grid, int x, int y);

	static void test() {
		std::vector<std::vector<int>> grid = {
			{1,1,1,1,1,1,1,0} ,{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}
		};
		int rst = closedIsland(grid);
		ASSERT(rst == 2);

		grid = {
			{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}
		};
		rst = closedIsland(grid);
		ASSERT(rst == 5);
		
		std::cout << "Solution 1254 passed!\n";
	}
private:
	constexpr static int dir[5] = { -1, 0, 1, 0, -1 };
};
