#include "ip_to_int.h"


void HJT02::native_main()
{
	std::string input;
	std::cin >> input;

	int rst = handle(input);

	rst == 0 ? printf("invalid IP") : printf("%i", rst);
}

unsigned int HJT02::handle(std::string input)
{
	std::vector<int> output;
	spiltString(input, output);

	// check
	if (output.size() != 4)
		return 0;
	for (int i = 0; i < 4; ++i)
	{
		if (i == 0)
		{
			if (output[i] < 1 || output[i] > 128)
				return 0;
		}
		else
		{
			if (output[i] < 0 || output[i] > 255)
				return 0;
		}
	}

	// calc int
	int rst = (output[0] << 24) | (output[1] << 16) | (output[2] << 8) | output[3];

	return rst;
}
