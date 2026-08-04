#include "kth_largest_element.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC215
{
	Solution solution;

	TEST_CASE("LC215 finds the kth largest element", "[problem][algorithm][sort][lc215]")
	{
		std::vector<int> nums{3, 2, 1, 5, 6, 4};

		REQUIRE(solution.findKthLargest(nums, 2) == 5);
	}

	TEST_CASE("LC215 handles duplicate values", "[problem][algorithm][sort][lc215]")
	{
		std::vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};

		REQUIRE(solution.findKthLargest(nums, 4) == 4);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC215
