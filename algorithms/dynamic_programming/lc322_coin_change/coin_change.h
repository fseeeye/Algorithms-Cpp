// 动态规划（背包问题）
// OJ: https://leetcode-cn.com/problems/coin-change/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC322
{

class Solution322 {
public:
	int coinChange(std::vector<int>& coins, int amount);

};

} // namespace AlgoCpp::Problem::Algorithm::LC322
