// 动态规划-分割问题
// OJ: https://leetcode-cn.com/problems/word-break/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution139 {
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict);

	void test() {
		std::string s = "leetcode";
		std::vector<std::string> wordDict = { "leet", "code" };
		ASSERT(wordBreak(s, wordDict) == true);

		s = "applepenapple";
		wordDict = { "apple", "pen" };
		ASSERT(wordBreak(s, wordDict) == true);

		s = "catsandog";
		wordDict = { "cats", "dog", "sand", "and", "cat"};
		ASSERT(wordBreak(s, wordDict) == false);
		
		std::cout << "Solution 139 passed!\n";
	}
};
