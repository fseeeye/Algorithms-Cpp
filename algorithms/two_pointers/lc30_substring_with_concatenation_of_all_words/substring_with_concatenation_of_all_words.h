// 滑动窗口(word)
// OJ: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC30
{

class Solution30 {
public:
	static std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);

};

} // namespace AlgoCpp::Problem::Algorithm::LC30
