#include "remove_element.h"

#include <catch2/catch_test_macros.hpp>
#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC27
{

	TEST_CASE("LC27 removes matching values in place", "[problem][algorithm][two_pointers][lc27]")
	{
		std::vector<int> values{3, 2, 2, 3};

		const int length = Solution027::removeElement(values, 3);

		REQUIRE(length == 2);
		REQUIRE(values[0] == 2);
		REQUIRE(values[1] == 2);
	}

} // namespace AlgoCpp::Problem::Algorithm::LC27
