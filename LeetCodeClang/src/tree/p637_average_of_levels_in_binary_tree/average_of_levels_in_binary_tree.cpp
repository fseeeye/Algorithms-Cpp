#include "average_of_levels_in_binary_tree.h"

#include <queue>

// Time:  O()
// Space: O()
std::vector<double> Solution637::averageOfLevels(TreeNode* root)
{
	std::vector<double> average_of_levels;
	if (root == nullptr)
		return average_of_levels;

	std::queue<TreeNode*> level_nodes;
	level_nodes.push(root);

	while (!level_nodes.empty())
	{
		int nodes_count = level_nodes.size();
		double sum = 0;

		for (int i = 0; i < nodes_count; ++i)
		{
			TreeNode* current_node = level_nodes.front();
			level_nodes.pop();

			sum += current_node->val;

			if (current_node->left != nullptr)
			{
				level_nodes.push(current_node->left);
			}

			if (current_node->right != nullptr)
			{
				level_nodes.push(current_node->right);
			}
		}

		average_of_levels.push_back(sum / nodes_count);
	}

	return average_of_levels;
}
