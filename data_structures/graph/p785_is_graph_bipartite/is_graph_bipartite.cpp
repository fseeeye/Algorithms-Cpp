#include "is_graph_bipartite.h"

#include <queue>

// Time:  O()
// Space: O()
bool Solution785::isBipartite(std::vector<std::vector<int>>& graph)
{
	int graph_size = static_cast<int>(graph.size());
	if (graph_size == 0)
		return true;

	std::vector<int> color(graph_size, 0);
	std::queue<int> q;

	for (int i = 0; i < graph_size; ++i)
	{
		if (color[i] == 0)
		{
			q.push(i);
			color[i] = 1;
		}

		while (!q.empty())
		{
			int current_node = q.front();
			q.pop();

			for (const int& near_node : graph[current_node])
			{
				if (color[near_node] == 0)
				{
					color[near_node] = color[current_node] == 1 ? 2 : 1;
					q.push(near_node);
				}
				else if (color[near_node] == color[current_node])
				{
					return false;
				}
			}
		}
	}

	return true;
}
