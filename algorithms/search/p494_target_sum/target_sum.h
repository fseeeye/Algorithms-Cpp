// DFS
// OJ: https://leetcode-cn.com/problems/target-sum/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution494 {
public:
	static int findTargetSumWays(std::vector<int>& nums, int target);
	static void dfs(std::vector<int>& nums, int target, int sum, int index, int& ways);

	static void test() {
		std::vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int rst = findTargetSumWays(nums, target);
		ASSERT(rst == 5);

		std::cout << "Solution 494 passed!\n";
	}
};
