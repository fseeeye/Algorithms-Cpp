#include "balanced_binary_tree.h"

// Time:  O()
// Space: O()
bool Solution110::isBalanced(TreeNode* root)
{
	return maxDepthInner(root) != -1;
}

int Solution110::maxDepthInner(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int left_depth = maxDepthInner(root->left);
	int right_depth = maxDepthInner(root->right);

	if (left_depth == -1 || right_depth == -1 || std::abs(right_depth - left_depth) > 1)
		return -1;

	return std::max(left_depth, right_depth) + 1;
}
