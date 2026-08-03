#include "kth_largest_element.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC215
{

	TEST_CASE("LC215 handles duplicate values", "[problem][algorithm][lc215]")
	{
		Solution solution;
		std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};

		REQUIRE(solution.findKthLargest(nums, 4) == 4);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC215
