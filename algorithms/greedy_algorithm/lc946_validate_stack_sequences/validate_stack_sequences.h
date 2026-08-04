// 栈 + 贪心
// OJ: https://leetcode-cn.com/problems/validate-stack-sequences/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC946
{

class Solution946 {
public:
	static bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);

};

} // namespace AlgoCpp::Problem::Algorithm::LC946
