// 前缀和
// OJ: https://leetcode.com/problems/range-sum-query-immutable/
#pragma once

#include <iostream>
#include <vector>
#include <numeric>

#include "common.h"
#include "Structures.h"

class Solution303 {
public:
	Solution303(std::vector<int>& nums)
		: psum(nums.size() + 1, 0)
	{
		// 生成 psum 数组
		std::partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
	}

	int sumRange(int left, int right) {
		// 返回区间和
		return psum[right + 1] - psum[left];
	}

private:
	std::vector<int> psum;

public:
	static void test() {

		std::cout << "Solution 303 passed!\n";
	}
};
