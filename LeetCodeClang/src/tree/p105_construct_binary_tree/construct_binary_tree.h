// 二叉树 - 前中序遍历
// OJ: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Tester.h"
#include "Structures.h"

class Solution105 {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
	TreeNode* buildTreeRecurse(std::vector<int>& preorder, std::unordered_map<int, int>& inorder_map, int preorder_index, int inorder_begin, int inorder_end);
	TreeNode* buildTreeRecurse2(std::vector<int>& preorder, std::unordered_map<int, int>& inorder_map, int preorder_index, int inorder_begin, int inorder_end);

	void test() {
		
		std::cout << "Solution 105 passed!\n";
	}
};
