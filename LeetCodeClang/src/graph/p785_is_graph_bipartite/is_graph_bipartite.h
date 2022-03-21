// 二分图
// OJ: https://leetcode-cn.com/problems/is-graph-bipartite/submissions/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution785 {
public:
	bool isBipartite(std::vector<std::vector<int>>& graph);

	void test() {
		
		std::cout << "Solution 785 passed!\n";
	}
};
