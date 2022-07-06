// 单调栈
// OJ: https://leetcode.cn/problems/daily-temperatures/submissions/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution739 {
public:
	static std::vector<int> dailyTemperatures(std::vector<int>& temperatures);

	static void test() {
		
		std::cout << "Solution 739 passed!\n";
	}
};
