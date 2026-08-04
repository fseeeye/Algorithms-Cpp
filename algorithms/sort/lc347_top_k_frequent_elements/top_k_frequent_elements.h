// 桶排序问题
// OJ: https://leetcode-cn.com/problems/top-k-frequent-elements/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Problem::Algorithm::LC347
{

class Solution347 {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k);

};

} // namespace AlgoCpp::Problem::Algorithm::LC347
