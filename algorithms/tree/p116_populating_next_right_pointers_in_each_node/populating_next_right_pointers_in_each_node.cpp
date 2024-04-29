#include "populating_next_right_pointers_in_each_node.h"

// Time:  O()
// Space: O()
Node* Solution116::connect(Node* root)
{
	if (root != nullptr)
		traverse(root->left, root->right);

	return root;
}

void Solution116::traverse(Node* left, Node* right)
{
	if (left == nullptr || right == nullptr)
		return;

	left->next = right;

	traverse(left->left, left->right);
	traverse(left->right, right->left);
	traverse(right->left, right->right);
}
