#include "template_binary_search.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Template::Algorithm::BinarySearch
{

	TEST_CASE("Algorithm.BinarySearch Binary Search", "[template][algorithm][binary_search]")
	{
		IntervalSearchTemp solution;
		std::vector<int> values = {0, 1, 1, 2, 3, 3, 9, 10, 10, 10};

		REQUIRE(solution.binary_search(values, 3) == 4);
		REQUIRE(solution.binary_search_left_bound2(values, 10) == 7);
		REQUIRE(solution.binary_search_right_bound2(values, 10) == 9);
		REQUIRE(solution.binary_search_left_bound(values, 10) == 7);
		REQUIRE(solution.binary_search_right_bound(values, 10) == 9);
		REQUIRE(solution.binary_search(values, 8) == -1);
	}

} // namespace AlgoCpp::Template::Algorithm::BinarySearch
