#include "word_search.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC79
{

	TEST_CASE("LC79 Word Search", "[problem][algorithm][search][lc79]")
	{
		Solution79 solution;
		std::vector<std::vector<char>> board = {
		    {'A', 'B', 'C', 'E'},
		    {'S', 'F', 'C', 'S'},
		    {'A', 'D', 'E', 'E'},
		};
		REQUIRE(solution.exist(board, "ABCCED"));
		REQUIRE(solution.exist(board, "SEE"));
		REQUIRE(!solution.exist(board, "ABCB"));
	}

} // namespace AlgoCpp::Problem::Algorithm::LC79
