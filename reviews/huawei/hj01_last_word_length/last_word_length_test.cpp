#include "last_word_length.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ01
{

TEST_CASE("HJ01 Last Word Length", "[problem][review][huawei][hj01]")
{
	REQUIRE(LastWordLength("hello nowcoder") == 8);
	REQUIRE(LastWordLength("single") == 6);
}

} // namespace AlgoCpp::Problem::Review::HJ01
