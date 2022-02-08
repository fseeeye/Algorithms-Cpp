// 深度优先搜索问题（回溯法）
// OJ: https://leetcode-cn.com/problems/permutations/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"

class Solution46 {
public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums);
	void permuteBacktracking(std::vector<int>& nums, int level, std::vector<std::vector<int>>& rst);

	void test() {
		std::vector<int> nums1 = { 1, 2, 3 };
		std::vector<std::vector<int>> rst1 = permute(nums1);
		std::vector<std::vector<int>> target = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2} };
		ASSERT(rst1 == target);
		
		std::cout << "Solution 47 passed!\n";
	}
};