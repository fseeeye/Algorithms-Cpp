#include "24points.h"

void HJ67::native_main()
{
	std::vector<float> nums;
	// handle input
	float tmp;
	for (int i = 0; i < 4; i++)
	{
		std::cin >> tmp;
		nums.push_back(tmp);
	}

	// dfs
	std::cout << (dfsRecurse(nums, 0) ? "true" : "false") << std::endl;
}

bool HJ67::dfsRecurse(std::vector<float> nums, float sum)
{
	if (sum == 24 && nums.empty())
		return true;

	for (int i = 0; i < nums.size(); i++)
	{
		std::vector<float> rest(nums);
		rest.erase(rest.begin() + i);

		if (nums.size() == 4)
		{
			if (dfsRecurse(rest, sum + nums[i]))
				return true;
		}
		else
		{
			if (dfsRecurse(rest, sum + nums[i]) ||
				dfsRecurse(rest, sum - nums[i]) ||
				dfsRecurse(rest, sum * nums[i]) ||
				dfsRecurse(rest, sum / nums[i]))
				return true;
		}
	}

	return false;
}
