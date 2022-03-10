#include "different_ways_to_add_parentheses.h"

#include <string>
#include <sstream>

// Time:  O()
// Space: O()
std::vector<int> Solution241::diffWaysToCompute(std::string expression)
{
	std::vector<int> diff_ways;

	for (int i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];
		
		if (c == '+' || c == '-' || c == '*')
		{
			std::vector<int> left_ways = diffWaysToCompute(expression.substr(0, i));
			std::vector<int> right_ways = diffWaysToCompute(expression.substr(i + 1));
			for (auto& l_way : left_ways)
			{
				for (auto& r_way : right_ways)
				{
					switch (c)
					{
						case '+': diff_ways.push_back(l_way + r_way); break;
						case '-': diff_ways.push_back(l_way - r_way); break;
						case '*': diff_ways.push_back(l_way * r_way); break;
					}
				}
			}
		}
	}

	if (diff_ways.empty())
		diff_ways.push_back(std::stoi(expression));

	return diff_ways;
}

// Time:  O()
// Space: O()
std::vector<int> Solution241::diffWaysToCompute2(std::string expression)
{
	std::vector<int> nums;
	std::vector<char> ops;
	int num;
	char op;
	std::istringstream ss(expression);
	while (ss >> num && ss >> op)
	{
		nums.push_back(num);
		ops.push_back(op);
	}
	nums.push_back(num);

	int nums_size = static_cast<int>(nums.size());
	std::vector<std::vector<std::vector<int>>> dp(nums_size, std::vector<std::vector<int>>(nums_size, std::vector<int>()));

	for (int j = 0; j < nums_size; ++j)
	{
		for (int i = j; i >= 0; --i)
		{
			if (i == j)
			{
				dp[i][j].push_back(nums[i]);
			}
			else
			{
				for (int k = i; k < j; ++k)
				{
					for (auto& l_way : dp[i][k])
					{
						for (auto& r_way : dp[k + 1][j])
						{
							switch (ops[k])
							{
								case '+': dp[i][j].push_back(l_way + r_way); break;
								case '-': dp[i][j].push_back(l_way - r_way); break;
								case '*': dp[i][j].push_back(l_way * r_way); break;
							}
						}
					}
				}
			}
		}
	}

	return dp[0][nums_size - 1];
}
