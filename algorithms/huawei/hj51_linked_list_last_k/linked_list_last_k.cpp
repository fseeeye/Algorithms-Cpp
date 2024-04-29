#include "linked_list_last_k.h"

#include <bits/stdc++.h>

void HJ51::native_main()
{
	int list_len;
	
	while (std::cin >> list_len)
	{
		// handle input
		ListNode* head = new ListNode();
		ListNode* current = head;

		int value;
		ListNode* temp_node;
		for (int i = 0; i < list_len; i++)
		{
			std::cin >> value;
			temp_node = new ListNode(value);

			current->m_pNext = temp_node;
			current = temp_node;
		}
		current->m_pNext = nullptr;

		// find last k node (slow fast ptr)
		int k;
		std::cin >> k;

		temp_node = find_node(head->m_pNext, k);
		if (temp_node != nullptr)
		{
			std::cout << temp_node->m_nKey << std::endl;
		}
	}
}

HJ51::ListNode* HJ51::find_node(ListNode* head, int k)
{
	ListNode* slow = head, * fast = head;

	for (int i = 0; i < k; i++)
	{
		if (fast == nullptr)
			return nullptr;
		fast = fast->m_pNext;
	}

	while (fast != nullptr)
	{
		slow = slow->m_pNext;
		fast = fast->m_pNext;
	}

	return slow;
}
