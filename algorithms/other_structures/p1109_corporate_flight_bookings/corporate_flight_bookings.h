// 差分数组
// OJ: https://leetcode.cn/problems/corporate-flight-bookings/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution1109 {
public:
	static std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n);

	static void test() {
		
		std::cout << "Solution 1109 passed!\n";
	}
};
