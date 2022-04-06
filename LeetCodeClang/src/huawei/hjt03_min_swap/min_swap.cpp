#include "min_swap.h"

void HJT03::native_main()
{
	std::string nums_str;
	int k;

	while (true)
	{
		// handle input
		std::getline(std::cin, nums_str);
		if (!nums_str.empty())
		{
			std::cin >> k;

			std::vector<int> nums;
			spilt(nums_str, nums);

			// calc & output
			std::cout << minTimes(nums, k) << std::endl;
		}
	}
}

int HJT03::minTimes(std::vector<int>& nums, int k)
{
	int rst = INT_MAX;

	// count small nums, as window size
	int window_max = 0;
	for (auto num : nums)
	{
		if (num < k)
			window_max++;
	}
	if (window_max == 0 || window_max == nums.size())
	{
		return 0;
	}

	// sliding window
	int l = 0, r = 0, window_switch_cnt = 0;
	for (; r < nums.size(); ++r)
	{
		if (nums[r] >= k)
		{
			++window_switch_cnt;
		}

		if (r - l + 1 == window_max) // window is max
		{
			// update rst
			rst = std::min(rst, window_switch_cnt);

			// move l
			if (nums[l] >= k)
			{
				--window_switch_cnt;
			}
			++l;
		}
	}

	return rst == INT_MAX ? 0 : rst;
}
