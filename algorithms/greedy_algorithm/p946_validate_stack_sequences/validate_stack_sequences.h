// 栈 + 贪心
// OJ: https://leetcode-cn.com/problems/validate-stack-sequences/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution946 {
public:
	static bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);

	static void test() {
		std::vector<int> pushed = { 1, 2, 3, 4, 5 };
		std::vector<int> poped = { 4, 5, 3, 2, 1 };
		ASSERT(validateStackSequences(pushed, poped) == true);

		pushed = { 1, 2, 3, 4, 5 };
		poped = { 4, 3, 5, 1, 2 };
		ASSERT(validateStackSequences(pushed, poped) == false);
		
		std::cout << "Solution 946 passed!\n";
	}
};
