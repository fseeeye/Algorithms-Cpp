// BFS
#pragma once

#include <bits/stdc++.h>

#include "Tester.h"

class HJ43 {
	struct Node {
		int x;
		int y;
		int index;

		Node(int x, int y, int index)
			: x(x), y(y), index(index)
		{}
	};

	static std::vector<int> dirs;

public:
	static void native_main();

	static std::vector<std::pair<int, int>> bfs(std::vector<std::vector<int>>& grid, int n, int m);

	static void test() {
		std::cout << "Solution 43 start.\n";

		native_main();

		std::cout << "\nSolution 43 done.\n";
	}
};
