// 链表
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC21
{

class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	ListNode* mergeTwoListsNonRecursive(ListNode* list1, ListNode* list2);

};

} // namespace AlgoCpp::Problem::DataStructure::LC21
