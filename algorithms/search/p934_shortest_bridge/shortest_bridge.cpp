#include "shortest_bridge.h"

// Time:  O(M * N)
// Space: O(M * N)
int Solution934::shortestBridge(std::vector<std::vector<int>>& grid)
{
	if (grid.empty() || grid[0].empty())
		return 0;
	int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());

	// Step1: Find first island lands (DFS)
	std::queue<std::pair<int, int>> seasides;
	bool isFindFirst = false;
	for (int i = 0; i < m; ++i)
	{
		if (isFindFirst) 
			break;
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == 1)
			{
				isFindFirst = true;
				shortestBridgeDFS(grid, seasides, m, n, i, j);
				break;
			}
		}
	}

	// Step2: Find second island & their shortest path len (BFS)
	int path_len = 0;
	int new_x, new_y, current_level_size;
	while (!seasides.empty())
	{
		// traverse current level
		++path_len;
		current_level_size = static_cast<int>(seasides.size());
		while (current_level_size--)
		{
			auto [x, y] = seasides.front();
			seasides.pop();
			// find second island at 4 dirs
			for (int k = 0; k < 4; ++k)
			{
				new_x = x + dirs[k], new_y = y + dirs[k + 1];
				if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
					continue;

				if (grid[new_x][new_y] == 0)
				{
					grid[new_x][new_y] = 2;
					seasides.push({ new_x, new_y });
					continue;
				}
				else if (grid[new_x][new_y] == 2)
					continue;
				else
					return path_len;
			}
		}
	}

	return 0;
}

void Solution934::shortestBridgeDFS(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& seasides, int m, int n, int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n)
		return;
	if (grid[x][y] == 2)
		return;
	else if (grid[x][y] == 0)
	{
		// find all first island seasides
		seasides.push({x, y});
		return;
	}
	else
	{
		grid[x][y] = 2;

		for (int k = 0; k < 4; ++k)
			shortestBridgeDFS(grid, seasides, m, n, x + dirs[k], y + dirs[k+1]);
	}
}
