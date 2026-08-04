#include "input_nums_count.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ97
{

TEST_CASE("HJ97 Input Nums Count", "[problem][review][huawei][hj97]")
{
	const auto [negativeCount, positiveAverage] = AnalyzeNumbers({-13, -4, -7, 0, 1, 2});
	REQUIRE(negativeCount == 3);
	REQUIRE(positiveAverage == 1.5);
}

} // namespace AlgoCpp::Problem::Review::HJ97
