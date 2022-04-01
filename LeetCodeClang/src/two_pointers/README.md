# leetcode-cpp

## 滑动窗口

滑动窗口的基本框架如下：

```c++
void sliding_window(std::string origin_str, std::string target_str)
{
	std::unordered_map<char, int> chars_need; // 需要那些字符及其数量
	std::unordered_map<char, int> chars_window; // 滑动窗口中拥有的字符及其数量

	int l = 0, r = 0;
	int chars_count = 0; // 滑动窗口中拥有的所需字符的数目

	// 初始化 chars_need
	for (char c : target_str)
	{
		chars_need[c]++;
	}

	auto s_size = origin_str.size();
	for (; r < s_size; r++) // 窗口右侧扩大，并判断停止条件
	{
		// 窗口内数据的更新逻辑
		// ...

		// debug r & l

		// 判断窗口是否要收缩
		while (/*...*/)
		{
			// 当前需要移出的字符
			char removed_char = origin_str[l];
			// 窗口左侧收缩
			++l;
			// 窗口数据的更新逻辑
			// ...
		}
	}

	// return ...
}
```
