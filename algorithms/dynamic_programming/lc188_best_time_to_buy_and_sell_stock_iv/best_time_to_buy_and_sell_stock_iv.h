// 动态规划（股票交易问题）
// OJ: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC188
{

class Solution188 {
public:
	static int maxProfit(int k, std::vector<int>& prices);

	static int maxProfitUnlimited(std::vector<int>& prices);

};

} // namespace AlgoCpp::Problem::Algorithm::LC188
