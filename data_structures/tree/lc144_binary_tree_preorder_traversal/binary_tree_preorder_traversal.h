// 二叉树 - 前序遍历
// OJ: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC144
{

class Solution144 {
public:
	std::vector<int> preorderTraversal(TreeNode* root);

};

} // namespace AlgoCpp::Problem::DataStructure::LC144
