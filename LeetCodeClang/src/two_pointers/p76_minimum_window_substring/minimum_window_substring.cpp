#include "minimum_window_substring.h"

#include <vector>

// Time:  O(N) = O(N) + O(N)
// Space: O(1)
std::string Solution76::minWindow(std::string s, std::string t)
{
	unsigned int s_size = s.size(), t_size = t.size();
	// 滑动窗口双指针
	unsigned int l = 0, r = 0; 
	// 最小滑动窗口存储变量
	unsigned int min_window_size = s_size + 1, min_l = 0; // 最小滑动窗口大小和最小l，方便最后取出该窗口
	// 辅助统计变量
	std::vector<int> chars_need(128, 0); // 目前 t 中每个字符在滑动窗口中的缺少数量
	std::vector<bool> chars_exist(128, false); // t 是否存在该字符
	unsigned int chars_count = 0; // 统计目前滑动窗口中拥有的 t 中字符数量

	// 统计 t 中的字符，从而更新两个辅助数组
	for (char i : t)
	{
		++chars_need[i];
		chars_exist[i] = true;
	}

	// 移动滑动窗口，不断更新数组和最短字符串的长度
	for (; r < s_size; ++r)
	{
		// 如果 t 存在当前字符
		if (chars_exist[s[r]])
		{
			// 如果 t 还需要当前字符，则更新 chars_count
			if (chars_need[s[r]]-- > 0)
			{
				++chars_count;
			}
			// 如果滑动窗口目前已经包含 t 中的全部字符
			while (chars_count == t_size)
			{
				// 检查当前滑动窗口大小是否更小
				if (r - l + 1 < min_window_size)
				{
					// 更新 min_window_size 和 min_l
					min_window_size = r - l + 1;
					min_l = l;
				}
				// 尝试右移 l，同时更新统计数组和 chars_count
				if (chars_exist[s[l]] && ++chars_need[s[l]] > 0)
				{
					--chars_count;
				}
				++l;
			}
		}
	}

	return min_window_size <= s_size ? s.substr(min_l, min_window_size) : "";
}
