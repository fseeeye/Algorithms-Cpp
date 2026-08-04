// 字典树 / 前缀树
// OJ: https://leetcode-cn.com/problems/implement-trie-prefix-tree/
#pragma once

#include <iostream>
#include <string>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC208
{

struct TrieNode {
	TrieNode* childNodes[26];
	bool isVal;

	TrieNode()
		: isVal(false)
	{
		for (auto& childNode : childNodes)
		{
			childNode = nullptr;
		}
	}

};

class Trie {
public:
	Trie()
		: root(new TrieNode) {}

	void insert(std::string word);

	bool search(std::string word);

	bool startsWith(std::string prefix);

public:

private:
	TrieNode* root;
};

} // namespace AlgoCpp::Problem::DataStructure::LC208
