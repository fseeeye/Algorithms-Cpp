#include "sequence_reconstruction.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC444
{

TEST_CASE("LC444 Sequence Reconstruction", "[problem][data_structure][graph][lc444]")
{
	std::vector<int> nums{1, 2, 3};
	std::vector<std::vector<int>> unique{{1, 2}, {1, 3}, {2, 3}};
	std::vector<std::vector<int>> ambiguous{{1, 2}, {1, 3}};
	REQUIRE(Solution444::sequenceReconstruction(nums, unique));
	REQUIRE_FALSE(Solution444::sequenceReconstruction(nums, ambiguous));
}

} // namespace AlgoCpp::Problem::DataStructure::LC444
