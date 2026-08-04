#include "populating_next_right_pointers_in_each_node_ii.h"

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace AlgoCpp::Problem::DataStructure::LC117
{

TEST_CASE("LC117 Populating Next Right Pointers In Each Node Ii", "[problem][data_structure][tree][lc117]")
{
	Node n5(5);
	Node n7(7);
	Node n2(2, nullptr, &n5, nullptr);
	Node n3(3, nullptr, &n7, nullptr);
	Node root(1, &n2, &n3, nullptr);
	Solution117::connect(&root);
	REQUIRE(n2.next == &n3);
	REQUIRE(n5.next == &n7);
	REQUIRE(n7.next == nullptr);
}

} // namespace AlgoCpp::Problem::DataStructure::LC117
