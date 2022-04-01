// XX问题
#pragma once

#include <bits/stdc++.h>

#include "Tester.h"

class HJ54 {
public:
	static void native_main();

	static void compute(std::stack<int>& num_stack, std::stack<char>& op_stack);

	static bool compare_priority(char op1, char op2);

	static void test() {
		while (true)
		{
			std::cout << "\nSolution 54 start.\n";

			native_main();

			std::cout << "\nSolution 54 done.\n";
		}
	}
};
