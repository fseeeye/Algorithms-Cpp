#include "populating_next_right_pointers_in_each_node.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC116
{

TEST_CASE("LC116 Populating Next Right Pointers In Each Node", "[problem][data_structure][tree][lc116]")
{
	Node n4(4);
	Node n5(5);
	Node n6(6);
	Node n7(7);
	Node n2(2, &n4, &n5, nullptr);
	Node n3(3, &n6, &n7, nullptr);
	Node root(1, &n2, &n3, nullptr);
	Solution116::connect(&root);
	REQUIRE(n2.next == &n3);
	REQUIRE(n4.next == &n5);
	REQUIRE(n5.next == &n6);
	REQUIRE(n6.next == &n7);
	REQUIRE(n7.next == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC116
