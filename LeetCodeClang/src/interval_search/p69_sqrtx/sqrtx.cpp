#include "sqrtx.h"

// Time:  O(log(N))
// Space: O(1)
int Solution69::mySqrt(int x)
{
	int l = 0, r = x, mid; // 初始化区间
	long long square;
	// 左闭右闭方法
	while (l <= r)
	{
		mid = l + (r - l) / 2; // 避免溢出
		square = (long long)mid * mid;
		if (square < x)
		{
			l = mid + 1;
		}
		else if(square > x)
		{
			r = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return r; // 由于需要舍弃小数部分，最后我们取右值
}
