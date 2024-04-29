// 动态规划-分割问题
// OJ: https://leetcode-cn.com/problems/decode-ways/
#pragma once

#include <iostream>

#include "common.h"

class Solution91 {
public:
	int numDecodings(std::string s);

	void test() {
		std::string s1 = "12";
		int rst = numDecodings(s1);
		ASSERT(rst == 2);

		std::string s2 = "226";
		rst = numDecodings(s2);
		ASSERT(rst == 3);

		std::string s3 = "0";
		rst = numDecodings(s3);
		ASSERT(rst == 0);
		
		std::cout << "Solution 91 passed!\n";
	}
};
