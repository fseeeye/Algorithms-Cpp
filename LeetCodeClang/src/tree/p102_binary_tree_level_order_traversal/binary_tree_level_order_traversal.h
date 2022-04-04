// 二叉树层次遍历
// OJ: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution102 {
public:
	static std::vector<std::vector<int>> levelOrder(TreeNode* root);

	static void test() {
		
		std::cout << "Solution 102 passed!\n";
	}
};
