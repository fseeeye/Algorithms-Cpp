// 二叉树DFS
// OJ: https://leetcode-cn.com/problems/path-sum/
#pragma once

#include <iostream>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC112
{

class Solution112 {
public:
	static bool hasPathSum(TreeNode* root, int targetSum);
	static bool recurse(TreeNode* root, int targetSum, int sum);

};

} // namespace AlgoCpp::Problem::DataStructure::LC112
