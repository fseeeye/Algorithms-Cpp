// 拓扑排序
// OJ: https://leetcode.cn/problems/sequence-reconstruction/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC444
{

class Solution444 {
public:
	static bool sequenceReconstruction(std::vector<int>& nums, std::vector<std::vector<int>>& sequences);

};

} // namespace AlgoCpp::Problem::DataStructure::LC444
