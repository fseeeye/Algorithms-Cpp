// 并查集
// OJ: https://leetcode.cn/problems/redundant-connection/
#pragma once

#include <iostream>
#include <vector>

#include "Tester.h"
#include "Structures.h"

class Solution684 {
public:
	static std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);

	static void test() {
		
		std::cout << "Solution 684 passed!\n";
	}
};

class UF {
public:
	UF(int capacity)
		: id(capacity), size(capacity, 1)
	{
		std::iota(id.begin(), id.end(), 0); // vector 初始化为 0..n-1
	}

	int Find(int p) {
		while (id[p] != p) { // 如果 current p 的祖先不是它自己
			id[p] = id[id[p]]; // *路径压缩*：在查找时顺便压缩祖先迭代层级，另下一次搜索更快
			p = id[p]; // 更新 current p
		}
		return p;
	}

	void Union(int p, int q) {
		int qf = Find(q), pf = Find(p);
		// *按秩合并*：每次合并都把深度较小的集合合并在深度较大的集合下面
		if (qf != pf) {
			if (size[pf] > size[qf]) {
				id[qf] = pf; // 合并，设置祖先
				size[pf] += size[qf]; // 更新 size
			}
			else {
				id[pf] = qf;
				size[qf] += size[pf];
			}
		}
	}

	bool IsUnion(int p, int q) {
		return Find(p) == Find(q);
	}

private:
	std::vector<int> id; // 记录所属并查集祖先
	std::vector<int> size; // 记录该节点下方深度(它是多少个节点的祖先)
};

