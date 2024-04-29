#include "maximum_depth_of_binary_tree.h"

// Time:  O(N)
// Space: O(1)
int Solution104::maxDepth(TreeNode* root)
{
	return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
