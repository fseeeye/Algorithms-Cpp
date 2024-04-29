// XX问题
// OJ: https://leetcode-cn.com/problems/.../
#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

#include "common.h"
#include "Structures.h"

class Solution1110 {
public:
	std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete);
	void delNodesRecurse(TreeNode*& root, std::unordered_set<int> to_delete_set, std::vector<TreeNode*>& forest);

	void test() {
		
		std::cout << "Solution 1110 passed!\n";
	}
};
