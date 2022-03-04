// 动态规划（字符串编辑问题）
// OJ: https://leetcode-cn.com/problems/edit-distance/
#pragma once

#include <iostream>

#include "Tester.h"

class Solution72 {
public:
	int minDistance(std::string word1, std::string word2);

	void test() {
		std::string word1 = "horse";
		std::string word2 = "ros";
		int rst = minDistance(word1, word2);
		ASSERT(rst == 3);

		word1 = "intention";
		word2 = "execution";
		rst = minDistance(word1, word2);
		ASSERT(rst == 5);
		
		std::cout << "Solution 72 passed!\n";
	}
};
