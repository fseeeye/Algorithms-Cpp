// 链表
// OJ: https://leetcode-cn.com/problems/reverse-linked-list/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC206
{

class Solution206 {
public:
	ListNode* reverseList(ListNode* head, ListNode* prev = nullptr);
	ListNode* reverseListNonRecursive(ListNode* head);

};

} // namespace AlgoCpp::Problem::DataStructure::LC206
