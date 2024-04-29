// 二叉树DFS
// OJ: https://leetcode-cn.com/problems/path-sum/
#pragma once

#include <iostream>

#include "common.h"
#include "Structures.h"

class Solution112 {
public:
	static bool hasPathSum(TreeNode* root, int targetSum);
	static bool recurse(TreeNode* root, int targetSum, int sum);

	static void test() {
		
		std::cout << "Solution 112 passed!\n";
	}
};
