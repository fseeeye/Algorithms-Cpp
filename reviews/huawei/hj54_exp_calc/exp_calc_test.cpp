#include "exp_calc.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace AlgoCpp::Problem::Review::HJ54
{

TEST_CASE("HJ54 Exp Calc", "[problem][review][huawei][hj54]")
{
	REQUIRE(EvaluateExpression("3+2*6-2") == 13);
	REQUIRE(EvaluateExpression("3*(4-2)+10/5") == 8);
	REQUIRE(EvaluateExpression("-3+5") == 2);
}

} // namespace AlgoCpp::Problem::Review::HJ54
