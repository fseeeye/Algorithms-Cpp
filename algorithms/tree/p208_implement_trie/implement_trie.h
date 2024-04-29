// 字典树 / 前缀树
// OJ: https://leetcode-cn.com/problems/implement-trie-prefix-tree/
#pragma once

#include <iostream>
#include <string>

#include "common.h"
#include "Structures.h"

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
	static void test() {
		
		std::cout << "Solution 208 passed!\n";
	}

private:
	TrieNode* root;
};
