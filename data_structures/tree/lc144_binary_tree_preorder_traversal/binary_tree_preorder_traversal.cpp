#include "binary_tree_preorder_traversal.h"

#include <stack>

namespace AlgoCpp::Problem::DataStructure::LC144
{

// Time:  O()
// Space: O()
std::vector<int> Solution144::preorderTraversal(TreeNode* root) // iterate method
{
	std::vector<int> rst;
	if (root == nullptr)
		return rst;

	std::stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode* node = s.top();
		s.pop();

		rst.push_back(node->val);

		if (node->right != nullptr)
			s.push(node->right);
		if (node->left != nullptr)
			s.push(node->left);
	}

	return rst;
}

} // namespace AlgoCpp::Problem::DataStructure::LC144
