#include "climbing_stairs.h"

#include <vector>

// Time:  O(N)
// Space: O(1)
int Solution70::climbStairs(int n)
{
	if (n < 2) return n;

	int pre_1 = 1, pre_2 = 1, rst;
	for (int i = 2; i <= n; ++i)
	{
		rst = pre_1 + pre_2;
		pre_2 = pre_1;
		pre_1 = rst;
	}

	return rst;
}
