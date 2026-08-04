// 二叉树 - 递归遍历
// OJ: https://leetcode-cn.com/problems/balanced-binary-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC110
{

class Solution110 {
public:
	bool isBalanced(TreeNode* root);
	int maxDepthInner(TreeNode* root);

};

} // namespace AlgoCpp::Problem::DataStructure::LC110
