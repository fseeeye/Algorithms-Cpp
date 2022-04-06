#pragma once

#include "bits/stdc++.h"

// 输入为 LeetCode 风格的一字符串，下面代码将输入数据解析到整数数组中。
void trimLeftSpaces(std::string& input)
{
	input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](unsigned char c) {
		return !std::isspace(c);
		}));
}

void trimRightSpaces(std::string& input)
{
	input.erase(std::find_if(input.rbegin(), input.rend(), [](unsigned char c) {
		return !std::isspace(c);
		}).base(), input.end());
}

int main1()
{
	std::string input = "  [1, 2, 3, 4, 5, 6]  ";
	std::cout << '"' << input << '"' << std::endl;
	trimLeftSpaces(input);
	std::cout << '"' << input << '"' << std::endl;
	trimRightSpaces(input);
	std::cout << '"' << input << '"' << std::endl;
	input = input.substr(1, input.size() - 2);
	std::cout << '"' << input << '"' << std::endl;

	std::stringstream ss;
	ss.str(input);
	char delim = ',';
	std::string num_group;
	while (std::getline(ss, num_group, delim))
	{
		std::cout << std::stoi(num_group) << std::endl; // trim and to int
	}

	return 0;
}

// 整型数组输入解析：
// 在终端的一行中输入 固定数目 的整型数字，并存到数组中，中间以空格分隔
int main2()
{
	std::vector<int> nums;
	for (int i = 0; i < nums.size(); i++) {
		int val;
		std::cin >> val;
		nums.push_back(val);
	}

	return 0;
}
// 在终端的一行中输入 非固定数目 的整型数字，并存到数组中，中间以空格分隔
int main3()
{
	std::vector<int> nums;
	int num;
	while (std::cin >> num)
	{
		nums.push_back(num);

		char c = std::getchar();
		std::cout << c << std::endl;
		if (c == '\n')
			break;
	}

	return 0;
}
// 单字符分隔的数字字符串作为输入
void SpiltInt(std::string& input, std::vector<int>& output, char pattern)
{
	input.push_back(pattern);

	size_t begin = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == pattern)
		{
			output.push_back(std::stoi(input.substr(begin, i - begin)));
			begin = i + 1;
		}
	}
}
// 多字符分隔的数字字符串作为输入
void SpiltInt(std::string& input, std::vector<int>& output, std::string pattern)
{
	input.append(pattern);

	size_t begin = 0;
	while (begin < input.size())
	{
		size_t pos = input.find(pattern, begin);
		if (pos != std::string::npos)
		{
			output.push_back(std::stoi(input.substr(begin, pos - begin)));
			begin = pos + pattern.size();
		}
		else
		{
			break;
		}
	}
}
int main4()
{
	std::string input = "2,3,4,5";
	std::vector<int> output;

	SpiltInt(input, output, ',');

	for (auto o : output)
	{
		std::cout << o << std::endl;
	}

	input = "2#?3#?4#?5";
	output.clear();

	SpiltInt(input, output, "#?");

	for (auto o : output)
	{
		std::cout << o << std::endl;
	}

	return 0;
}

// 输出格式控制：要求按照数字以单空格（或者其他字符，如逗号',' 点号'.' 冒号':'等）分隔，末尾却无空格（或者其他字符）。
int main5()
{
	std::vector<int> nums = { 1, 2, 3, 4, 5 , 6 };

	std::string output;
	char spilt = ',';
	for (auto num : nums)
	{
		output.append(std::to_string(num));
		output.push_back(spilt);
	}
	output = output.substr(0, output.size() - 1);

	std::cout << output << std::endl;

	return 0;
}

//二叉树类解析
//仅输入一行字符串
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int v)
		: val(v), left(nullptr), right(nullptr) {}
	TreeNode(int v, TreeNode* l, TreeNode* r)
		: val(v), left(l), right(r) {}
};

TreeNode* createNode(std::string node_str)
{
	TreeNode* node = nullptr;
	if (node_str != "null" && node_str != " null")
	{
		node = new TreeNode(std::stoi(node_str)); // will trim
	}

	return node;
}

int main6()
{
	std::string input = "[7, 6, 5, 3, null, 4, null, 11, null, 1, 3, 2, null, null, 16]";
	input = input.substr(1, input.size() - 2);

	// 7, 6, 5, 3, null, 4, null, 11, null, 1, 3, 2, null, null, 16
	std::string node_str;
	std::stringstream ss(input);
	if (!std::getline(ss, node_str, ','))
	{
		return 0;
	}

	TreeNode* root = createNode(node_str);
	if (root == nullptr)
	{
		return 0;
	}
	std::cout << node_str << std::endl;

	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		int level_size = static_cast<int>(q.size());

		while (level_size--)
		{
			TreeNode* current_node = q.front();
			q.pop();

			// get left node
			if (!std::getline(ss, node_str, ','))
			{
				return 0;
			}

			current_node->left = createNode(node_str);
			if (current_node->left)
				q.push(current_node->left);
			std::cout << node_str << std::endl;

			// get right node
			if (!std::getline(ss, node_str, ','))
			{
				return 0;
			}

			current_node->right = createNode(node_str);
			if (current_node->right)
				q.push(current_node->right);
			std::cout << node_str << std::endl;
		}
	}

	return 0;
}
