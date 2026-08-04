#include "validate_stack_sequences.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC946
{

	TEST_CASE("LC946 Validate Stack Sequences", "[problem][algorithm][greedy_algorithm][lc946]")
	{
		Solution946 solution;
		std::vector<int> pushed = { 1, 2, 3, 4, 5 };
		std::vector<int> poped = { 4, 5, 3, 2, 1 };
		REQUIRE(solution.validateStackSequences(pushed, poped) == true);

		pushed = { 1, 2, 3, 4, 5 };
		poped = { 4, 3, 5, 1, 2 };
		REQUIRE(solution.validateStackSequences(pushed, poped) == false);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC946
