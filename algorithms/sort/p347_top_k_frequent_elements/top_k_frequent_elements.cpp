#include "top_k_frequent_elements.h"

#include <unordered_map>

// Time:  O()
// Space: O()
std::vector<int> Solution347::topKFrequent(std::vector<int>& nums, int k)
{
	// Step1: 记录各数字的出现频率
	std::unordered_map<int, int> frequence_map;
	int max_count = 0;
	for (const int& num : nums)
	{
		max_count = std::max(max_count, ++frequence_map[num]);
	}

	// Step2：对各数字的出现频率进行桶排序
	std::vector<std::vector<int>> num_buckets(max_count + 1);
	for (const auto& [k, v] : frequence_map)
	{
		num_buckets[v].push_back(k);
	}

	// Step3：从桶中取出前 k 个数字
	std::vector<int> rst;
	for (int i = max_count; i > 0 && rst.size() < k; --i)
	{
		for (const int& num : num_buckets[i])
		{
			if (rst.size() < k)
			{
				rst.push_back(num);
			}
			else
			{
				break;
			}
		}
	}

	return rst;
}
