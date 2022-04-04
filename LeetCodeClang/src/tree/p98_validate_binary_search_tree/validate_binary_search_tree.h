// 二叉查找树
// OJ: https://leetcode-cn.com/problems/validate-binary-search-tree/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution098 {
public:
	static bool isValidBST(TreeNode* root);
	static void inorderBST(TreeNode* root, std::vector<int>& inorder);

	static void test() {
		
		std::cout << "Solution 098 passed!\n";
	}
};
