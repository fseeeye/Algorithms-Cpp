// 区间重叠问题
// OJ: https://leetcode-cn.com/problems/my-calendar-i/
#pragma once

#include <iostream>
#include <map>

#include "common.h"
#include "Structures.h"

class MyCalendar {
	std::map<int, int> calendar;

public:
	MyCalendar() = default;

	bool book(int start, int end);

public:
	static void test() {
		MyCalendar* c = new MyCalendar();
		ASSERT(c->book(10, 20) == true);
		ASSERT(c->book(15, 25) == false);
		ASSERT(c->book(20, 30) == true);
		
		std::cout << "Solution 729 passed!\n";
	}
};
