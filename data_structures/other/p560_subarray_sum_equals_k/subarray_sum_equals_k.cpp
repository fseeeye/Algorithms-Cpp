#include "subarray_sum_equals_k.h"

#include <unordered_map>

// Time:  O()
// Space: O()
int Solution560::subarraySum(std::vector<int>& nums, int k)
{
	if (nums.empty()) {
		return 0;
	}

	int count = 0; // 区间和为k的个数
	int psum = 0; // 当前前缀和
	std::unordered_map<int, int> psumMap; // 前缀和统计 Map
	psumMap[0] = 1;

	for (int num : nums) {
		// 更新当前前缀和
		psum += num;
		// 统计以当前节点结尾的区间和为 k 的数量
		if (psumMap.find(psum - k) != psumMap.end()) {
			count += psumMap[psum - k];
		}
		// 更新 map
		++psumMap[psum];
	}

	return count;
}
