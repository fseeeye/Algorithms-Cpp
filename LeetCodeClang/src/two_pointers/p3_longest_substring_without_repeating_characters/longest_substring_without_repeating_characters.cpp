#include "longest_substring_without_repeating_characters.h"

#include <unordered_map>

// Time:  O()
// Space: O()
int Solution03::lengthOfLongestSubstring(std::string s)
{
	std::unordered_map<char, int> window;
	int l = 0, r = 0;
	int max_length = 0;

	while (r < s.length())
	{
		char current_char = s[r];
		r++;
		window[current_char]++;

		while (window[current_char] > 1)
		{
			char remove_char = s[l];
			l++;

			window[remove_char]--;
		}

		max_length = std::max(max_length, r - l);
	}

	return max_length;
}
