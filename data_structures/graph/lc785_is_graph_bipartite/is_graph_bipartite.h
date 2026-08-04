// 二分图
// OJ: https://leetcode-cn.com/problems/is-graph-bipartite/submissions/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC785
{

class Solution785 {
public:
	bool isBipartite(std::vector<std::vector<int>>& graph);

};

} // namespace AlgoCpp::Problem::DataStructure::LC785
