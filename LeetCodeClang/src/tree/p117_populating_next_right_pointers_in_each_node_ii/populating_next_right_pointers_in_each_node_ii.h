// 二叉树
// OJ: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution117 {
public:
	static Node* connect(Node* root);

	static void test() {
		
		std::cout << "Solution 117 passed!\n";
	}
};

