#include "construct_binary_tree.h"

// Time:  O()
// Space: O()
TreeNode* Solution105::buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	if (preorder.empty() || inorder.empty())
		return nullptr;

	std::unordered_map<int, int> inorder_map;
	for (int i = 0; i < inorder.size(); ++i)
		inorder_map[inorder[i]] = i;
	
	return buildTreeRecurse(preorder, inorder_map, 0, 0, static_cast<int>(inorder.size()) - 1);
}

TreeNode* Solution105::buildTreeRecurse(std::vector<int>& preorder, std::unordered_map<int, int>& inorder_map, int preorder_index, int inorder_begin, int inorder_end)
{
	if (inorder_begin > inorder_end)
		return nullptr;

	int root_val = preorder[preorder_index];
	int root_inorder_index = inorder_map[root_val];
	int root_left_len = root_inorder_index - inorder_begin;

	TreeNode* root = new TreeNode(root_val);

	root->left = buildTreeRecurse(preorder, inorder_map, preorder_index + 1, inorder_begin, root_inorder_index - 1);
	root->right = buildTreeRecurse(preorder, inorder_map, preorder_index + 1 + root_left_len, root_inorder_index + 1, inorder_end);

	return root;
}
