﻿// 二叉树 - 递归遍历
// OJ: https://leetcode-cn.com/problems/balanced-binary-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution110 {
public:
	bool isBalanced(TreeNode* root);
	int maxDepthInner(TreeNode* root);

	void test() {
		
		std::cout << "Solution 110 passed!\n";
	}
};
