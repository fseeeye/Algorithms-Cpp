#include "link_list_cycle_ii.h"

// Time:  O(N)，第一次相遇 O(N)，第二次相遇 O(N) 
// Space: O(1)，只使用了两个指针
ListNode * Solution142::detectCycle(ListNode *head)
{
	ListNode* slow = head, * fast = head;

	// 判断是否存在环路。若存在，则产生第一次相遇
	// slow step = 1, fast step = 2
	do 
	{
		// 如果 fast 或 fast->next 是末尾节点，说明不存在环路
		if (fast == nullptr || fast->next == nullptr)
		{
			return nullptr;
		}
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	// 若存在环路，通过第二次相遇找到环路起始位置
	// slow step = fast step = 1
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
