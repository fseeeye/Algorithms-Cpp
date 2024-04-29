// 二叉树 - 递归遍历
// OJ: https://leetcode-cn.com/problems/path-sum-iii/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution437 {
public:
	int pathSum(TreeNode* root, int targetSum);
	int pathSumRootAsStart(TreeNode* root, int targetSum);

	void test() {
		
		std::cout << "Solution 437 passed!\n";
	}
};
