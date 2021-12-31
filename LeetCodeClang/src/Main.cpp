#include <iostream>
#include <functional>

// greedy algorithm
//#include "p455_assign_cookies/assign_cookies.h"
//#include "p135_candy/candy.h"
//#include "p435_non_overlapping_intervals/non_overlapping_intervals.h"

// two pointers
#include "p167_two_sum_ii/two_sum_ii.h"
#include "p88_merge_sorted_array/merge_sorted_array.h"
#include "p142_link_list_cycle_ii/link_list_cycle_ii.h"
#include "p76_minimum_window_substring/minimum_window_substring.h"

int main()
{
	/* two pointers */
	Solution167 solution167;
	solution167.test();

	Solution88 solution88;
	solution88.test();

	Solution142 solution142;
	solution142.test();

	Solution76 solution76;
	solution76.test();

	std::cin.get();
}