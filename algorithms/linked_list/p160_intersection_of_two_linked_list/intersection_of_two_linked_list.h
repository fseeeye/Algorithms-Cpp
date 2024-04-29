// 链表
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution160 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

	void test() {
		
		std::cout << "Solution 160 passed!\n";
	}
};
