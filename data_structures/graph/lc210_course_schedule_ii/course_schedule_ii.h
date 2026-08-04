// 拓扑排序
// OJ: https://leetcode-cn.com/problems/course-schedule-ii/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC210
{

class Solution210 {
public:
	std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

};

} // namespace AlgoCpp::Problem::DataStructure::LC210
