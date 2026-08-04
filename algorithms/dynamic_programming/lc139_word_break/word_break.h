// 动态规划-分割问题
// OJ: https://leetcode-cn.com/problems/word-break/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC139
{

class Solution139 {
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict);

};

} // namespace AlgoCpp::Problem::Algorithm::LC139
