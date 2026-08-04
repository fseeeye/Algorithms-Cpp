#include "reverse_linked_list.h"

// Time:  O()
// Space: O()
ListNode* Solution206::reverseList(ListNode* head, ListNode* prev/*=nullptr*/)
{
	if (head == nullptr)
		return prev;

	ListNode* next = head->next;
	head->next = prev;

	return reverseList(next, head);
}

// Time:  O()
// Space: O()
ListNode* Solution206::reverseListNonRecursive(ListNode* head)
{
	ListNode *prev = nullptr, *next;
	while (head != nullptr)
	{
		next = head->next;
		head->next = prev;

		prev = head;
		head = next;
	}

	return prev;
}
