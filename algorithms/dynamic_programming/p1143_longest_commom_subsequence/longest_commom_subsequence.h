// 动态规划（子序列）问题
// OJ: https://leetcode-cn.com/problems/longest-common-subsequence/
#pragma once

#include <iostream>

#include "common.h"

class Solution1143 {
public:
	int longestCommonSubsequence(std::string text1, std::string text2);

	void test() {
		std::string text1 = "abcde";
		std::string text2 = "ace";
		int rst = longestCommonSubsequence(text1, text2);
		ASSERT(rst == 3);

		text1 = "abc";
		text2 = "abc";
		rst = longestCommonSubsequence(text1, text2);
		ASSERT(rst == 3);

		text1 = "abc";
		text2 = "def";
		rst = longestCommonSubsequence(text1, text2);
		ASSERT(rst == 0);
		
		std::cout << "Solution 1143 passed!\n";
	}
};
