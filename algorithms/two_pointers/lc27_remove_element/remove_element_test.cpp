#include "remove_element.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC27
{

	TEST_CASE("LC27 removes matching values in place", "[problem][algorithm][two_pointers][lc27]")
	{
		std::vector<int> nums{3, 2, 2, 3};

		const int length = Solution027::removeElement(nums, 3);

		REQUIRE(length == 2);
		REQUIRE(nums[0] == 2);
		REQUIRE(nums[1] == 2);

		std::vector<int> nums1{};
		const int length1 = Solution027::removeElement(nums1, 0);
		REQUIRE(length1 == 0);
	}

	TEST_CASE("LC27 removes matching values in place (Optimized Version)", "[problem][algorithm][two_pointers][lc27]")
	{
		std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};

		const int length = Solution027::removeElementOpt(nums, 2);

		REQUIRE(length == 5);
		REQUIRE(nums[0] != 2);
		REQUIRE(nums[1] != 2);
		REQUIRE(nums[2] != 2);
		REQUIRE(nums[3] != 2);
		REQUIRE(nums[4] != 2);

		std::vector<int> nums1{};
		const int length1 = Solution027::removeElementOpt(nums1, 0);
		REQUIRE(length1 == 0);

		std::vector<int> nums2{1};
		const int length2 = Solution027::removeElementOpt(nums2, 1);
		REQUIRE(length2 == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC27
