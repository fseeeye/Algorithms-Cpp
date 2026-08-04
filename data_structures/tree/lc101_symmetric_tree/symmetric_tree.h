// 二叉树-递归遍历
// OJ: https://leetcode-cn.com/problems/symmetric-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC101
{

class Solution101 {
public:
	bool isSymmetric(TreeNode* root);
	bool isSame(TreeNode* left, TreeNode* right);

};

} // namespace AlgoCpp::Problem::DataStructure::LC101
