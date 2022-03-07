// 动态规划（股票交易问题）
// OJ: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution188 {
public:
	static int maxProfit(int k, std::vector<int>& prices);

	static int maxProfitUnlimited(std::vector<int>& prices);

	static void test() {
		int k = 2;
		std::vector<int> prices = { 2, 4, 1 };
		int rst = maxProfit(k, prices);
		ASSERT(rst == 2);

		k = 2;
		prices = { 3, 2, 6, 5, 0, 3 };
		rst = maxProfit(k, prices);
		ASSERT(rst == 7);

		std::cout << "Solution 188 passed!\n";
	}
};
