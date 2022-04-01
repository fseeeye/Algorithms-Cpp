#include "count_char.h"


void HJ02::native_main()
{
	std::string input;
	char target;

	std::getline(std::cin, input);

	std::cin >> target;
	target = toupper(target);

	unsigned int rst = 0;
	for (auto input_char : input)
	{
		if (toupper(input_char) == target)
		{
			++rst;
		}
	}

	std::cout << rst;
}
