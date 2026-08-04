#include "populating_next_right_pointers_in_each_node_ii.h"

#include <queue>

// Time:  O()
// Space: O()
Node* Solution117::connect(Node* root)
{
	if (root == nullptr) return root;

	std::queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int nodes_cnt = static_cast<int>(q.size());

		Node* prev_node = nullptr, * current_node;
		for (int i = 0; i < nodes_cnt; ++i)
		{
			current_node = q.front();
			q.pop();
			
			if (i != 0)
				prev_node->next = current_node;
			prev_node = current_node;
			
			if (current_node->left)
				q.push(current_node->left);
			if (current_node->right)
				q.push(current_node->right);
		}
	}

	return root;
}
