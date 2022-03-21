// 复合数据结构问题
// OJ: https://leetcode-cn.com/problems/lru-cache/
#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>

#include "Tester.h"
#include "Structures.h"

class LRUCache {
public:
	LRUCache(int capacity);

	int get(int key);
	void put(int key, int value);

public:
	void test() {
		
		std::cout << "Solution 146 passed!\n";
	}

private:
	std::list<std::pair<int, int>> cache;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
	int capacity;
};
