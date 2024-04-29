#include "delete_nodes_and_return_forest.h"

// Time:  O()
// Space: O()
std::vector<TreeNode*> Solution1110::delNodes(TreeNode* root, std::vector<int>& to_delete)
{
	std::vector<TreeNode*> forest;
	std::unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

	delNodesRecurse(root, to_delete_set, forest);

	if (root != nullptr)
		forest.push_back(root);

	return forest;
}

void Solution1110::delNodesRecurse(TreeNode*& root, std::unordered_set<int> to_delete_set, std::vector<TreeNode*>& forest)
{
	if (root == nullptr)
		return;

	delNodesRecurse(root->left, to_delete_set, forest);
	delNodesRecurse(root->right, to_delete_set, forest);

	if (to_delete_set.count(root->val) > 0)
	{
		if (root->left != nullptr)
		{
			forest.push_back(root->left);
		}

		if (root->right != nullptr)
		{
			forest.push_back(root->right);
		}

		root = nullptr;
	}
}
