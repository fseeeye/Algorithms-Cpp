#include "p135_candy.h"

#include <numeric>

// Time:  O(2N)
// Space: O(N)
int Solution135::candy(std::vector<int>& ratings)
{
	int ratings_size = ratings.size();
	// 初始化每个小孩对应的糖果数组，并为每个小孩先分配一颗糖
	std::vector<int> candys(ratings_size, 1);
	// 正向遍历，更新糖果数量
	for (int i = 1; i < ratings_size; i++)
	{
		// 如果当前孩子比他左侧的孩子评分高
		if (ratings[i] > ratings[i - 1])
			// 更新糖果数为：左侧孩子的糖果数加一
			candys[i] = candys[i - 1] + 1;
	}
	// 反向遍历，更新糖果数量
	for (int i = ratings_size - 2; i >= 0; i--)
	{
		// 如果当前孩子比他右侧的孩子评分高
		if (ratings[i] > ratings[i + 1])
			// 更新糖果数为：右侧孩子的糖果数加一(右规则) 与 自己当前糖果数(左规则) 更大的一方
			candys[i] = std::max(candys[i + 1] + 1, candys[i]);
	}

	// 返回糖果数之和
	return std::accumulate(candys.begin(), candys.end(), 0);
}
