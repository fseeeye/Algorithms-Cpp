#include "binary_tree_level_order_traversal.h"

#include <queue>

// Time:  O()
// Space: O()
std::vector<std::vector<int>> Solution102::levelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> rst;

	if (root == nullptr)
		return rst;

	// bfs
	std::queue<TreeNode*> q;
	q.push(root);

	int level = 0;
	while (!q.empty())
	{
		int level_size = static_cast<int>(q.size());
		rst.emplace_back();

		while (level_size--)
		{
			TreeNode* node = q.front();
			q.pop();

			rst[level].push_back(node->val);

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}

		++level;
	}

	return rst;
}
