// 二叉树 - 层次遍历
// OJ: https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution637 {
public:
	std::vector<double> averageOfLevels(TreeNode* root);

	void test() {
		
		std::cout << "Solution 637 passed!\n";
	}
};
