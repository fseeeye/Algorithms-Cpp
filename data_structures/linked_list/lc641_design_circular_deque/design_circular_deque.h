// 双向队列
// OJ: https://leetcode-cn.com/problems/design-circular-deque/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC641
{

struct DListNode {
	int val;
	DListNode* next;
	DListNode* prev;

	DListNode()
		: val(0), next(nullptr), prev(nullptr) {}
	DListNode(int x)
		: val(x), next(nullptr), prev(nullptr) {}
	DListNode(int x, DListNode* next, DListNode* prev)
		: val(x), next(next), prev(prev) {}
};

class MyCircularDeque {
public:
	unsigned int capacity;
	unsigned int size;
	DListNode* head;
	DListNode* tail;

public:
	MyCircularDeque(int k);

	bool insertFront(int value);

	bool insertLast(int value);

	bool deleteFront();

	bool deleteLast();

	int getFront();

	int getRear();

	bool isEmpty();

	bool isFull();

public:
};

} // namespace AlgoCpp::Problem::DataStructure::LC641
