# Algorithms-Cpp

My collection of algorithm and data structure solutions.

## Content List

- [数据结构 - 动态数组](https://github.com/fseeeye/Algorithms-Cpp/tree/master/data_structures/dynamic_array)
- [数据结构 - 链表](#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84---%E9%93%BE%E8%A1%A8)
- [数据结构 - 树](#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84---%E6%A0%91)
- [数据结构 - 图](#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84---%E5%9B%BE)
- [数据结构 - 其它](#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84---%E5%85%B6%E5%AE%83)
- [贪心算法](#%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95)
- [双指针](#%E5%8F%8C%E6%8C%87%E9%92%88)
- [二分查找](#%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)
- [排序算法](#%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)
- [优先搜索](#%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2)
- [动态规划](#%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92)
- [分治算法](#%E5%88%86%E6%B2%BB%E7%AE%97%E6%B3%95)
- [Ref](#reference)

## Solution List

### 贪心算法

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  135  | [Candy (Hard)](./algorithms/greedy_algorithm/p135_candy)  | 分配问题 |
|  435  | [Non-Overlapping Intervals (Medium)](./algorithms/greedy_algorithm/p435_non_overlapping_intervals)  | 区间问题 |
|  455  | [Assign Cookies (Easy)](./algorithms/greedy_algorithm/p455_assign_cookies)  | 分配问题 |

### 双指针

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  76   | [Minimum Window Substring (Hard)](./algorithms/two_pointers/p76_minimum_window_substring)  | 滑动窗口 |
|  88   | [Merge Sorted Array (Easy)](./algorithms/two_pointers/p88_merge_sorted_array)  |
|  142  | [Link List Cycle II (Medium)](./algorithms/two_pointers/p142_link_list_cycle_ii)  | 快慢指针 |
|  167  | [Two Sum II (Easy)](./algorithms/two_pointers/p167_two_sum_ii)  |

### 二分查找

[模板总结](./algorithms/binary_search/template/)

|  QID  |      Name      |
| :---: |     :----:     |
|  34   | [Find First and Last Position of Element in Sorted Array (Easy)](./algorithms/binary_search/p34_find_ele_in_sorted_array)  | 查找区间 |
|  69   | [Sqrt(x) (Easy)](./algorithms/binary_search/p69_sqrtx)  | 开方 |
|  81   | [Search In Rotated Sorted Array II (Medium)](./algorithms/binary_search/p81_search_in_rotated_sorted_array_ii)  | 旋转数组 |

### 排序算法

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  215  | [Kth Largest Element (Medium)](./algorithms/sort/p215_kth_largest_element)  | 快速选择 |
|  347  | [Top k Frequent Elements (Medium)](./algorithms/sort/p347_top_k_frequent_elements)  | 桶排序 |

### 优先搜索

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  417  | [Pacific Atlantic Waterflow (Medium)](./algorithms/search/p417_pacific_atlantic_water_flow)  | 深度优先搜索 |
|  547  | [Number of Provinces (Medium)](./algorithms/search/p547_number_of_provinces)  | 深度优先搜索 |
|  695  | [Max Area of Island (Medium)](./algorithms/search/p695_max_area_of_island)  | 深度优先搜索 |
|  46   | [Permutations (Medium)](./algorithms/search/p46_permutations)  | 回溯法 |
|  51   | [N-Queens (Hard)](./algorithms/search/p51_n_queens)  | 回溯法 |
|  77   | [Combinations (Medium)](./algorithms/search/p77_combinations)  | 回溯法 |
|  79   | [Word Search (Medium)](./algorithms/search/p79_word_search)  | 回溯法 |
|  126  | [Word Ladder II (Hard)](./algorithms/search/p126_word_ladder_ii)  | 广度优先搜索 |
|  934  | [Shortest Bridge (Medium)](./algorithms/search/p934_shortest_bridge)  | 广度优先搜索 |

### 动态规划

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  70   | [Climbing Stairs (Easy)](./algorithms/dynamic_programming/p70_climbing_stairs)  | 一维 |
|  198  | [Hourse Robber (Easy)](./algorithms/dynamic_programming/p198_house_robber)  | 一维 |
|  413  | [Arithmetic Slices (Medium)](./algorithms/dynamic_programming/p413_arithmetic_slices)  | 一维 |
|  64   | [Minimum Path Sum (Medium)](./algorithms/dynamic_programming/p64_mini_path_sum)  | 二维 |
|  542  | [0-1 Matrix (Medium)](./algorithms/dynamic_programming/p542_01_matrix)  | 二维 |
|  221  | [Maximal Square (Medium)](./algorithms/dynamic_programming/p221_maximal_square)  | 二维 |
|  279  | [Perfect Square (Medium)](./algorithms/dynamic_programming/p279_perfect_squares)  | 分割问题 |
|  91   | [Decode Ways (Medium)](./algorithms/dynamic_programming/p91_decode_ways)  | 分割问题 |
|  139  | [Word Break (Medium)](./algorithms/dynamic_programming/p139_word_break)  | 分割问题 |
|  300  | [Logest Increasing Subsequence (Medium)](./algorithms/dynamic_programming/p300_longest_increasing_subsequence)  | 子序列问题 |
|  1143 | [Logest Common Subsequence (Medium)](./algorithms/dynamic_programming/p1143_longest_commom_subsequence)  | 子序列问题 |
|  416  | [Partition Equal Subset Sum (Medium)](./algorithms/dynamic_programming/p416_partition_equal_subset_sum)  | 背包问题 |
|  474  | [Ones and Zeros (Medium)](./algorithms/dynamic_programming/p474_ones_and_zeroes)  | 0-1背包问题 |
|  322  | [Coin Change (Medium)](./algorithms/dynamic_programming/p322_coin_change)  | 完全背包问题 |
|  72   | [Edit Distance (Hard)](./algorithms/dynamic_programming/p72_edit_distance)  | 字符串编辑问题 |
|  650  | [2 Keys Keyboard (Medium)](./algorithms/dynamic_programming/p650_2_keys_keyboard)  | 字符串编辑问题 |
|  10   | [Regular Expression Matching (Hard)](./algorithms/dynamic_programming/p10_regular_expression_matching)  | 字符串编辑问题 |
|  121  | [Best Time to Buy and Sell Stock (Easy)](./algorithms/dynamic_programming/p121_best_time_to_buy_and_sell_stock)  | 股票交易问题 |
|  188  | [Best Time to Buy and Sell Stock IV (Hard)](./algorithms/dynamic_programming/p188_best_time_to_buy_and_sell_stock_iv)  | 股票交易问题 |
|  309  | [Best Time to Buy and Sell Stock with Cooldown (Medium)](./algorithms/dynamic_programming/p188_best_time_to_buy_and_sell_stock_iv)  | 股票交易问题 |


### 分治算法

|  QID  |      Name      |
| :---: |     :----:     |
|  241  | [Different Ways to Add Parentheses](./algorithms/divide_conquer/p241_different_ways_to_add_parentheses)  |

### 数据结构 - 链表

|  QID  |      Name      |
| :---: |     :----:     |
|  21   | [Merge Two Sorted List (Easy)](./algorithms/linked_list/p21_merge_two_sorted_lists)  |
|  24   | [Swap Nodes in Pairs (Easy)](./algorithms/linked_list/p24_swap_nodes_in_pairs)  |
|  160  | [Intersection of Two Linked Lists (Easy)](./algorithms/linked_list/p160_intersection_of_two_linked_list)  |
|  206  | [Reverse Linked List (Easy)](./algorithms/linked_list/p206_reverse_linked_list)  |
|  234  | [Palindrome Linked List (Easy)](./algorithms/linked_list/p234_palindrome_linked_list)  |

### 数据结构 - 树

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  104  | [Maximum Depth of Binary Tree (Easy)](./algorithms/tree/p104_maximum_depth_of_binary_tree)  | 二叉树递归遍历 |
|  110  | [Balanced Binary Tree (Easy)](./algorithms/tree/p110_balanced_binary_tree)  | 二叉树递归遍历 |
|  543  | [Diameter of Binary Tree (Easy)](./algorithms/tree/p543_diameter_of_binary_tree)  | 二叉树递归遍历 |
|  437  | [Path Sum III (Medium)](./algorithms/tree/p437_path_sum_iii)  | 二叉树递归遍历 |
|  101  | [Symmetric Tree (Easy)](./algorithms/tree/p110_balanced_binary_tree)  | 二叉树递归遍历 |
|  1110 | [Delete Nodes And Return Forest (Medium)](./algorithms/tree/p1110_delete_nodes_and_return_forest)  | 二叉树递归遍历 |
|  637  | [Average of Levels in Binary Tree (Easy)](./algorithms/tree/p637_average_of_levels_in_binary_tree)  | 二叉树层次遍历 |
|  105  | [Construct Binary Tree from Preorder and Inorder Traversal (Medium)](./algorithms/tree/p105_construct_binary_tree)  | 二叉树前中序遍历 |
|  144  | [Binary Tree Preorder Traversal (Easy)](./algorithms/tree/p144_binary_tree_preorder_traversal)  | 二叉树前序遍历 |
|  99   | [Recover Binary Search Tree (Medium)](./algorithms/tree/p99_recover_binary_search_tree)  | 二叉查找树 |
|  669  | [Trim a Binary Search Tree (Easy)](./algorithms/tree/p669_trim_a_binary_search_tree) | 二叉查找树 |
|  208  | [Implement Trie (Prefix Tree) (Medium)](./algorithms/tree/p208_implement_trie) | 前缀树 / 字典树 |

### 数据结构 - 图

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  785  | [Is Graphy Bipartite? (Medium)](./algorithms/graph/p785_is_graph_bipartite) | 二分图 |
|  210  | [Course Schedule II (Medium)](./algorithms/graph/p210_course_schedule_ii) | 拓扑排序 |

### 数据结构 - 其它

|  QID  |      Name      |      Tip      |
| :---: |     :----:     |     :----:    |
|  210  | [LRU Cache (Medium)](./algorithms/other_structures/p146_lru_cache) | LRU |


## Reference

- [LeetCode 101](https://github.com/changgyhub/leetcode_101)
- [williamfiset/Algorithms](https://github.com/williamfiset/Algorithms)
- [LabuLadong](https://labuladong.gitee.io/algo/)
