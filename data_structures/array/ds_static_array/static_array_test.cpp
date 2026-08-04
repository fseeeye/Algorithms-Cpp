#include "static_array.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Template::DataStructure::StaticArray
{

TEST_CASE("Static Array exposes fixed-size indexed storage", "[template][data_structure][array][static_array]")
{
	StaticArray<int, 3> values;
	static_assert(values.Size() == 3);
	values[0] = 2;
	values[1] = 4;
	values[2] = 6;

	REQUIRE(values.Data()[1] == 4);
	REQUIRE(values.At(2) == 6);
	REQUIRE_THROWS_AS(values.At(3), std::out_of_range);
}

} // namespace AlgoCpp::Template::DataStructure::StaticArray
