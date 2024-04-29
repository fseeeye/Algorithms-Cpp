// 哈希表
// OJ: https://leetcode-cn.com/problems/brick-wall/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "Structures.h"

class Solution554 {
public:
	static int leastBricks(std::vector<std::vector<int>>& wall);

	static void test() {
		std::vector<std::vector<int>> wall = {
			{ 1, 2, 2, 1},
			{ 3, 1, 3},
			{ 1, 3, 2},
			{ 2, 4},
			{ 3, 1, 2},
			{ 1, 3, 1, 1}
		};
		int rst = leastBricks(wall);
		ASSERT(rst == 2);

		wall = {
			{1}, {1}, {1}
		};
		rst = leastBricks(wall);
		ASSERT(rst == 3);
		
		std::cout << "Solution 554 passed!\n";
	}
};
