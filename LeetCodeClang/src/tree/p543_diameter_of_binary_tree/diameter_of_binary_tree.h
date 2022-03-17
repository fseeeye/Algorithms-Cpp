// 二叉树 - 递归遍历
// OJ: https://leetcode-cn.com/problems/diameter-of-binary-tree/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution543 {
public:
	int diameterOfBinaryTree(TreeNode* root);
	int maxDepthInner(TreeNode* root, int& max_diameter);

	void test() {
		
		std::cout << "Solution 543 passed!\n";
	}
};
