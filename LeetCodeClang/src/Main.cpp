#include <iostream>
#include <functional>

// greedy algorithm
#include "p455_assign_cookies/assign_cookies.h"
#include "p135_candy/candy.h"
#include "p435_non_overlapping_intervals/non_overlapping_intervals.h"

// two pointers
#include "p167_two_sum_ii/two_sum_ii.h"

int* addition(int a, int b) {
	int* sum = new int(a + b);
	return sum;
}

int subtraction(int a, int b) {
	return a - b;
}

int operation(int x, int y, std::function<int(int, int)> func) {
	return func(x, y);
}

int main()
{
	/* greedy algorithm */ 
	//Solution455 solution455;
	//solution455.test();

	//Solution135 solution135;
	//solution135.test();

	//Solution435 solution435;
	//solution435.test();

	/* two pointers */
	Solution167 solution167;
	solution167.test();

	std::cin.get();
}