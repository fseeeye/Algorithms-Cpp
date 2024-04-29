// 单链表
// OJ: https://leetcode.cn/problems/partition-list/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution086 {
public:
	ListNode* partition(ListNode* head, int x);

	void test() {
		
		std::cout << "Solution 086 passed!\n";
	}
};
