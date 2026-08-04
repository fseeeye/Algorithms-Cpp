#include "next_greater_element_ii.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::DataStructure::LC503
{

	TEST_CASE("LC503 Next Greater Element Ii", "[problem][data_structure][other][lc503]")
	{
		Solution503 solution;
		std::vector<int> nums = { -2, 1 };
		std::vector<int> rst = solution.nextGreaterElements(nums);
		REQUIRE(rst == std::vector({ 1, -1 }));
	}

} // namespace AlgoCpp::Problem::DataStructure::LC503
