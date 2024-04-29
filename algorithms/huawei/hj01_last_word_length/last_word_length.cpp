#include "last_word_length.h"

#include <bits/stdc++.h>

// Time:  O()
// Space: O()
void HJ01::native_main()
{
	std::string input;

	std::getline(std::cin, input);

	auto input_size = input.size();
	auto const blank_pos = input.rfind(' ');
	if (blank_pos + 1 < input_size)
	{
		std::string last_word = input.substr(blank_pos + 1, input_size - blank_pos - 1);

		std::cout << last_word.length();
	}
	else
	{
		std::cout << input_size << std::endl;
	}
}
