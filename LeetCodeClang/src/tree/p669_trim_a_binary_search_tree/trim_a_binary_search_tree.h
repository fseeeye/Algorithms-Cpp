// 二叉搜索树
// OJ: https://leetcode-cn.com/problems/trim-a-binary-search-tree/
#pragma once

#include <iostream>

#include "Tester.h"
#include "Structures.h"

class Solution669 {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high);

	void test() {
		
		std::cout << "Solution 669 passed!\n";
	}
};
