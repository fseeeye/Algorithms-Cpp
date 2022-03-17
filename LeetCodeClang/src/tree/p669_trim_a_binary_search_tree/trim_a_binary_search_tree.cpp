#include "trim_a_binary_search_tree.h"

// Time:  O()
// Space: O()
TreeNode* Solution669::trimBST(TreeNode* root, int low, int high)
{
	if (root == nullptr)
		return root;

	if (root->val > high)
		return trimBST(root->left, low, high);
	if (root->val < low)
		return trimBST(root->right, low, high);

	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);

	return root;
}
