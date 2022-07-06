#include "daily_temperatures.h"

#include <stack>

// Time:  O()
// Space: O()
std::vector<int> Solution739::dailyTemperatures(std::vector<int>& temperatures)
{
	int tSize = static_cast<int>(temperatures.size());
	std::stack<int> s;
	std::vector<int> rst(tSize, 0);

	for (int i = 0; i < tSize; i++) {
		while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
			rst[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}

	return rst;
}
