// BFS
// OJ: https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/
#pragma once

#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC1129
{

	class Solution1129
	{
	public:
		static std::vector<int> shortestAlternatingPaths(
			int n,
			std::vector<std::vector<int>>& redEdges,
			std::vector<std::vector<int>>& blueEdges);
	};

} // namespace AlgoCpp::Problem::Algorithm::LC1129
