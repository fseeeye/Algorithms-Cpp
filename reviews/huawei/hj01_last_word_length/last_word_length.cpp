#include "last_word_length.h"

#include <iostream>
#include <string>

namespace AlgoCpp::Problem::Review::HJ01
{

std::size_t LastWordLength(const std::string_view input)
{
	const auto lastCharacter = input.find_last_not_of(' ');
	if (lastCharacter == std::string_view::npos) return 0;
	const auto lastSpace = input.rfind(' ', lastCharacter);
	return lastSpace == std::string_view::npos ? lastCharacter + 1 : lastCharacter - lastSpace;
}

void native_main()
{
	std::string input;
	std::getline(std::cin, input);
	std::cout << LastWordLength(input);
}

} // namespace AlgoCpp::Problem::Review::HJ01
