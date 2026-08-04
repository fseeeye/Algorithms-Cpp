#include "count_char.h"

#include <cctype>
#include <iostream>
#include <string>

namespace AlgoCpp::Problem::Review::HJ02
{
	namespace
	{

		int ToUpper(const char character) { return std::toupper(static_cast<unsigned char>(character)); }

	} // namespace

	std::size_t CountChar(const std::string_view input, const char target)
	{
		const int normalizedTarget = ToUpper(target);
		std::size_t count = 0;

		for (const char character : input)
		{
			if (ToUpper(character) == normalizedTarget)
			{
				++count;
			}
		}

		return count;
	}

	void native_main()
	{
		std::string input;
		char target;

		std::getline(std::cin, input);
		std::cin >> target;
		std::cout << CountChar(input, target);
	}

} // namespace AlgoCpp::Problem::Review::HJ02
