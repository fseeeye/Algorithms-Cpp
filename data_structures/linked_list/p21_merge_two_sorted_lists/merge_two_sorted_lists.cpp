#include "merge_two_sorted_lists.h"

// Time:  O()
// Space: O()
ListNode* Solution21::mergeTwoLists(ListNode* list1, ListNode* list2)
{
	if (!list1) return list2;
	if (!list2) return list1;

	if (list1->val > list2->val)
	{
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
	else
	{
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
}

// Time:  O()
// Space: O()
ListNode* Solution21::mergeTwoListsNonRecursive(ListNode* list1, ListNode* list2)
{
	ListNode* dummy_header = new ListNode(0);
	ListNode* current_node = dummy_header;

	while (list1 && list2)
	{
		if (list1->val > list2->val)
		{
			current_node->next = list2;
			list2 = list2->next;
		}
		else
		{
			current_node->next = list1;
			list1 = list1->next;
		}

		current_node = current_node->next;
	}
	current_node->next = list1 ? list1 : list2;

	return dummy_header->next;
}
