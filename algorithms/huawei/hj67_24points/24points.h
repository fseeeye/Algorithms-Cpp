// DFS
#pragma once

#include <bits/stdc++.h>

#include "common.h"

class HJ67 {
public:
	static void native_main();

	static bool dfsRecurse(std::vector<float> nums, float sum);

	static void test() {
		std::cout << "Solution 67 start.\n";

		native_main();

		std::cout << "\nSolution 67 done.\n";
	}
};
