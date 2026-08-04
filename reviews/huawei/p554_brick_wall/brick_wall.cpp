#include "brick_wall.h"

#include <unordered_map>

// Time:  O()
// Space: O()
int Solution554::leastBricks(std::vector<std::vector<int>>& wall)
{
	// calc height
	int height = static_cast<int>(wall.size()), width = 0;
	for (int brick : wall[0])
	{
		width += brick;
	}

	// record boundary
	std::unordered_map<int, int> boundaries;
	for (std::vector<int>& level : wall)
	{
		int current_pos = 0;
		for (int i = 0; i < level.size() - 1; ++i)
		{
			current_pos += level[i];
			boundaries[current_pos] += 1;
		}
	}

	// find max boundary
	int max_boundary = 0;
	for (auto& boundary : boundaries)
	{
		max_boundary = std::max(max_boundary, boundary.second);
	}

	// calc rst
	return height - max_boundary;
}
