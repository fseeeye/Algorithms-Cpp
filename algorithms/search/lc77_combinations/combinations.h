// XX问题
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC77
{

class Solution77 {
public:
	std::vector<std::vector<int>> combine(int n, int k);
	void combineBackTracking(std::vector<std::vector<int>>& rst, std::vector<int>& current_comb, int current_pos, int count, int n, int k);

};

} // namespace AlgoCpp::Problem::Algorithm::LC77
