// 链表
// OJ: https://leetcode-cn.com/problems/palindrome-linked-list/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution234 {
public:
	bool isPalindrome(ListNode* head);

	ListNode* reverseList(ListNode* head, ListNode* prev = nullptr);

	void test() {
		
		std::cout << "Solution 234 passed!\n";
	}
};
