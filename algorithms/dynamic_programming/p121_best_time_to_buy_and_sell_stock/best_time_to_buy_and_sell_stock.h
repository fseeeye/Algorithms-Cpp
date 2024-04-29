// 动态规划（股票交易问题）
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution121 {
public:
	static int maxProfit(std::vector<int>& prices);

	static void test() {
		std::vector<int> prices = { 7, 1, 5, 3, 6, 4};
		int rst = maxProfit(prices);
		ASSERT(rst == 5);

		prices = { 7, 6, 4, 3, 1 };
		rst = maxProfit(prices);
		ASSERT(rst == 0);
		
		std::cout << "Solution 121 passed!\n";
	}
};
