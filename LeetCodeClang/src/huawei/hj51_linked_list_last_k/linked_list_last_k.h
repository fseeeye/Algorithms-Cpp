// XX问题
#pragma once

#include <bits/stdc++.h>

#include "Tester.h"

class HJ51 {
	struct ListNode
	{
		int m_nKey;
		ListNode* m_pNext;

		ListNode()
			: m_nKey(0), m_pNext(nullptr)
		{}

		ListNode(int value)
			: m_nKey(value), m_pNext(nullptr)
		{}
	};

public:
	static void native_main();
	static ListNode* find_node(ListNode* head, int k);

	static void test() {
		std::cout << "Solution 51 start.\n";

		native_main();

		std::cout << "\nSolution 51 done.\n";
	}
};
