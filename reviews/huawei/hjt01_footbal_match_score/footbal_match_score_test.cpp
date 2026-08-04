#include "footbal_match_score.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJT01
{

TEST_CASE("HJT01 Footbal Match Score", "[problem][review][huawei][hjt01]")
{
	std::vector<std::string> matches{"a-b 3:0", "b-a 1:1"};
	REQUIRE(HJT01::sort(matches) == std::vector<std::pair<std::string, int>>{{"a", 4}, {"b", 1}});
}

} // namespace AlgoCpp::Problem::Review::HJT01
