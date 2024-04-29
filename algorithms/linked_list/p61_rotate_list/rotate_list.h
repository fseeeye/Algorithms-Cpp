// 链表
// OJ: https://leetcode-cn.com/problems/rotate-list/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution061 {
public:
	ListNode* rotateRight(ListNode* head, int k);

	static void test() {
		
		std::cout << "Solution 061 passed!\n";
	}
};
