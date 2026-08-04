// 二分搜索个人总结模板
#pragma once

#include <iostream>
#include <vector>

#include "common.h"

namespace AlgoCpp::Template::Algorithm::BinarySearch
{

class IntervalSearchTemp {
public:
	// 搜索一个数：左闭右闭
	int binary_search(std::vector<int>& nums, int target);

	// 搜索左边界：左闭右闭
	int binary_search_left_bound2(std::vector<int>& nums, int target);

	// 搜索右边界：左闭右闭
	int binary_search_right_bound2(std::vector<int>& nums, int target);

	// 搜索左边界：左闭右开
	int binary_search_left_bound(std::vector<int>& nums, int target);

	// 搜索右边界：左闭右开
	int binary_search_right_bound(std::vector<int>& nums, int target);

};

} // namespace AlgoCpp::Template::Algorithm::BinarySearch
