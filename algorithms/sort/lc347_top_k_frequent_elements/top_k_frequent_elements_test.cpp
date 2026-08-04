#include "top_k_frequent_elements.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC347
{

	TEST_CASE("LC347 Top k Frequent Elements", "[problem][algorithm][sort][lc347]")
	{
		Solution347 solution;
		std::vector<int> nums1 = { 1, 1, 1, 2, 2, 3 };
		std::vector<int> rst1 = solution.topKFrequent(nums1, 2);
		std::vector<int> target_rst1 = { 1, 2 };
		REQUIRE(rst1 == target_rst1);

		std::vector<int> nums2 = { 1 };
		std::vector<int> rst2 = solution.topKFrequent(nums2, 1);
		std::vector<int> target_rst2 = { 1 };
		REQUIRE(rst2 == target_rst2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC347
