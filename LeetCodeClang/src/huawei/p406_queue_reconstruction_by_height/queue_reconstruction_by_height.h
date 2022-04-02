// 队列
// OJ: https://leetcode-cn.com/problems/queue-reconstruction-by-height/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution406 {
public:
	static std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people);

	static void test() {
		
		std::cout << "Solution 406 passed!\n";
	}
};
