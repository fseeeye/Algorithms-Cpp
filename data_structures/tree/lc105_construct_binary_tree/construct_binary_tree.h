// 二叉树 - 前中序遍历
// OJ: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC105
{

class Solution105 {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
	TreeNode* buildTreeRecurse(std::vector<int>& preorder, std::unordered_map<int, int>& inorder_map, int preorder_index, int inorder_begin, int inorder_end);
	TreeNode* buildTreeRecurse2(std::vector<int>& preorder, std::unordered_map<int, int>& inorder_map, int preorder_index, int inorder_begin, int inorder_end);

};

} // namespace AlgoCpp::Problem::DataStructure::LC105
