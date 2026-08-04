// 二叉查找树
// OJ: https://leetcode-cn.com/problems/validate-binary-search-tree/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC98
{

class Solution098 {
public:
	static bool isValidBST(TreeNode* root);
	static void inorderBST(TreeNode* root, std::vector<int>& inorder);

};

} // namespace AlgoCpp::Problem::DataStructure::LC98
