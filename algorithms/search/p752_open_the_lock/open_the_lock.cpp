#include "open_the_lock.h"

#include <queue>
#include <unordered_set>

// Time:  O()
// Space: O()
int Solution752::openLock(std::vector<std::string>& deadends, std::string target)
{
	std::unordered_set<std::string> deadends_set(deadends.begin(), deadends.end());
	std::unordered_set<std::string> visited;

	if (deadends_set.count("0000"))
		return -1;

	// bfs
	std::queue<std::string> q;
	q.push("0000");
	visited.insert("0000");

	auto push = [&](std::string& current) {
		if (!visited.count(current))
		{
			visited.insert(current);
			if (!deadends_set.count(current))
				q.push(current);
		}
	};

	int level = 0;
	
	while (!q.empty())
	{
		int level_size = static_cast<int>(q.size());

		while (level_size--)
		{
			std::string current = q.front();
			q.pop();

			if (current == target)
				return level;

			for (int i = 0; i < 4; i++)
			{
				char val = current[i];

				current[i] = val == '9' ? '0' : val + 1;
				push(current);

				current[i] = val == '0' ? '9' : val - 1;
				push(current);

				current[i] = val;
			}
		}

		++level;
	}

	return -1;
}
