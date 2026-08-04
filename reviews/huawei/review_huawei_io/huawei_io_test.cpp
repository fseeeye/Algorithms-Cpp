#include "huawei_io.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Template::Review::HuaweiIO
{

TEST_CASE("Huawei IO parses and formats delimited integers", "[template][review][huawei][huawei_io]")
{
	REQUIRE(Trim("  value  ") == "value");
	REQUIRE(SplitIntegers("1, 2,-3", ',') == std::vector<int>{1, 2, -3});
	REQUIRE(JoinIntegers({1, 2, -3}, ',') == "1,2,-3");
	REQUIRE_THROWS_AS(SplitIntegers("1,nope", ','), std::invalid_argument);
}

} // namespace AlgoCpp::Template::Review::HuaweiIO
