#include "group_anagrams.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::LC49
{

TEST_CASE("LC49 Group Anagrams", "[problem][review][huawei][lc49]")
{
	std::vector<std::string> values{"eat", "tea", "tan", "ate", "nat", "bat"};
	auto groups = Solution49{}.groupAnagrams(values);
	for (auto& group : groups) std::sort(group.begin(), group.end());
	std::sort(groups.begin(), groups.end());
	std::vector<std::vector<std::string>> expected{{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}};
	std::sort(expected.begin(), expected.end());
	REQUIRE(groups == expected);
}

} // namespace AlgoCpp::Problem::Review::LC49
