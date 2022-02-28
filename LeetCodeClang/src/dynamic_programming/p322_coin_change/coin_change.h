// 动态规划（背包问题）
// OJ: https://leetcode-cn.com/problems/coin-change/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution322 {
public:
	int coinChange(std::vector<int>& coins, int amount);

	void test() {
		std::vector<int> coins = { 1, 2, 5 };
		int rst = coinChange(coins, 11);
		ASSERT(rst == 3);

		coins = { 2 };
		rst = coinChange(coins, 3);
		ASSERT(rst == -1);

		coins = { 1 };
		rst = coinChange(coins, 0);
		ASSERT(rst == 0);
		
		std::cout << "Solution 322 passed!\n";
	}
};
