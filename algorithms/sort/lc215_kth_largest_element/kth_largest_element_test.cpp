#include "kth_largest_element.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC215
{

	TEST_CASE("LC215 finds the kth largest element", "[problem][algorithm][lc215]")
	{
		Solution solution;
		std::vector<int> nums{3, 2, 1, 5, 6, 4};

		REQUIRE(solution.findKthLargest(nums, 2) == 5);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC215
