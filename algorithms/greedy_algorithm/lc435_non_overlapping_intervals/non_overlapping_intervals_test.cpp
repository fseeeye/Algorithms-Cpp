#include "non_overlapping_intervals.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC435
{

	TEST_CASE("LC435 Non-Overlapping Intervals", "[problem][algorithm][greedy_algorithm][lc435]")
	{
		Solution435 solution;
		std::vector<std::vector<int>> intervals0 = {};
		REQUIRE(solution.eraseOverlapIntervals(intervals0) == 0);

		std::vector<std::vector<int>> intervals1 = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
		REQUIRE(solution.eraseOverlapIntervals(intervals1) == 1);

		std::vector<std::vector<int>> intervals2 = { {1, 2}, {1, 2}, {1, 2}, {1, 2} };
		REQUIRE(solution.eraseOverlapIntervals(intervals2) == 3);

		std::vector<std::vector<int>> intervals3 = { {1, 2}, {2, 3} };
		REQUIRE(solution.eraseOverlapIntervals(intervals3) == 0);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC435
