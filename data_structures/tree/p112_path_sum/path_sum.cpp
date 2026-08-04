#include "path_sum.h"

// Time:  O()
// Space: O()
bool Solution112::hasPathSum(TreeNode* root, int targetSum)
{
	return recurse(root, targetSum, 0);
}

bool Solution112::recurse(TreeNode* root, int targetSum, int sum)
{
	if (root == nullptr) return false;

	sum += root->val;

	// leaf node
	if (root->left == nullptr && root->right == nullptr)
	{
		return sum == targetSum;
	}

	// inter node
	return recurse(root->left, targetSum, sum) || recurse(root->right, targetSum, sum);
}
