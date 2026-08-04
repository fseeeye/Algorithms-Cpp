#include "partition_list.h"

// Time:  O(N)
// Space: O(1)
ListNode* Solution086::partition(ListNode* head, int x)
{
	ListNode* small =  new ListNode();
	ListNode* small_head = small;
	ListNode* large = new ListNode();
	ListNode* large_head = large;

	while (head != nullptr)
	{
		if (head->val < x)
		{
			small->next = head;
			small = small->next;
		}
		else
		{
			large->next = head;
			large = large->next;
		}

		head = head->next;
	}

	large->next = nullptr;
	small->next = large_head->next;

	return small_head->next;
}
