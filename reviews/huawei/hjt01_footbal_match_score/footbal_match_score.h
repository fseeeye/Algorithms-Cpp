// 字符串 + 排序
//题目描述
// 
//足球比赛采用双循环赛制（即任意两队之间分主客场进行两场比赛），胜平负分别得分3、1、0分。
//设计一个足球比赛自动排名系统，以数组形式输入比赛信息，如 String[] str = { "a-b 2:1","a-c 3:4" }。
//假设队伍名为a - z的26个英文字母，比赛球队最多26只。
//输出各个参赛球队的积分并由高到低排名（积分相同的按照球队名进行字典序排序）。
//输入描述：
//
//输入的每一行代表 一场比赛 的比分（每场比分的2个数值为0~9之间，即大于等于0，小于等于9），队伍之间以"-"分隔，比分之间以":"分隔，空行为输入结束。
//
//输入保障正确，每两个队伍之间有主客场两场比赛，不多也不少，不需要异常判断。
//
//输出描述：
//
//输出各个参赛球队的积分并 由高到低 排名(积分相同的按照球队名进行字典序排序)。
//输出结果中，队伍之间以","分隔。
//示例 1 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//输入
//
//1
//2
//a - b 3:0
//b - a 1 : 1
//输出
//
//1
//a 4, b 1
//说明
//
//a - b 3:0，则a积3分，b积0分；
//b - a 1 : 1，则a积1分，b积1分。
//因此最终a积4分，b积1分。
//示例 2 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//输入
//
//1
//2
//3
//4
//5
//6
//a - b 3:0
//a - c 2 : 1
//b - a 1 : 1
//c - a 0 : 1
//b - c 4 : 3
//c - b 2 : 2
//输出
//
//1
//a 10, b 5, c 1

#pragma once

#include <bits/stdc++.h>

#include "common.h"

class HJT01 {
public:
	static void native_main();

	static std::vector<std::pair<std::string, int>> sort(std::vector<std::string>& inputs);

	template<typename T>
	static void spilt(std::string& input, char pattern, std::vector<T>& output)
	{
		input.push_back(pattern);
		int start = 0;

		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == pattern)
			{
				output.push_back(input.substr(start, i - start));
				start = i + 1;
			}
		}
	}

	template<typename T = int>
	static void spilt(std::string& input, char pattern, std::vector<int>& output)
	{
		input.push_back(pattern);
		int start = 0;

		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == pattern)
			{
				output.push_back(std::stoi(input.substr(start, i - start)));
				start = i + 1;
			}
		}
	}

	static void test() {
		std::cout << "Solution start.\n";

		native_main();

		std::cout << "\nSolution done.\n";
	}
};
