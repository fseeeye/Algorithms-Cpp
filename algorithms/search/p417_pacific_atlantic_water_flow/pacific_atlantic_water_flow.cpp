#include "pacific_atlantic_water_flow.h"

std::vector<int> Solution417::dirs = { -1, 0, 1, 0 ,-1 };

// Time:  O(N^2)
// Space: O(2N)
std::vector<std::vector<int>> Solution417::pacificAtlantic(std::vector<std::vector<int>>& heights)
{
	if (heights.empty() || heights[0].empty())
	{
		return {};
	}

	int m = static_cast<int>(heights.size()), n = static_cast<int>(heights[0].size());
	std::vector<std::vector<bool>> can_reach_pacific(m, std::vector<bool>(n, false));
	std::vector<std::vector<bool>> can_reach_atlantic(m, std::vector<bool>(n, false));

	for (int i = 0; i < m; ++i)
	{
		pacificAtlanticDFS(heights, can_reach_pacific, i, 0); // 遍历左边界
		pacificAtlanticDFS(heights, can_reach_atlantic, i, n - 1); // 遍历右边界
	}

	for (int j = 0; j < n; ++j)
	{
		pacificAtlanticDFS(heights, can_reach_pacific, 0, j); // 遍历上边界
		pacificAtlanticDFS(heights, can_reach_atlantic, m - 1, j); // 遍历下边界
	}

	// 找到满足条件的点
	std::vector<std::vector<int>> rst = {};
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (can_reach_pacific[i][j] == true && can_reach_atlantic[i][j] == true)
			{
				rst.push_back({i, j});
			}
		}
	}

	return rst;
}

void Solution417::pacificAtlanticDFS(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& can_reach, int x, int y)
{
	if (can_reach[x][y] == true)
	{
		return;
	}

	can_reach[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int new_x = x + dirs[i];
		int new_y = y + dirs[i + 1];

		if (new_x >= 0 && new_x < heights.size() && new_y >=0 && new_y < heights[new_x].size()
			&& heights[x][y] <= heights[new_x][new_y])
		{
			pacificAtlanticDFS(heights, can_reach, new_x, new_y);
		}
	}
}
