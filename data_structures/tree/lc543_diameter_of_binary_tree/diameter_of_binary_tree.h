// 二叉树 - 递归遍历
// OJ: https://leetcode-cn.com/problems/diameter-of-binary-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC543
{

class Solution543 {
public:
	int diameterOfBinaryTree(TreeNode* root);
	int maxDepthInner(TreeNode* root, int& max_diameter);

};

} // namespace AlgoCpp::Problem::DataStructure::LC543
