#include "rotate_list.h"

// Time:  O()
// Space: O()
ListNode* Solution061::rotateRight(ListNode* head, int k)
{
	if (k == 0 || head == nullptr || head->next == nullptr)
		return head;

	// calc list length
	int len = 1;
	ListNode* tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
		++len;
	}

	// find head final pos
	int head_pos = 1 + k % len;

	// find new tail
	ListNode* new_tail = head;
	for (int i = 0; i < len - head_pos; i++)
	{
		new_tail = new_tail->next;
		if (new_tail->next == nullptr)
		{
			return head;
		}
	}

	// rotate list
	tail->next = head;
	head = new_tail->next;
	new_tail->next = nullptr;

	return head;
}
