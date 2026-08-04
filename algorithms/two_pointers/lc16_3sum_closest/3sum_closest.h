// 单链表
// OJ: https://leetcode-cn.com/problems/3sum-closest/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC16
{

class Solution016 {
public:
	static int threeSumClosest(std::vector<int>& nums, int target);
	static int closed(int target, int num1, int num2);

};

} // namespace AlgoCpp::Problem::Algorithm::LC16
