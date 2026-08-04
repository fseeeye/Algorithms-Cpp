// 二叉树层次遍历
// OJ: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC102
{

class Solution102 {
public:
	static std::vector<std::vector<int>> levelOrder(TreeNode* root);

};

} // namespace AlgoCpp::Problem::DataStructure::LC102
