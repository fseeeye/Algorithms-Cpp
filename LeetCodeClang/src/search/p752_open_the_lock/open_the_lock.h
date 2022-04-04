// BFS
// OJ: https://leetcode-cn.com/problems/open-the-lock/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution752 {
public:
	static int openLock(std::vector<std::string>& deadends, std::string target);

	static void test() {
		std::vector<std::string> deadends = { "0201","0101","0102","1212","2002" };
		std::string target = "0202";
		int rst = openLock(deadends, target);
		ASSERT(rst == 6);
		
		std::cout << "Solution 752 passed!\n";
	}
};
