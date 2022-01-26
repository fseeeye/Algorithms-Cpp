#include "non_overlapping_intervals.h"

#include <algorithm>

// Time:  O(N*log(N)) - 我们需要 O(N*log(N)) 的时间对所有的区间按照右端点进行升序排序
// Space: O(log(N)) - 排序需要使用的栈空间
int Solution435::eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
	if (intervals.empty())
		return 0;

	// 把区间们按照结尾大小增序排序
	std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& left, std::vector<int>& right) {
		return left[1] < right[1];
	});

	// 每次选择结尾最小且和前一个选择的区间不重叠的区间
	int intervals_size = static_cast<int>(intervals.size());
	int prev_last = intervals[0][1];
	int removed = 0;
	for (int i = 1; i < intervals_size; i++)
	{
		// 判断是否重叠
		if (intervals[i][0] < prev_last)
		{
			// 如果重叠，移除该区间
			removed++;
		}
		else
		{
			// 如果不重叠，更新 prev_last 为当前区间的结尾
			prev_last = intervals[i][1];
		}
	}

	return removed;
}
