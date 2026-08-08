#include "merge_intervals.h"

#include <algorithm>

namespace AlgoCpp::Problem::Algorithm::LC56
{

	// Implement the public interface declared in merge_intervals.h.

	std::vector<std::vector<int>> Solution::merge(std::vector<std::vector<int>>& intervals)
	{
		if (intervals.empty())
		{
			return {};
		}
		std::ranges::sort(intervals);
		std::vector<std::vector<int>> merged;
		// 1. push back first elem
		merged.push_back(intervals[0]);

		// 2. if cannot merge, push it; if can merge, do it.
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][0] <= merged.back()[1])
			{
				merged.back()[1] = std::max(intervals[i][1], merged.back()[1]);
			}
			else
			{
				merged.push_back(intervals[i]);
			}
		}

		return merged;
	}
} // namespace AlgoCpp::Problem::Algorithm::LC56
