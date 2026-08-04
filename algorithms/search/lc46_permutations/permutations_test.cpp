#include "permutations.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC46
{

	TEST_CASE("LC46 Permutations", "[problem][algorithm][search][lc46]")
	{
		Solution46 solution;
		std::vector<int> nums1 = { 1, 2, 3 };
		std::vector<std::vector<int>> rst1 = solution.permute(nums1);
		std::vector<std::vector<int>> target = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2} };
		REQUIRE(rst1 == target);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC46
