#include "lru_cache.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC146
{

TEST_CASE("LC146 Lru Cache", "[problem][data_structure][other][lc146]")
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	REQUIRE(cache.get(1) == 1);
	cache.put(3, 3);
	REQUIRE(cache.get(2) == -1);
	cache.put(4, 4);
	REQUIRE(cache.get(1) == -1);
	REQUIRE(cache.get(3) == 3);
	REQUIRE(cache.get(4) == 4);
}

} // namespace AlgoCpp::Problem::DataStructure::LC146
