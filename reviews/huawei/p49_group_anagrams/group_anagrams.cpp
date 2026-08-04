#include "group_anagrams.h"

#include <unordered_map>
#include <algorithm>

// Time:  O()
// Space: O()
std::vector<std::vector<std::string>> Solution49::groupAnagrams(std::vector<std::string>& strs)
{
	std::unordered_map<std::string, std::vector<std::string>> rst_map;

	for (auto& str : strs)
	{
		std::string sorted_str = str;
		std::sort(sorted_str.begin(), sorted_str.end());

		rst_map[sorted_str].push_back(str);
	}

	std::vector<std::vector<std::string>> rst;
	rst.reserve(rst_map.size());
	for (auto& kv : rst_map)
	{
		rst.push_back(kv.second);
	}

	return rst;
}
