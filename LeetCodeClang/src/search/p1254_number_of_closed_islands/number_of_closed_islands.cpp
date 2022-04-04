#include "number_of_closed_islands.h"

// Time:  O()
// Space: O()
int Solution1254::closedIsland(std::vector<std::vector<int>>& grid)
{
	int n = static_cast<int>(grid.size()), m = static_cast<int>(grid[0].size());
	if (n <= 2 || m <= 2)
		return 0;

	int closed_island_num = 0;

	for (int i = 1; i < n - 1; i++) // ignore boundary
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (grid[i][j] == 0 && closedIslandDFS(grid, i, j))
				++closed_island_num;
		}
	}

	return closed_island_num;
}

bool Solution1254::closedIslandDFS(std::vector<std::vector<int>>& grid, int x, int y)
{
	grid[x][y] = 1;

	bool rst = true;
	for (int k = 0; k < 4; k++)
	{
		int new_x = x + dir[k], new_y = y + dir[k+1];

		if (grid[new_x][new_y] == 0)
		{
			if (new_x > 0 && new_x < grid.size() - 1 && new_y > 0 && new_y < grid[0].size() - 1)
			{
				if (!closedIslandDFS(grid, new_x, new_y))
					rst = false;
			}
			else
			{
				rst = false;
			}
		}
	}

	return rst;
}
