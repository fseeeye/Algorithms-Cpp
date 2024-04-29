// 双向队列
// OJ: https://leetcode-cn.com/problems/design-circular-deque/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

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
	static void test() {
		MyCircularDeque* obj = new MyCircularDeque(4);
		bool param_1 = obj->insertFront(9);
		bool p2 = obj->deleteLast();
		int p3 = obj->getRear();
		int p4 = obj->getFront();
		int p5 = obj->getFront();
		bool p6 = obj->deleteFront();
		bool p7 = obj->insertFront(6);
		bool p8 = obj->insertLast(5);
		bool p9 = obj->insertFront(9);
		int p10 = obj->getFront();
		bool p11 = obj->insertFront(6);
	
		std::cout << "Solution 641 passed!\n";
	}
};
