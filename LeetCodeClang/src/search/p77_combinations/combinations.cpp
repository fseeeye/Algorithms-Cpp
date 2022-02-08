#include "combinations.h"

// Time:  O(..)
// Space: O(..)
std::vector<std::vector<int>> Solution77::combine(int n, int k)
{
	std::vector<std::vector<int>> rst;
	std::vector<int> comb(k, 0);
	int count = 0;
	combineBackTracking(rst, comb, 1, count, n, k);

	return rst;
}

void Solution77::combineBackTracking(std::vector<std::vector<int>>& rst, std::vector<int>& current_comb, int current_pos, int count, int n, int k)
{
	if (count == k)
	{
		rst.push_back(current_comb);
		return;
	}

	for (int i = current_pos; i <= n; ++i)
	{
		current_comb[count++] = i;
		combineBackTracking(rst, current_comb, i + 1, count, n, k);
		--count;
	}
}
