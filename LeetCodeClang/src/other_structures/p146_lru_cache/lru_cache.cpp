#include "lru_cache.h"

LRUCache::LRUCache(int capacity)
	: capacity(capacity)
{
}

int LRUCache::get(int key)
{
	auto it = hash.find(key);
	if (it == hash.end())
		return -1;

	auto& cache_it = it->second;
	cache.splice(cache.begin(), cache, cache_it); // update cache and its iterator

	return cache_it->second;
}

void LRUCache::put(int key, int value)
{
	auto it = hash.find(key);

	if (it == hash.end()) // not found
	{
		// insert
		cache.insert(cache.begin(), std::make_pair(key, value));
		hash[key] = cache.begin();

		// check capacity
		if (cache.size() > capacity)
		{
			hash.erase(cache.back().first);
			cache.pop_back();
		}
	}
	else // found
	{
		it->second->second = value; // update value
		cache.splice(cache.begin(), cache, it->second); // update cache and its iterator
	}
}
