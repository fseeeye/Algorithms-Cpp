// 复合数据结构问题
// OJ: https://leetcode-cn.com/problems/lru-cache/
#pragma once

#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>

#include "common.h"
#include "structures.h"

namespace AlgoCpp::Problem::DataStructure::LC146
{

class LRUCache {
public:
	LRUCache(int capacity);

	int get(int key);
	void put(int key, int value);

public:

private:
	std::list<std::pair<int, int>> cache;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
	int capacity;
};

} // namespace AlgoCpp::Problem::DataStructure::LC146
