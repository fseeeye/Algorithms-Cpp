# leetcode-cpp

二分查找的基本框架如下：

```c++
int binary_search(std::vector<int>& nums, int target)
{
	if (nums.size() == 0) return -1;

	int left = 0, right = /*...*/;

	while (left /*...*/ right)
	{
		int mid = left + (right - left) / 2;

		if (nums[mid] == target)
		{
			/*...*/
		}
		else if (nums[mid] < target)
		{
			left = /*...*/;
		}
		else if (nums[mid] > target)
		{
			right = /*...*/;
		}
	}

	return /*...*/;
}
```

具体模板请参考：[个人总结模板](./template)



