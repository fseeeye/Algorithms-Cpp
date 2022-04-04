#include "shortest_path_in_binary_matrix.h"

#include <queue>

// Time:  O()
// Space: O()
int Solution1091::shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid)
{
	if (grid[0][0] != 0)
		return -1;

	int path_len = 0, grid_size = static_cast<int>(grid.size());
	std::queue<std::pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		++path_len;

		int level_size = static_cast<int>(q.size());
		while (level_size--)
		{
			auto [x, y] = q.front();
			q.pop();

			if (grid[x][y] == 1)
				continue;
			grid[x][y] = 1;

			// if end
			if (x == grid_size - 1 && y == grid_size - 1)
				return path_len;

			// traverse dirs
			for (auto dir : dirs)
			{
				int new_x = x + dir[0], new_y = y + dir[1];

				if (new_x >= 0 && new_x < grid_size && new_y >= 0 && new_y < grid_size
					&& grid[new_x][new_y] == 0)
				{
					q.push({ new_x, new_y });
				}
			}
		}
	}

	return -1;
}
