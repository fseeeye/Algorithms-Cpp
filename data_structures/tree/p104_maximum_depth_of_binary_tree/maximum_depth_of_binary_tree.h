// 二叉树-递归遍历
// OJ: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

class Solution104 {
public:
	int maxDepth(TreeNode* root);

	void test() {
		
		std::cout << "Solution 104 passed!\n";
	}
};
