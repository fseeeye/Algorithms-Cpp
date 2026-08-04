// BFS
#pragma once

#include <bits/stdc++.h>

#include "common.h"

namespace AlgoCpp::Problem::Review::HJ43
{

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

};

} // namespace AlgoCpp::Problem::Review::HJ43
