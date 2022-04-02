// 双指针
// OJ: https://leetcode-cn.com/problems/remove-element/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution027 {
public:
	static int removeElement(std::vector<int>& nums, int val);

	static void test() {
		
		std::cout << "Solution 027 passed!\n";
	}
};
