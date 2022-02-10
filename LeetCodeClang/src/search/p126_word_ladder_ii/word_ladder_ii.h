// 广度优先搜索问题
// OJ: https://leetcode-cn.com/problems/word-ladder-ii/
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Tester.h"

class Solution126 {
public:
	std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
	void findLaddersBacktracking(const std::string& currentBeginWord, const std::string& endWord, std::unordered_map<std::string, std::vector<std::string>>& next, std::vector<std::string>& current_path, std::vector<std::vector<std::string>>& rst);

	void test() {
		std::string beginWord = "hit";
		std::string endWord = "cog";
		std::vector<std::string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
		std::vector<std::vector<std::string>> target = {
			{ "hit", "hot", "dot", "dog", "cog" },
			{ "hit", "hot", "lot", "log", "cog" },
		};
		std::vector<std::vector<std::string>> rst = findLadders(beginWord, endWord, wordList);
		ASSERT(rst == target);

		wordList = { "hot", "dot", "dog", "lot", "log" };
		std::vector<std::vector<std::string>> target2 = {};
		std::vector<std::vector<std::string>> rst2 = findLadders(beginWord, endWord, wordList);
		ASSERT(rst2 == target2);

		wordList = { "a", "b", "c" };
		beginWord = "a";
		endWord = "c";
		std::vector<std::vector<std::string>> target3 = { { "a", "c" } };
		std::vector<std::vector<std::string>> rst3 = findLadders(beginWord, endWord, wordList);
		ASSERT(rst3 == target3);
		
		std::cout << "Solution 126 passed!\n";
	}
};
