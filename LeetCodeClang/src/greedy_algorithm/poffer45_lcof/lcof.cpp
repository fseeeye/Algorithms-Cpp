#include "lcof.h"

#include <numeric>
#include <algorithm>

// Time:  O(NlogN)
// Space: O(N)
std::string SolutionO45::minNumber(std::vector<int>& nums)
{
	std::vector<std::string> snums;
	std::string rst;

	// nums to vector string
	for (auto num : nums) {
		snums.push_back(std::to_string(num));
	}

	// sort
	std::sort(snums.begin(), snums.end(), [](std::string& a, std::string& b) {
		return a + b < b + a;
	});

	// vector to string
	for (auto& s : snums) {
		rst.append(s);
	}

	return rst;
}
