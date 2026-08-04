// BFS
// OJ: https://leetcode-cn.com/problems/open-the-lock/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Algorithm::LC752
{

class Solution752 {
public:
	static int openLock(std::vector<std::string>& deadends, std::string target);

};

} // namespace AlgoCpp::Problem::Algorithm::LC752
