#include "palindrome_linked_list.h"

// Time:  O(N)
// Space: O(1)
bool Solution234::isPalindrome(ListNode* head)
{
	if (!head || !head->next)
		return true;

	// Step1: slow-fast ptr find middle node
	ListNode* slow = head, *fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// Step2: reverse the second half
	slow->next = reverseList(slow->next);
	slow = slow->next;
	
	// Step3: compare two half list
	while (slow)
	{
		if (slow->val != head->val)
			return false;
		slow = slow->next;
		head = head->next;
	}

	return true;
}

ListNode* Solution234::reverseList(ListNode* head, ListNode* prev /*= nullptr*/)
{
	ListNode *next;

	while (head != nullptr)
	{
		next = head->next;
		head->next = prev;

		prev = head;
		head = next;
	}

	return prev;
}
