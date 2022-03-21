// 拓扑排序
// OJ: https://leetcode-cn.com/problems/course-schedule-ii/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution210 {
public:
	std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);

	void test() {
		
		std::cout << "Solution 210 passed!\n";
	}
};
