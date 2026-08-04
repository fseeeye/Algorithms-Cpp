// 字符串
//题目描述
//
//存在一种虚拟IPv4地址，由4小节组成，每节的范围为0~128，以#号间隔，格式如下：
//
//1
//(1~128)#(0~255)#(0~255)#(0~255)
//请利用这个特性把虚拟IPv4地址转换为一个32位的整数，IPv4地址以字符串形式给出，要求每个IPv4地址只能对应到唯一的整数上。
//
//如果是非法IPv4，返回 invalid IP。
//
//输入描述：
//
//输入一行，虚拟IPv4地址格式字符串
//
//输出描述：
//
//输出一行，按照要求输出整型或者特定字符
//
//示例 1 输入输出示例仅供调试，后台判题数据一般不包含示例
//
//输入
//
//1
//100#101#1#5
//输出
//
//1
//1684340997
//样例解释
//
//举例：一个ip地址为100#101#1#5
//
//alt
//
//组合起来即为：01100100 01100101 00000001 00000101，转换为10进制数就是：1684340997， 即该IP地址转换后的数字就是它。


#pragma once

#include <bits/stdc++.h>

#include "common.h"

class HJT02 {
public:
	static void native_main();

	static unsigned int handle(std::string input);

	static void spiltString(std::string& input, std::vector<int>& output, char pattern = '#')
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
