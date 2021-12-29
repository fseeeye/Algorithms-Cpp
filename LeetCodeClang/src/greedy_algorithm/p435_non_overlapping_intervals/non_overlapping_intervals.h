// 区间问题
// OJ: https://leetcode-cn.com/problems/non-overlapping-intervals/
#pragma once

#include <vector>
#include <iostream>

#include "Tester.h"

class Solution435 {
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);

	void test() {
		std::vector<std::vector<int>> intervals0 = {};
		ASSERT(eraseOverlapIntervals(intervals0) == 0);

		std::vector<std::vector<int>> intervals1 = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
		ASSERT(eraseOverlapIntervals(intervals1) == 1);

		std::vector<std::vector<int>> intervals2 = { {1, 2}, {1, 2}, {1, 2}, {1, 2} };
		ASSERT(eraseOverlapIntervals(intervals2) == 3);

		std::vector<std::vector<int>> intervals3 = { {1, 2}, {2, 3} };
		ASSERT(eraseOverlapIntervals(intervals3) == 0);

		std::cout << "Solution 435 passed!\n";
	}
};