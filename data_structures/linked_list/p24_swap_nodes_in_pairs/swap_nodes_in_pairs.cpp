#include "swap_nodes_in_pairs.h"

// Time:  O()
// Space: O()
ListNode* Solution24::swapPairs(ListNode* head)
{
	ListNode* current = head, *tmp;

	if (current && current->next)
	{
		tmp = current->next;
		current->next = tmp->next;
		tmp->next = current;

		head = tmp;

		while (current->next && current->next->next)
		{
			tmp = current->next->next;
			current->next->next = tmp->next;
			tmp->next = current->next;
			current->next = tmp;

			current = tmp->next;
		}
	}

	return head;
}
