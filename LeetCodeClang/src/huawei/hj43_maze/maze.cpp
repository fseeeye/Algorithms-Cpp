#include "maze.h"

std::vector<int> HJ43::dirs = { -1, 0, 1, 0, -1 };

std::vector<std::pair<int, int>> HJ43::bfs(std::vector<std::vector<int>>& grid, int n, int m)
{
	if (grid[0][0] == 1)
		return {};

	int route_index = 0;
	std::vector<Node> route;
	route.emplace_back(0, 0, -1); // x, y, father index

	std::queue<Node> q;
	q.push({ 0,0,0 }); // x, y, its index


	while (!q.empty())
	{
		int level_size = static_cast<int>(q.size());

		while (level_size--)
		{
			Node current = q.front();
			int x = current.x, y = current.y;
			q.pop();

			// if end
			if (x == n - 1 && y == m - 1)
			{
				std::vector<std::pair<int, int>> path;
				current = route[current.index];
				while (true)
				{
					path.emplace_back(current.x, current.y);

					if (current.index == -1)
					{
						std::reverse(path.begin(), path.end());
						return path;
					}

					current = route[current.index];
				}
			}

			// visited
			grid[x][y] = 1;

			// search four dirs
			for (int i = 0; i < 4; i++)
			{
				int new_x = x + dirs[i], new_y = y + dirs[i + 1];

				if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m
					&& grid[new_x][new_y] == 0)
				{
					route.emplace_back(new_x, new_y, current.index);

					++route_index;
					q.push({ new_x, new_y, route_index });
				}
			}
		}
	}

	return {};
}

void HJ43::native_main()
{
	// handle input
	int n = 2, m = 2;
	std::cin >> n >> m;

	std::vector<std::vector<int>> grid(n, std::vector<int>(m));
	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> tmp;
			grid[i][j] = tmp;
		}
	}

	// bfs
	std::vector<std::pair<int, int>> path = bfs(grid, n, m);

	// output rst
	for (auto [x, y] : path)
	{
		printf("(%i,%i)\n", x, y);
	}
}
