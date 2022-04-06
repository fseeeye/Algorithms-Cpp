// 滑动窗口
//题目描述
//
//给出一个数组nums，你需要通过交换位置，将数组中 任何位置 上的 小于 k 的整数 组合到一起，并返回所有可能中所需最少的交换次数。
//
//输出将数组A中小于k的整数组合到一起的最小交换次数。
//
//组合在一起是指满足条件的数字相邻，不要求在数组中的位置相邻。
//
//示例 1 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//输入
//
//1
//2
//1, 3, 1, 4, 0
//2
//输出
//
//1
//1
//说明
//
//交换3和0
//
//示例 2 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//1
//2
//0, 0, 0, 1, 0
//2
//输出
//
//1
//0
//说明
//
//已经满足条件，不需要交换。
//
//示例 3 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//1
//2
//2, 3, 2
//1
//输出
//
//1
//0
//说明
//
//不存在小于k的数，无需交换。

#pragma once

#include <bits/stdc++.h>

#include "Tester.h"

class HJT03 {
public:
	static void native_main();

	static int minTimes(std::vector<int>& nums, int k);

	static void spilt(std::string& input, std::vector<int>& output, char pattern = ',')
	{
		input.push_back(pattern);
		int beginning = 0;

		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == pattern)
			{
				output.push_back(std::stoi(input.substr(beginning, i - beginning)));
				beginning = i + 1;
			}
		}
	}

	static void test() {
		std::cout << "Solution start.\n";

		native_main();

		std::cout << "\nSolution done.\n";
	}
};
