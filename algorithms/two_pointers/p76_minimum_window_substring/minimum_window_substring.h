// XX问题
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>

#include "common.h"

class Solution76 {
public:
	std::string minWindow(std::string s, std::string t);
	std::string minWindow_2(std::string s, std::string t);

	void test() {
		std::string rst1 = minWindow("ADOBECODEBANC", "ABC");
		ASSERT(rst1 == "BANC");

		std::string rst2 = minWindow("a", "a");
		ASSERT(rst2 == "a");

		std::string rst3 = minWindow("a", "aa");
		ASSERT(rst3.empty());

		rst1 = minWindow_2("ADOBECODEBANC", "ABC");
		ASSERT(rst1 == "BANC");

		rst2 = minWindow_2("a", "a");
		ASSERT(rst2 == "a");

		rst3 = minWindow_2("a", "aa");
		ASSERT(rst3.empty());

		std::cout << "Solution 76 passed!\n";
	}
};