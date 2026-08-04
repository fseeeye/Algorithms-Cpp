#include "recover_binary_search_tree.h"

// Time:  O()
// Space: O()
void Solution99::recoverTree(TreeNode* root)
{
	TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;

	searchMistakeNode(root, mistake1, mistake2, prev);

	if (mistake1 && mistake2)
	{
		int tmp = mistake1->val;
		mistake1->val = mistake2->val;
		mistake2->val = tmp;
	}
}

void Solution99::searchMistakeNode(TreeNode* root, TreeNode*& mistake1, TreeNode*& mistake2, TreeNode*& prev)
{
	if (root == nullptr)
		return;

	// inorder search
	if (root->left != nullptr)
	{
		searchMistakeNode(root->left, mistake1, mistake2, prev);
	}

	if (prev != nullptr && root->val < prev->val)
	{
		if (mistake1 == nullptr)
		{
			mistake1 = prev;
			mistake2 = root;
		}
		else
			mistake2 = root;
	}
	prev = root;

	if (root->right != nullptr)
	{
		searchMistakeNode(root->right, mistake1, mistake2, prev);
	}
}
