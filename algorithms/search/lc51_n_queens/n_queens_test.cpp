#include "n_queens.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::Algorithm::LC51
{

	TEST_CASE("LC51 N-Queens", "[problem][algorithm][search][lc51]")
	{
		Solution51 solution;
		std::vector<std::vector<std::string>> rst1 = solution.solveNQueens(4);
		std::vector<std::vector<std::string>> target1 = {
		    {".Q..","...Q","Q...","..Q."},
		    {"..Q.","Q...","...Q",".Q.."}
		};
		REQUIRE(rst1 == target1);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC51
