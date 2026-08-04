// 动态规划（背包问题）
// OJ: https://leetcode-cn.com/problems/ones-and-zeroes/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC474
{

class Solution474 {
public:
	int findMaxForm(std::vector<std::string>& strs, int m, int n);

	std::pair<int, int> countStr01(std::string& str);

};

} // namespace AlgoCpp::Problem::Algorithm::LC474
