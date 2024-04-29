#include "merge_sorted_array.h"

// Time:  O(m+n)，指针移动单调递减，最多移动 m+nm+n 次，因此时间复杂度为 O(m+n)O(m+n)。
// Space: O(1)，直接对数组 nums1 原地修改，不需要额外空间。
void Solution88::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int n1 = m - 1; // 指向 nums1 需排序元素结尾，初始化为 m - 1
	int n2 = n - 1; // 指向 nums2 需排序元素结尾，初始化为 n - 1
	int pos = m + n - 1; // 指向拷贝位置，初始化为 nums1 数组最后

	while (n2 >= 0) {
		// 如果 nums2 和 nums1 均未拷贝完 
		if (n1 >= 0)
		{
			// 比较双指针只想元素的大小，大的那个拷贝至 pos 所在位置
			nums1[pos--] = nums1[n1] > nums2[n2] ? nums1[n1--] : nums2[n2--];
		}
		// 如果 nums1 已经拷贝完了
		else
		{
			// 直接逐个复制 nums2 中的元素
			nums1[pos--] = nums2[n2--];
		}
		// 如果 nums2 已经拷贝完了，就直接终止程序
	}
}
