#include "implement_trie.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC208
{

TEST_CASE("LC208 Implement Trie", "[problem][data_structure][tree][lc208]")
{
	Trie trie;
	trie.insert("apple");
	REQUIRE(trie.search("apple"));
	REQUIRE_FALSE(trie.search("app"));
	REQUIRE(trie.startsWith("app"));
	trie.insert("app");
	REQUIRE(trie.search("app"));
}

} // namespace AlgoCpp::Problem::DataStructure::LC208
