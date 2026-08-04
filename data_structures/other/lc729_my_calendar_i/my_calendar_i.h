// 区间重叠问题
// OJ: https://leetcode-cn.com/problems/my-calendar-i/
#pragma once

#include <iostream>
#include <map>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC729
{

class MyCalendar {
	std::map<int, int> calendar;

public:
	MyCalendar() = default;

	bool book(int start, int end);

public:
};

} // namespace AlgoCpp::Problem::DataStructure::LC729
