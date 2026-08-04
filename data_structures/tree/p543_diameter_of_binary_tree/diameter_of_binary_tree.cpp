#include "diameter_of_binary_tree.h"

// Time:  O()
// Space: O()
int Solution543::diameterOfBinaryTree(TreeNode* root)
{
	int max_diameter = 0;
	maxDepthInner(root, max_diameter);

	return max_diameter;
}

int Solution543::maxDepthInner(TreeNode* root, int& max_diameter)
{
	if (root == nullptr)
		return 0;

	int left_depth = maxDepthInner(root->left, max_diameter);
	int right_depth = maxDepthInner(root->right, max_diameter);
	max_diameter = std::max(max_diameter, left_depth + right_depth);

	return std::max(left_depth, right_depth) + 1;
}
