#include "max_area_of_island.h"

#include <stack>
#include <utility>

std::vector<int> dirs{ -1, 0, 1, 0, -1 }; // 上下左右方向向量

// method1: stack
// Time:  O(N), N 为所有网格的数量
// Space: O(N), N 为所有网格的数量
int Solution695::maxAreaOfIslandStack(std::vector<std::vector<int>>& grid)
{
	int m = static_cast<int>(grid.size()), n = m ? static_cast<int>(grid[0].size()) : 0;
	int max_area = 0, current_area;

	// 遍历所有土地
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 计算土地连成的岛屿面积，并更新最大岛屿面积
			if (grid[i][j] == 1)
			{
				grid[i][j] = 0;
				current_area = 1;

				std::stack<std::pair<int, int>> islands;
				islands.push({i, j});

				while (!islands.empty())
				{
					auto [island_x, island_y] = islands.top();
					islands.pop();

					int new_x, new_y;
					for (int k = 0; k < 4; k++)
					{
						new_x = island_x + dirs[k], new_y = island_y + dirs[k + 1];
						if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y])
						{
							grid[new_x][new_y] = 0;
							++current_area;
							islands.push({ new_x, new_y });
						}
					}

					max_area = std::max(max_area, current_area);
				}
			}
		}
	}

	return max_area;
}

// method2: recurse
// Time:  O(N), N 为所有网格的数量
// Space: O(N), N 为所有网格的数量
int Solution695::maxAreaOfIslandRecurse(std::vector<std::vector<int>>& grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;

	int max_area = 0;

	// 遍历所有土地
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
				max_area = std::max(max_area, maxAreaDFS(grid, i, j));
		}
	}

	return max_area;
}

int Solution695::maxAreaDFS(std::vector<std::vector<int>>& grid, int x, int y)
{
	if (grid[x][y] == 0)
		return 0;
	grid[x][y] = 0;
	// 计算当前土地组成岛屿的面积
	int area = 1;
	int new_x, new_y;
	for (int k = 0; k < 4; ++k)
	{
		new_x = x + dirs[k], new_y = y + dirs[k + 1];
		if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size())
		{
			area += maxAreaDFS(grid, new_x, new_y);
		}
	}

	return area;
}
