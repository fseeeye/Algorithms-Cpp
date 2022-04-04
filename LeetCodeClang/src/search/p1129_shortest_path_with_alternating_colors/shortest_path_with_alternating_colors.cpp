#include "shortest_path_with_alternating_colors.h"

#include <queue>

// Time:  O()
// Space: O()
std::vector<int> Solution1129::shortestAlternatingPaths(int n, std::vector<std::vector<int>>& redEdges, std::vector<std::vector<int>>& blueEdges)
{
	std::vector<int> min_paths(n, INT_MAX);

	// red/blue directed graph
	std::vector<std::vector<int>> red(n, std::vector<int>()), blue(n, std::vector<int>());
	for (auto& red_edge : redEdges)
	{
		red[red_edge[0]].emplace_back(red_edge[1]);
	}
	for (auto& blue_edge : blueEdges)
	{
		blue[blue_edge[0]].emplace_back(blue_edge[1]);
	}
	// red/blue visited
	std::vector<bool> red_visited(n, false), blue_visited(n, false);

	// bfs
	std::queue<std::pair<int, bool>> q; // false = red, true = blue
	q.push({0, false});
	q.push({0, true});

	red_visited[0] = true;
	blue_visited[0] = true;
	int path_len = 0;

	while (!q.empty())
	{
		int level_size = static_cast<int>(q.size());

		while (level_size--)
		{
			auto [node, color] = q.front();
			q.pop();

			// update min path
			min_paths[node] = std::min(min_paths[node], path_len);
			
			// push node to queue
			if (color == false) // current node need red
			{
				for (auto next_node : red[node])
				{
					if (!blue_visited[next_node])
					{
						blue_visited[next_node] = true;
						q.push({ next_node, true });
					}
				}
			}
			else // current node need blue
			{
				for (auto next_node : blue[node])
				{
					if (!red_visited[next_node])
					{
						red_visited[next_node] = true;
						q.push({ next_node, false });
					}
				}
			}
		}

		++path_len;
	}

	for (auto& min_path : min_paths)
	{
		if (min_path == INT_MAX)
			min_path = -1;
	}

	return min_paths;
}
