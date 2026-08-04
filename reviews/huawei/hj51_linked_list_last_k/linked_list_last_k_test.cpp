#include "linked_list_last_k.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ51
{

TEST_CASE("HJ51 Linked List Last K", "[problem][review][huawei][hj51]")
{
	REQUIRE(FindLastKValue({1, 2, 3, 4, 5}, 2) == 4);
	REQUIRE_FALSE(FindLastKValue({1, 2}, 3).has_value());
}

} // namespace AlgoCpp::Problem::Review::HJ51
