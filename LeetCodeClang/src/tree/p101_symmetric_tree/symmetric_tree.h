// 二叉树-递归遍历
// OJ: https://leetcode-cn.com/problems/symmetric-tree/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution101 {
public:
	bool isSymmetric(TreeNode* root);
	bool isSame(TreeNode* left, TreeNode* right);

	void test() {
		
		std::cout << "Solution 101 passed!\n";
	}
};
