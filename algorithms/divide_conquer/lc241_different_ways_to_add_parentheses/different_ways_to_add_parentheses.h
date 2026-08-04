// 分治问题
// OJ: https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC241
{

class Solution241 {
public:
	static std::vector<int> diffWaysToCompute(std::string expression);
	static std::vector<int> diffWaysToCompute2(std::string expression);

};

} // namespace AlgoCpp::Problem::Algorithm::LC241
