#include "word_ladder_ii.h"

// Time:  O(..)
// Space: O(..)
std::vector<std::vector<std::string>> Solution126::findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
	std::vector<std::vector<std::string>> rst;
	std::unordered_map<std::string, std::vector<std::string>> next;
	// wordlist to unordered set & check
	std::unordered_set<std::string> word_set;
	for (const auto& word : wordList)
		word_set.insert(word);
	if (!word_set.count(endWord))
		return rst;
	word_set.erase(beginWord);
	word_set.erase(endWord);
	
	// BI-Search shortest path - BFS
	bool isFound = false, isReverse = false;
	std::unordered_set<std::string> queue_positive{beginWord}, queue_negative{endWord};

	while (!queue_positive.empty())
	{
		std::unordered_set<std::string> new_queue;
		for (const auto& word : queue_positive)
		{
			// Search all posible next level words
			std::string word_searcher = word;
			for (auto& word_char : word_searcher)
			{
				char char_remember = word_char;
				for (int k = 0; k < 26; ++k)
				{
					word_char = 'a' + k;
					// check if find new next word
					if (word_set.count(word_searcher))
					{
						new_queue.insert(word_searcher);
						isReverse ? next[word_searcher].push_back(word) : next[word].push_back(word_searcher);
					}
					// check if find shortest path
					if (queue_negative.count(word_searcher))
					{
						isFound = true;
						isReverse ? next[word_searcher].push_back(word) : next[word].push_back(word_searcher);
					}
				}
				word_char = char_remember;
			}
		}
		// if found shortest path, stop
		if (isFound)
			break;
		// Remove searched word in word_set
		for (const auto& searched_word : new_queue)
			word_set.erase(searched_word);
		// Reverse search direction
		queue_positive = new_queue;
		if (queue_negative.size() < queue_positive.size())
		{
			std::swap(queue_positive, queue_negative);
			isReverse = !isReverse;
		}
	}

	// Find all shortest path - DFS(backtracking)
	if (isFound)
	{
		std::vector<std::string> tmp_path {beginWord};
		findLaddersBacktracking(beginWord, endWord, next, tmp_path, rst);
	}

	return rst;
}

void Solution126::findLaddersBacktracking(const std::string& currentBeginWord, const std::string& endWord, std::unordered_map<std::string, std::vector<std::string>>& next, std::vector<std::string>& current_path, std::vector<std::vector<std::string>>& rst)
{
	if (currentBeginWord == endWord)
	{
		rst.push_back(current_path);
		return;
	}

	for (const auto& next_word : next[currentBeginWord])
	{
		current_path.push_back(next_word);
		findLaddersBacktracking(next_word, endWord, next, current_path, rst);
		current_path.pop_back();
	}
}
