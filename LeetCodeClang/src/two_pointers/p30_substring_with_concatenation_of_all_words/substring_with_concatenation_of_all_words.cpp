#include "substring_with_concatenation_of_all_words.h"

#include <unordered_map>

// Time:  O()
// Space: O()
std::vector<int> Solution30::findSubstring(std::string s, std::vector<std::string>& words)
{
	if (words.size() == 0) return {};

	std::unordered_map<std::string, int> words_need;

	int stride = words[0].size(), len_limit = stride * words.size();

	std::vector<int> rst;

	for (auto& word : words)
	{
		words_need[word]++;
	}

	for (int i = 0; i < stride; ++i)
	{
		int l = i, r = i;
		int words_count = 0;
		std::unordered_map<std::string, int> words_window;

		for (; r + stride <= s.size(); r += stride)
		{
			std::string current_word = s.substr(r, stride);

			if (words_need.count(current_word)) // current word is needed
			{
				words_window[current_word]++;
				if (words_window[current_word] == words_need[current_word])
				{
					words_count++;
				}
			}

			while (r + stride - l > len_limit)
			{
				std::string removed_word = s.substr(l, stride);
				l += stride;

				if (words_need.count(removed_word)) // current word is needed
				{
					if (words_window[removed_word] == words_need[removed_word])
					{
						words_count--;
					}
					words_window[removed_word]--;
				}
			}

			if (r + stride - l == len_limit && words_count == words_need.size())
			{
				rst.push_back(l);
			}
		}
	}

	return rst;
}
