#include "implement_queue_using_stacks.h"

#include <catch2/catch_test_macros.hpp>

namespace AlgoCpp::Problem::DataStructure::LC232
{

	TEST_CASE("LC232 Implement Queue Using Stacks", "[problem][data_structure][queue][lc232]")
	{
		// Arrange inputs and invoke the Exercise's native public interface here.
		MyQueue* obj = new MyQueue();
		obj->push(1);
		obj->push(2);
		int param_1 = obj->peek();
		CHECK(param_1 == 1);
		int param_2 = obj->pop();
		CHECK(param_2 == 1);
		bool param_3 = obj->empty();
		CHECK(param_3 == false);
		int param_4 = obj->pop();
		CHECK(param_4 == 2);
	}

} // namespace AlgoCpp::Problem::DataStructure::LC232
