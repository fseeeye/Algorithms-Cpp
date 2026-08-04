#include "queue_reconstruction_by_height.h"

#include <algorithm>

// Time:  O()
// Space: O()
std::vector<std::vector<int>> Solution406::reconstructQueue(std::vector<std::vector<int>>& people)
{
	std::sort(people.begin(), people.end(), [](std::vector<int>& a, std::vector<int>& b) {
		return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
	});

	std::vector<std::vector<int>> rst;
	for (auto& person : people)
	{
		rst.insert(rst.begin() + person[1], person);
	}

	return rst;
}
