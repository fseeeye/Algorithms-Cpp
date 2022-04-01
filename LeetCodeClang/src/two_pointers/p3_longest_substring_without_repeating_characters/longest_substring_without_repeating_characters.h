// 滑动窗口
// OJ: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution03 {
public:
	static int lengthOfLongestSubstring(std::string s);

	static void test() {
		std::string s = "abcabcbb";
		int rst = lengthOfLongestSubstring(s);
		ASSERT(rst == 3);

		s = "bbbbb";
		rst = lengthOfLongestSubstring(s);
		ASSERT(rst == 1);

		s = "pwwkew";
		rst = lengthOfLongestSubstring(s);
		ASSERT(rst == 3);
		
		std::cout << "Solution 3 passed!\n";
	}
};
