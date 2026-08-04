#include "symmetric_tree.h"

// Time:  O()
// Space: O()
bool Solution101::isSymmetric(TreeNode* root)
{
	return root == nullptr ? true : isSame(root->left, root->right);
}

bool Solution101::isSame(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;

	if (left == nullptr || right == nullptr)
		return false;

	if (left->val != right->val)
		return false;

	return isSame(left->left, right->right) && isSame(left->right, right->left);
}
