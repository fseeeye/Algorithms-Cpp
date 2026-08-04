// 二叉搜索树
// OJ: https://leetcode-cn.com/problems/trim-a-binary-search-tree/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC669
{

class Solution669 {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high);

};

} // namespace AlgoCpp::Problem::DataStructure::LC669
