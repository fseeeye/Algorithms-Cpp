# Algorithms-Cpp

My collection of algorithm and data structure solutions.

## Get Started

1. (Optional)Install vcpkg : 
    1. `git clone https://github.com/microsoft/vcpkg.git`
    2. `cd vcpkg`
    3. `.\bootstrap-vcpkg.bat`
    4. add install path to system environment variable `VCPKG_ROOT` : `set VCPKG_ROOT="C:\path\to\vcpkg"; set PATH=%VCPKG_ROOT%;%PATH%`
2. Install [Xmake](https://xmake.io) : `winget install xmake`
3. Develop with VS:
    1. Run `xmake project -k vsxmake -m "debug,release"`
    2. Open the generated VS solution file in `vsxmake20xx` folder. Exercise projects are grouped by their source path, such as `Algorithms/binary_search`, and source, header, metadata, and test files appear directly beneath their target.
    3. Choose **Release/Debug x64** and Build in Visual Studio.
4. Develop with VSCode:
    1. (Optional) Set Debug/Release mode: `xmake config -m [debug|release] -y`
    2. (Optional) Make compile_commands.json file: `xmake project -k compile_commands .vscode`
    3. Open vscode with Developer Command Prompt for VSxx
5. Run an Exercise target:
    1. Build: `xmake build xxx`
    2. Run: `xmake run xxx [-d]`

## Exercise Workflow

Each Exercise is built as an independent Catch2 test executable. Xmake manages Catch2 `3.15.x`, discovers Exercise directories recursively, and creates one target for every valid `exercise.json` plus `*_test.cpp` pair. Every Exercise depends on the `basic` support library and is excluded from the default build.

- Create a Problem Exercise while retaining the problem's native public API:

```powershell
# Simple
xmake new --kind=problem --root=algorithms/sort --id=LC215 --slug=kth_largest_element
# Full
xmake new --kind=problem --root=algorithms/sort --id=LC215 --slug=kth_largest_element `
  --name="Kth Largest Element" --difficulty=Medium `
  --tip="Quick select" --url=https://leetcode.com/problems/kth-largest-element-in-an-array/
```

This maps to directory and target `lc215_kth_largest_element`, namespace `AlgoCpp::Problem::Algorithm::LC215`, and Catch2 tags `[problem][algorithm][sort][lc215]`.

- Create a reusable Template Exercise without an external problem ID:

```powershell
xmake new --kind=template --root=data_structures/array --slug=dynamic_array
```

This maps to directory and target `ds_dynamic_array`, namespace `AlgoCpp::Template::DataStructure::DynamicArray`, and tags `[template][data_structure][array][dynamic_array]`. The initial scaffold contains commented interface examples and a failing placeholder test; replace that placeholder with real assertions after choosing the Exercise's natural API.

- The top-level root determines the namespace domain: `algorithms` → `Algorithm`, `data_structures` → `DataStructure`, and `reviews` → `Review`. Problem IDs and slugs are safely normalized and reported. Unsafe input, an unsupported root, an existing target, or a duplicate Problem ID fails without leaving a partial Exercise. `--url` is optional for both Problem and Template Exercises; when supplied, it is stored in metadata and emitted once as `// refs : URL` above the generated header.

A typical Exercise is:

```text
lc215_kth_largest_element/
├── kth_largest_element.h
├── kth_largest_element.cpp
├── kth_largest_element_test.cpp
├── duplicates_test.cpp          # optional; any number of *_test.cpp files
└── exercise.json
```

Use the same Catch2 `TEST_CASE` form for Huawei, LeetCode, and Template Exercises; invoke each Exercise through its natural public API:

```cpp
TEST_CASE("LC215 finds the kth largest element", "[problem][algorithm][sort][lc215]")
{
    Solution solution;
    std::vector<int> nums{3, 2, 1, 5, 6, 4};
    REQUIRE(solution.findKthLargest(nums, 2) == 5);
}
```

```cpp
TEST_CASE("HJ02 counts characters without case sensitivity", "[problem][review][huawei][hj02]")
{
    REQUIRE(CountChar("ABCabc", 'A') == 2);
}
```

Run one Exercise or every Exercise Test:

```powershell
xmake run lc215_kth_largest_element
xmake test
```

`exercise.json` is the catalog source of truth. Regenerate the managed README region with `xmake index`, or verify that it is current without writing via `xmake index --check`. The index follows the `algorithms` and `data_structures` directory categories; Review Exercises remain buildable but are intentionally omitted.

## Exercise Index

<!-- exercise-index:start -->
### Algorithms

#### Binary Search

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| Algorithm.BinarySearch | [Binary Search](./algorithms/binary_search/algo_binary_search) |  |  |
| LC34 | [Find First and Last Position of Element in Sorted Array](./algorithms/binary_search/lc34_find_ele_in_sorted_array) | Medium | 查找区间 |
| LC69 | [Sqrt(x)](./algorithms/binary_search/lc69_sqrtx) | Easy | 开方 |
| LC81 | [Search In Rotated Sorted Array II](./algorithms/binary_search/lc81_search_in_rotated_sorted_array_ii) | Medium | 旋转数组 |

#### Divide Conquer

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC241 | [Different Ways to Add Parentheses](./algorithms/divide_conquer/lc241_different_ways_to_add_parentheses) |  |  |

#### Dynamic Programming

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC10 | [Regular Expression Matching](./algorithms/dynamic_programming/lc10_regular_expression_matching) | Hard | 字符串编辑问题 |
| LC64 | [Minimum Path Sum](./algorithms/dynamic_programming/lc64_mini_path_sum) | Medium | 二维 |
| LC70 | [Climbing Stairs](./algorithms/dynamic_programming/lc70_climbing_stairs) | Easy | 一维 |
| LC72 | [Edit Distance](./algorithms/dynamic_programming/lc72_edit_distance) | Hard | 字符串编辑问题 |
| LC91 | [Decode Ways](./algorithms/dynamic_programming/lc91_decode_ways) | Medium | 分割问题 |
| LC121 | [Best Time to Buy and Sell Stock](./algorithms/dynamic_programming/lc121_best_time_to_buy_and_sell_stock) | Easy | 股票交易问题 |
| LC139 | [Word Break](./algorithms/dynamic_programming/lc139_word_break) | Medium | 分割问题 |
| LC188 | [Best Time to Buy and Sell Stock IV](./algorithms/dynamic_programming/lc188_best_time_to_buy_and_sell_stock_iv) | Hard | 股票交易问题 |
| LC198 | [Hourse Robber](./algorithms/dynamic_programming/lc198_house_robber) | Easy | 一维 |
| LC221 | [Maximal Square](./algorithms/dynamic_programming/lc221_maximal_square) | Medium | 二维 |
| LC279 | [Perfect Square](./algorithms/dynamic_programming/lc279_perfect_squares) | Medium | 分割问题 |
| LC300 | [Logest Increasing Subsequence](./algorithms/dynamic_programming/lc300_longest_increasing_subsequence) | Medium | 子序列问题 |
| LC309 | [Best Time to Buy and Sell Stock with Cooldown](./algorithms/dynamic_programming/lc309_best_time_to_buy_and_sell_stock_with_cooldown) | Medium | 股票交易问题 |
| LC322 | [Coin Change](./algorithms/dynamic_programming/lc322_coin_change) | Medium | 完全背包问题 |
| LC413 | [Arithmetic Slices](./algorithms/dynamic_programming/lc413_arithmetic_slices) | Medium | 一维 |
| LC416 | [Partition Equal Subset Sum](./algorithms/dynamic_programming/lc416_partition_equal_subset_sum) | Medium | 背包问题 |
| LC474 | [Ones and Zeros](./algorithms/dynamic_programming/lc474_ones_and_zeroes) | Medium | 0-1背包问题 |
| LC542 | [0-1 Matrix](./algorithms/dynamic_programming/lc542_01_matrix) | Medium | 二维 |
| LC650 | [2 Keys Keyboard](./algorithms/dynamic_programming/lc650_2_keys_keyboard) | Medium | 字符串编辑问题 |
| LC1143 | [Logest Common Subsequence](./algorithms/dynamic_programming/lc1143_longest_commom_subsequence) | Medium | 子序列问题 |

#### Greedy Algorithm

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC135 | [Candy](./algorithms/greedy_algorithm/lc135_candy) | Hard | 分配问题 |
| LC435 | [Non-Overlapping Intervals](./algorithms/greedy_algorithm/lc435_non_overlapping_intervals) | Medium | 区间问题 |
| LC455 | [Assign Cookies](./algorithms/greedy_algorithm/lc455_assign_cookies) | Easy | 分配问题 |
| LC946 | [Validate Stack Sequences](./algorithms/greedy_algorithm/lc946_validate_stack_sequences) |  | 栈 |
| LCOF45 | [Arrange Array to Minimum Number](./algorithms/greedy_algorithm/lcof45_arrange_array_to_min_number) | Easy | 排序 |

#### Search

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC46 | [Permutations](./algorithms/search/lc46_permutations) | Medium | 回溯法 |
| LC51 | [N-Queens](./algorithms/search/lc51_n_queens) | Hard | 回溯法 |
| LC77 | [Combinations](./algorithms/search/lc77_combinations) | Medium | 回溯法 |
| LC79 | [Word Search](./algorithms/search/lc79_word_search) | Medium | 回溯法 |
| LC126 | [Word Ladder II](./algorithms/search/lc126_word_ladder_ii) | Hard | 广度优先搜索 |
| LC417 | [Pacific Atlantic Waterflow](./algorithms/search/lc417_pacific_atlantic_water_flow) | Medium | 深度优先搜索 |
| LC494 | [Target Sum](./algorithms/search/lc494_target_sum) |  |  |
| LC547 | [Number of Provinces](./algorithms/search/lc547_number_of_provinces) | Medium | 深度优先搜索 |
| LC695 | [Max Area of Island](./algorithms/search/lc695_max_area_of_island) | Medium | 深度优先搜索 |
| LC752 | [Open The Lock](./algorithms/search/lc752_open_the_lock) |  |  |
| LC934 | [Shortest Bridge](./algorithms/search/lc934_shortest_bridge) | Medium | 广度优先搜索 |
| LC1091 | [Shortest Path In Binary Matrix](./algorithms/search/lc1091_shortest_path_in_binary_matrix) |  |  |
| LC1129 | [Shortest Path with Alternating Colors](./algorithms/search/lc1129_shortest_path_with_alternating_colors) |  |  |
| LC1254 | [Number Of Closed Islands](./algorithms/search/lc1254_number_of_closed_islands) |  |  |

#### Sort

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC215 | [Kth Largest Element](./algorithms/sort/lc215_kth_largest_element) | Medium | 快速选择 |
| LC347 | [Top k Frequent Elements](./algorithms/sort/lc347_top_k_frequent_elements) | Medium | 桶排序 |

#### Two Pointers

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC3 | [Longest Substring Without Repeating Characters](./algorithms/two_pointers/lc3_longest_substring_without_repeating_characters) |  |  |
| LC16 | [3sum Closest](./algorithms/two_pointers/lc16_3sum_closest) |  |  |
| LC27 | [Remove Element](./algorithms/two_pointers/lc27_remove_element) | Easy | 双指针 |
| LC30 | [Substring With Concatenation Of All Words](./algorithms/two_pointers/lc30_substring_with_concatenation_of_all_words) |  |  |
| LC76 | [Minimum Window Substring](./algorithms/two_pointers/lc76_minimum_window_substring) | Hard | 滑动窗口 |
| LC88 | [Merge Sorted Array](./algorithms/two_pointers/lc88_merge_sorted_array) | Easy |  |
| LC142 | [Link List Cycle II](./algorithms/two_pointers/lc142_link_list_cycle_ii) | Medium | 快慢指针 |
| LC167 | [Two Sum II](./algorithms/two_pointers/lc167_two_sum_ii) | Easy |  |

### Data Structures

#### Array

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| DataStructure.DynamicArray | [Dynamic Array](./data_structures/array/ds_dynamic_array) |  |  |
| DataStructure.StaticArray | [Static Array](./data_structures/array/ds_static_array) |  |  |

#### Graph

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC210 | [Course Schedule Ii](./data_structures/graph/lc210_course_schedule_ii) |  |  |
| LC444 | [Sequence Reconstruction](./data_structures/graph/lc444_sequence_reconstruction) |  |  |
| LC785 | [Is Graph Bipartite](./data_structures/graph/lc785_is_graph_bipartite) |  |  |

#### Linked List

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC21 | [Merge Two Sorted Lists](./data_structures/linked_list/lc21_merge_two_sorted_lists) |  |  |
| LC24 | [Swap Nodes In Pairs](./data_structures/linked_list/lc24_swap_nodes_in_pairs) |  |  |
| LC61 | [Rotate List](./data_structures/linked_list/lc61_rotate_list) |  |  |
| LC86 | [Partition List](./data_structures/linked_list/lc86_partition_list) |  |  |
| LC160 | [Intersection Of Two Linked List](./data_structures/linked_list/lc160_intersection_of_two_linked_list) |  |  |
| LC206 | [Reverse Linked List](./data_structures/linked_list/lc206_reverse_linked_list) |  |  |
| LC234 | [Palindrome Linked List](./data_structures/linked_list/lc234_palindrome_linked_list) |  |  |
| LC641 | [Design Circular Deque](./data_structures/linked_list/lc641_design_circular_deque) |  |  |

#### Other

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC146 | [Lru Cache](./data_structures/other/lc146_lru_cache) |  |  |
| LC303 | [Range Sum Query](./data_structures/other/lc303_range_sum_query) |  |  |
| LC304 | [Range Sum Query 2d](./data_structures/other/lc304_range_sum_query_2d) |  |  |
| LC503 | [Next Greater Element Ii](./data_structures/other/lc503_next_greater_element_ii) |  |  |
| LC560 | [Subarray Sum Equals K](./data_structures/other/lc560_subarray_sum_equals_k) |  |  |
| LC684 | [Redundant Connection](./data_structures/other/lc684_redundant_connection) |  |  |
| LC729 | [My Calendar I](./data_structures/other/lc729_my_calendar_i) |  |  |
| LC739 | [Daily Temperatures](./data_structures/other/lc739_daily_temperatures) |  |  |
| LC1109 | [Corporate Flight Bookings](./data_structures/other/lc1109_corporate_flight_bookings) |  |  |

#### Queue

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC232 | [Implement Queue Using Stacks](./data_structures/queue/lc232_implement_queue_using_stacks) | Easy |  |

#### Tree

| ID | Name | Difficulty | Tip |
| :-- | :--- | :--------- | :-- |
| LC98 | [Validate Binary Search Tree](./data_structures/tree/lc98_validate_binary_search_tree) |  |  |
| LC99 | [Recover Binary Search Tree](./data_structures/tree/lc99_recover_binary_search_tree) |  |  |
| LC101 | [Symmetric Tree](./data_structures/tree/lc101_symmetric_tree) |  |  |
| LC102 | [Binary Tree Level Order Traversal](./data_structures/tree/lc102_binary_tree_level_order_traversal) |  |  |
| LC104 | [Maximum Depth Of Binary Tree](./data_structures/tree/lc104_maximum_depth_of_binary_tree) |  |  |
| LC105 | [Construct Binary Tree](./data_structures/tree/lc105_construct_binary_tree) |  |  |
| LC110 | [Balanced Binary Tree](./data_structures/tree/lc110_balanced_binary_tree) |  |  |
| LC112 | [Path Sum](./data_structures/tree/lc112_path_sum) |  |  |
| LC116 | [Populating Next Right Pointers In Each Node](./data_structures/tree/lc116_populating_next_right_pointers_in_each_node) |  |  |
| LC117 | [Populating Next Right Pointers In Each Node Ii](./data_structures/tree/lc117_populating_next_right_pointers_in_each_node_ii) |  |  |
| LC144 | [Binary Tree Preorder Traversal](./data_structures/tree/lc144_binary_tree_preorder_traversal) |  |  |
| LC208 | [Implement Trie](./data_structures/tree/lc208_implement_trie) |  |  |
| LC437 | [Path Sum Iii](./data_structures/tree/lc437_path_sum_iii) |  |  |
| LC543 | [Diameter Of Binary Tree](./data_structures/tree/lc543_diameter_of_binary_tree) |  |  |
| LC637 | [Average Of Levels In Binary Tree](./data_structures/tree/lc637_average_of_levels_in_binary_tree) |  |  |
| LC669 | [Trim A Binary Search Tree](./data_structures/tree/lc669_trim_a_binary_search_tree) |  |  |
| LC1110 | [Delete Nodes And Return Forest](./data_structures/tree/lc1110_delete_nodes_and_return_forest) |  |  |
<!-- exercise-index:end -->

## Reference

- [LeetCode 101](https://github.com/changgyhub/leetcode_101)
- [williamfiset/Algorithms](https://github.com/williamfiset/Algorithms)
- [LabuLadong](https://labuladong.gitee.io/algo/)
