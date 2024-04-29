// Kth Element 快速排序问题
// OJ: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

class Solution215 {
public:
	int findKthLargest(std::vector<int>& nums, int k);
	int quickSelection(std::vector<int>& nums, int l, int r);

	void test() {
		std::vector<int> nums1 = { 3, 2, 1, 5, 6, 4 };
		int rst1 = findKthLargest(nums1, 2);
		ASSERT(rst1 == 5);

		std::vector<int> nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
		int rst2 = findKthLargest(nums2, 4);
		ASSERT(rst2 == 4);
		
		std::cout << "Solution 215 passed!\n";
	}
};