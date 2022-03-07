// 动态规划（股票交易问题）
// OJ: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution309 {
public:
	static int maxProfit(std::vector<int>& prices);

	static void test() {
		std::vector<int> prices = { 1, 2, 3, 0, 2 };
		int rst = maxProfit(prices);
		ASSERT(rst == 3);

		prices = { 1 };
		rst = maxProfit(prices);
		ASSERT(rst == 0);
		
		std::cout << "Solution 309 passed!\n";
	}
};
