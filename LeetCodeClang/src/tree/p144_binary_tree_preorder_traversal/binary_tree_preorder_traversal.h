// 二叉树 - 前序遍历
// OJ: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution144 {
public:
	std::vector<int> preorderTraversal(TreeNode* root);

	void test() {
		
		std::cout << "Solution 144 passed!\n";
	}
};
