#include "validate_binary_search_tree.h"

// Time:  O()
// Space: O()
bool Solution098::isValidBST(TreeNode* root)
{
	std::vector<int> inorder;
	inorderBST(root, inorder);

	if (inorder.size() <= 1)
	{
		return true;
	}

	for (int i = 1; i < inorder.size(); i++)
	{
		if (inorder[i] <= inorder[i-1])
		{
			return false;
		}
	}

	return true;
}

void Solution098::inorderBST(TreeNode* root, std::vector<int>& inorder)
{
	if (root == nullptr) 
		return;

	inorderBST(root->left, inorder);

	inorder.push_back(root->val);

	inorderBST(root->right, inorder);
}
