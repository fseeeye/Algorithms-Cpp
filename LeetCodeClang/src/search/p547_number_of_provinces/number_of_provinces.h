// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/number-of-provinces/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution547 {
public:
	int findCircleNum(std::vector<std::vector<int>>& isConnected);
	void findCircleDFS(std::vector<std::vector<int>>& isConnected, int idx, std::vector<bool>& visited);

	void test() {
		std::vector<std::vector<int>> isConnected1 = 
		{
			{1, 1, 0},
			{1, 1, 0},
			{0, 0, 1}
		};
		int rst1 = findCircleNum(isConnected1);
		ASSERT(rst1 == 2);

		std::vector<std::vector<int>> isConnected2 =
		{
			{1, 0, 0},
			{0, 1, 0},
			{0, 0, 1}
		};
		int rst2 = findCircleNum(isConnected2);
		ASSERT(rst2 == 3);

		std::cout << "Solution 547 passed!\n";
	}
};