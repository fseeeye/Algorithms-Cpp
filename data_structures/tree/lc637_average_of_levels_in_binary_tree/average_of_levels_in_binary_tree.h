// 二叉树 - 层次遍历
// OJ: https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC637
{

class Solution637 {
public:
	std::vector<double> averageOfLevels(TreeNode* root);

};

} // namespace AlgoCpp::Problem::DataStructure::LC637
