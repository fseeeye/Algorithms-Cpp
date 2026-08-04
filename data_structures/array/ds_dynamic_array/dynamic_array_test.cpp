#include "dynamic_array.h"

#include <catch2/catch_test_macros.hpp>
#include <string>

namespace AlgoCpp::Template::DataStructure::DynamicArray
{

TEST_CASE("Dynamic Array grows and owns its values", "[template][data_structure][array][dynamic_array]")
{
	DynamicArray<std::string> values(1);
	values.PushBack("alpha");
	values.EmplaceBack(3, 'b');

	REQUIRE(values.Size() == 2);
	REQUIRE(values.Capacity() >= 2);
	REQUIRE(values.At(0) == "alpha");
	REQUIRE(values.At(1) == "bbb");

	DynamicArray<std::string> copied = values;
	values.RemoveAt(0);
	REQUIRE(values.At(0) == "bbb");
	REQUIRE(copied.At(0) == "alpha");

	values.Clear();
	REQUIRE(values.IsEmpty());
	REQUIRE_THROWS_AS(values.At(0), std::out_of_range);
}

} // namespace AlgoCpp::Template::DataStructure::DynamicArray
