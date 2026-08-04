// DFS
// OJ: https://leetcode-cn.com/problems/target-sum/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC494
{

class Solution494 {
public:
	static int findTargetSumWays(std::vector<int>& nums, int target);
	static void dfs(std::vector<int>& nums, int target, int sum, int index, int& ways);

};

} // namespace AlgoCpp::Problem::Algorithm::LC494
