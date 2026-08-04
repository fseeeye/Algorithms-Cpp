// 字符串处理
// OJ: https://leetcode-cn.com/problems/group-anagrams/
#pragma once

#include <iostream>
#include <vector>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::Review::LC49
{

class Solution49 {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

};

} // namespace AlgoCpp::Problem::Review::LC49
