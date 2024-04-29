// 前缀和
// OJ: https://leetcode.com/problems/subarray-sum-equals-k/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution560 {
public:
	static int subarraySum(std::vector<int>& nums, int k);

	static void test() {
		
		std::cout << "Solution 560 passed!\n";
	}
};
