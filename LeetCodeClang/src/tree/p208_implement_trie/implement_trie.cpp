#include "implement_trie.h"

void Trie::insert(std::string word)
{
	TrieNode* current_node = root;

	for (auto c : word)
	{
		if (current_node->childNodes[c - 'a'] == nullptr)
			current_node->childNodes[c - 'a'] = new TrieNode();
		current_node = current_node->childNodes[c - 'a'];
	}

	current_node->isVal = true;
}

bool Trie::search(std::string word)
{
	TrieNode* current_node = root;

	for (auto c : word)
	{
		if (current_node == nullptr)
			break;
		current_node = current_node->childNodes[c - 'a'];
	}

	return current_node == nullptr ? false : current_node->isVal;
}

bool Trie::startsWith(std::string prefix)
{
	TrieNode* current_node = root;

	for (auto c : prefix)
	{
		if (current_node == nullptr)
			break;
		current_node = current_node->childNodes[c - 'a'];
	}

	return current_node != nullptr;
}
