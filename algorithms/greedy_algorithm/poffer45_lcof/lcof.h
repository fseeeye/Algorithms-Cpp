//
// OJ: https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/

#include <vector>
#include <cassert>
#include <iostream>

#include "common.h"

#include <string>
#include <vector>

class SolutionO45 {
public:
	static std::string minNumber(std::vector<int>& nums);

	static void test() {
		std::vector<int> nums = { 3, 30, 34, 5, 9 };
		std::string rst = minNumber(nums);
		std::cout << rst << std::endl;

		std::cout << "Solution offer 45 passed!\n";
	}
};