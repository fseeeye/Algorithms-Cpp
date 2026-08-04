#include "design_circular_deque.h"

MyCircularDeque::MyCircularDeque(int k)
	: capacity(k), size(0), head(nullptr), tail(nullptr)
{
}

bool MyCircularDeque::insertFront(int value)
{
	if (size == capacity)
	{
		return false;
	}

	if (size == 0)
	{
		tail = head = new DListNode(value);
	}
	else
	{
		DListNode* new_node = new DListNode(value, head, nullptr);
		head->prev = new_node;
		head = new_node;
	}

	size++;
	return true;
}

bool MyCircularDeque::insertLast(int value)
{
	if (size == capacity)
	{
		return false;
	}

	if (size == 0)
	{
		tail = head = new DListNode(value);
	}
	else
	{
		DListNode* new_node = new DListNode(value, nullptr, tail);
		tail->next = new_node;
		tail = new_node;
	}

	size++;
	return true;
}

bool MyCircularDeque::deleteFront()
{
	if (head == nullptr)
	{
		return false;
	}

	DListNode* removed_head = head;
	head = head->next;

	// remove node
	delete removed_head;
	if (head != nullptr)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}

	size--;
	return true;
}

bool MyCircularDeque::deleteLast()
{
	if (tail == nullptr)
	{
		return false;
	}
	
	DListNode* removed_tail = tail;
	tail = tail->prev;

	// remove node
	delete removed_tail;
	if (tail != nullptr)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}

	size--;
	return true;
}

int MyCircularDeque::getFront()
{
	return head == nullptr ? -1 : head->val;
}

int MyCircularDeque::getRear()
{
	return tail == nullptr ? -1 : tail->val;
}

bool MyCircularDeque::isEmpty()
{
	return size == 0;
}

bool MyCircularDeque::isFull()
{
	return size == capacity;
}
