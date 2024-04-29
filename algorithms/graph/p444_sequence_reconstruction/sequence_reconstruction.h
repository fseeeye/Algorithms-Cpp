// 拓扑排序
// OJ: https://leetcode.cn/problems/sequence-reconstruction/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution444 {
public:
	static bool sequenceReconstruction(std::vector<int>& nums, std::vector<std::vector<int>>& sequences);

	static void test() {
		
		std::cout << "Solution 444 passed!\n";
	}
};
