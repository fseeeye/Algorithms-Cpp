// 深度优先搜索问题
// OJ: https://leetcode-cn.com/problems/number-of-provinces/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC547
{

class Solution547 {
public:
	int findCircleNum(std::vector<std::vector<int>>& isConnected);
	void findCircleDFS(std::vector<std::vector<int>>& isConnected, int idx, std::vector<bool>& visited);

};

} // namespace AlgoCpp::Problem::Algorithm::LC547
