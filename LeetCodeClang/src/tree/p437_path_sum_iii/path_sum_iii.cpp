#include "path_sum_iii.h"

// Time:  O()
// Space: O()
int Solution437::pathSum(TreeNode* root, int targetSum)
{
	return root == nullptr ? 0 : pathSumRootAsStart(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}

int Solution437::pathSumRootAsStart(TreeNode* root, int targetSum)
{
	if (root == nullptr)
		return 0;
	
	int count = root->val == targetSum ? 1 : 0;
	count += pathSumRootAsStart(root->left, targetSum - root->val);
	count += pathSumRootAsStart(root->right, targetSum - root->val);

	return count;
}
