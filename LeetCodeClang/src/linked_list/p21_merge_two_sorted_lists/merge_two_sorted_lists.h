// 链表
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	ListNode* mergeTwoListsNonRecursive(ListNode* list1, ListNode* list2);

	void test() {
		
		std::cout << "Solution 21 passed!\n";
	}
};
