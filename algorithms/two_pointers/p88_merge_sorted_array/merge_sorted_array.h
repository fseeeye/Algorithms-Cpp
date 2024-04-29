// XX问题
// OJ: https://leetcode-cn.com/problems/merge-sorted-array/
#pragma once

#include <vector>
#include <iostream>

#include "common.h"

class Solution88 {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

	void test() {
		std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
		std::vector<int> nums2 = { 2, 5, 6 };
		merge(nums1, 3, nums2, 3);
		std::vector<int> answer = { 1, 2, 2, 3, 5, 6 };
		ASSERT(nums1 == answer);

		std::cout << "Solution 88 passed!\n";
	}
};