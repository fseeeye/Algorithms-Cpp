// 快慢指针找单向链表环路问题
// OJ: https://leetcode-cn.com/problems/linked-list-cycle-ii/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution142 {
public:
	ListNode *detectCycle(ListNode *head);

	void test() {
		ListNode node1 = ListNode(3);
		ListNode node2 = ListNode(2);
		ListNode node3 = ListNode(0);
		ListNode node4 = ListNode(-4);
		node1.next = &node2;
		node2.next = &node3;
		node3.next = &node4;
		node4.next = &node2;

		ListNode* rst = detectCycle(&node1);
		ASSERT(rst == &node2);

		std::cout << "Solution 142 passed!\n";
	}
};