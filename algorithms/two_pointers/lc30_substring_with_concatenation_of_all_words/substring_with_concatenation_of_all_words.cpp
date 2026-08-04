#include "substring_with_concatenation_of_all_words.h"

#include <unordered_map>

namespace AlgoCpp::Problem::Algorithm::LC30
{

// Time:  O()
// Space: O()
std::vector<int> Solution30::findSubstring(std::string s, std::vector<std::string>& words)
{
	if (words.size() == 0) return {};

	std::unordered_map<std::string, int> words_need;

	const std::size_t stride = words[0].size();
	const std::size_t lengthLimit = stride * words.size();

	std::vector<int> rst;

	for (auto& word : words)
	{
		words_need[word]++;
	}

	for (std::size_t i = 0; i < stride; ++i)
	{
		std::size_t left = i;
		std::size_t right = i;
		std::size_t wordsCount = 0;
		std::unordered_map<std::string, int> words_window;

		for (; right + stride <= s.size(); right += stride)
		{
			std::string current_word = s.substr(right, stride);

			if (words_need.count(current_word)) // current word is needed
			{
				words_window[current_word]++;
				if (words_window[current_word] == words_need[current_word])
				{
					wordsCount++;
				}
			}

			while (right + stride - left > lengthLimit)
			{
				std::string removed_word = s.substr(left, stride);
				left += stride;

				if (words_need.count(removed_word)) // current word is needed
				{
					if (words_window[removed_word] == words_need[removed_word])
					{
						wordsCount--;
					}
					words_window[removed_word]--;
				}
			}

			if (right + stride - left == lengthLimit && wordsCount == words_need.size())
			{
				rst.push_back(static_cast<int>(left));
			}
		}
	}

	return rst;
}

} // namespace AlgoCpp::Problem::Algorithm::LC30
