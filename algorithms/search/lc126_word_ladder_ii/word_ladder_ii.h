// 广度优先搜索问题
// OJ: https://leetcode-cn.com/problems/word-ladder-ii/
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC126
{

class Solution126 {
public:
	std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList);
	void findLaddersBacktracking(const std::string& currentBeginWord, const std::string& endWord, std::unordered_map<std::string, std::vector<std::string>>& next, std::vector<std::string>& current_path, std::vector<std::vector<std::string>>& rst);

};

} // namespace AlgoCpp::Problem::Algorithm::LC126
