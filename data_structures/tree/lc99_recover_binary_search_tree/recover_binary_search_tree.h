// 二叉搜索树
// OJ: https://leetcode-cn.com/problems/recover-binary-search-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC99
{

class Solution99 {
public:
	void recoverTree(TreeNode* root);
	void searchMistakeNode(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& prev);

};

} // namespace AlgoCpp::Problem::DataStructure::LC99
