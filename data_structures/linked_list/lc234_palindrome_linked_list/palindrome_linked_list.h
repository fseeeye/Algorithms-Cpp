// 链表
// OJ: https://leetcode-cn.com/problems/palindrome-linked-list/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC234
{

class Solution234 {
public:
	bool isPalindrome(ListNode* head);

	ListNode* reverseList(ListNode* head, ListNode* prev = nullptr);

};

} // namespace AlgoCpp::Problem::DataStructure::LC234
