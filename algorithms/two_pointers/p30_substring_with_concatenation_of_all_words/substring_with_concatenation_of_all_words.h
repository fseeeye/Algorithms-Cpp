// 滑动窗口(word)
// OJ: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution30 {
public:
	static std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);

	static void test() {
		std::string s = "barfoothefoobarman";
		std::vector<std::string> words = { "foo", "bar" };
		std::vector<int> rst = findSubstring(s, words);
		auto target = std::vector<int>{ 0, 9 };
		ASSERT(rst == target);

		s = "wordgoodgoodgoodbestword";
		words = { "word","good","best","word" };
		rst = findSubstring(s, words);
		target = std::vector<int>{ };
		ASSERT(rst == target);

		s = "barfoofoobarthefoobarman";
		words = { "bar","foo","the" };
		rst = findSubstring(s, words);
		target = std::vector<int>{ 6, 9, 12 };
		ASSERT(rst == target);

		s = "wordgoodgoodgoodbestword";
		words = { "word", "good", "best", "good" };
		rst = findSubstring(s, words);
		target = std::vector<int>{ 8 };
		ASSERT(rst == target);
		
		std::cout << "Solution 30 passed!\n";
	}
};
