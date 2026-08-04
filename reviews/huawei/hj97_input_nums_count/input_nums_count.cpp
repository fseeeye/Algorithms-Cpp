#include "input_nums_count.h"

// Time:  O()
// Space: O()
void HJ97::native_main()
{
	size_t nums_size;
	std::vector<int> nums;

	unsigned int negative_size = 0;
	float positive_average = 0.f;
	
	// handle input
	std::cin >> nums_size;
	nums.reserve(nums_size);

	int temp;
	for (int i = 0; i < nums_size; ++i)
	{
		std::cin >> temp;
		if (temp > 0)
		{
			nums.push_back(temp);
		}
		else if (temp < 0)
		{
			++negative_size;
		}
	}

	// calc average
	auto positive_size = nums.size();
	for (auto positive_num : nums)
	{
		positive_average += positive_num / (float)positive_size;
	}

	// output
	printf("%i %.1f", negative_size, positive_average);
}
