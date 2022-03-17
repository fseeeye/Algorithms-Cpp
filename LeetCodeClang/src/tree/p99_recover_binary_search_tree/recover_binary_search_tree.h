// 二叉搜索树
// OJ: https://leetcode-cn.com/problems/recover-binary-search-tree/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution99 {
public:
	void recoverTree(TreeNode* root);
	void searchMistakeNode(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& prev);

	void test() {
		
		std::cout << "Solution 99 passed!\n";
	}
};
