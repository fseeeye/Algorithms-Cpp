// 链表
// OJ: https://leetcode-cn.com/problems/reverse-linked-list/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution206 {
public:
	ListNode* reverseList(ListNode* head, ListNode* prev = nullptr);
	ListNode* reverseListNonRecursive(ListNode* head);

	void test() {
		
		std::cout << "Solution 206 passed!\n";
	}
};
