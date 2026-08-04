// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/permutations/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC46
{

class Solution46 {
public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums);
	void permuteBacktracking(std::vector<int>& nums, int level, std::vector<std::vector<int>>& rst);

};

} // namespace AlgoCpp::Problem::Algorithm::LC46
