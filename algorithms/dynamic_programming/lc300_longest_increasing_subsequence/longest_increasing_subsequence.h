// 动态规划（子序列）问题
// OJ: https://leetcode-cn.com/problems/longest-increasing-subsequence/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC300
{

class Solution300 {
public:
	int lengthOfLIS(std::vector<int>& nums);
	int lengthOfLIS2(std::vector<int>& nums);

};

} // namespace AlgoCpp::Problem::Algorithm::LC300
