// 字符串处理
// OJ: https://leetcode-cn.com/problems/group-anagrams/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution49 {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

	static void test() {
		
		std::cout << "Solution 049 passed!\n";
	}
};
