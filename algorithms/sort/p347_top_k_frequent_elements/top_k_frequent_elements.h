// 桶排序问题
// OJ: https://leetcode-cn.com/problems/top-k-frequent-elements/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution347 {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k);

	void test() {
		std::vector<int> nums1 = { 1, 1, 1, 2, 2, 3 };
		std::vector<int> rst1 = topKFrequent(nums1, 2);
		std::vector<int> target_rst1 = { 1, 2 };
		ASSERT(rst1 == target_rst1);

		std::vector<int> nums2 = { 1 };
		std::vector<int> rst2 = topKFrequent(nums2, 1);
		std::vector<int> target_rst2 = { 1 };
		ASSERT(rst2 == target_rst2);
		
		std::cout << "Solution 347 passed!\n";
	}
};