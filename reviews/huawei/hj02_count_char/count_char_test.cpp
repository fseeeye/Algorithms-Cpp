#include "count_char.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::HJ02
{

	TEST_CASE("HJ02 counts characters without case sensitivity", "[problem][algorithm][hj02]")
	{
		REQUIRE(CountChar("ABCabc", 'A') == 2);
		REQUIRE(CountChar("ABCabc", 'a') == 2);
	}

	TEST_CASE("HJ02 counts spaces", "[problem][algorithm][hj02]") { REQUIRE(CountChar("A B C", ' ') == 2); }

} // namespace AlgoCpp::Problem::Algorithm::HJ02
