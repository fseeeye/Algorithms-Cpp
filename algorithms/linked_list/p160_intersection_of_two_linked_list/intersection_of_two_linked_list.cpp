#include "intersection_of_two_linked_list.h"

// Time:  O()
// Space: O()
ListNode* Solution160::getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *lA = headA, *lB = headB;

	while (lA != lB)
	{
		lA = lA ? lA->next : headB;
		lB = lB ? lB->next : headA;
	}

	return lA; // or return lB;
}
