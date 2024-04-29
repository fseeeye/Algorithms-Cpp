// 动态规划（字符串编辑问题）
// OJ: https://leetcode-cn.com/problems/regular-expression-matching/
#pragma once

#include <iostream>

#include "common.h"

class Solution10 {
public:
	bool isMatch(std::string s, std::string p);

	void test() {
		std::string s = "aa";
		std::string p = "a";
		ASSERT(isMatch(s, p) == false);

		s = "aa";
		p = "a*";
		ASSERT(isMatch(s, p) == true);

		s = "ab";
		p = ".*";
		ASSERT(isMatch(s, p) == true);
		
		std::cout << "Solution 10 passed!\n";
	}
};
