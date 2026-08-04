#include "design_circular_deque.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC641
{

TEST_CASE("LC641 Design Circular Deque", "[problem][data_structure][linked_list][lc641]")
{
	MyCircularDeque deque(3);
	REQUIRE(deque.insertLast(1));
	REQUIRE(deque.insertLast(2));
	REQUIRE(deque.insertFront(3));
	REQUIRE_FALSE(deque.insertFront(4));
	REQUIRE(deque.getRear() == 2);
	REQUIRE(deque.isFull());
	REQUIRE(deque.deleteLast());
	REQUIRE(deque.insertFront(4));
	REQUIRE(deque.getFront() == 4);
}

} // namespace AlgoCpp::Problem::DataStructure::LC641
