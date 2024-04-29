#include "sequence_reconstruction.h"

#include <unordered_map>
#include <unordered_set>

// Time:  O()
// Space: O()
bool Solution444::sequenceReconstruction(std::vector<int>& nums, std::vector<std::vector<int>>& sequences)
{
	std::unordered_map<int, std::unordered_set<int>> graph;
	std::unordered_map<int, int> indegree;

	// 1.建拓扑图
	for (auto& sequence : sequences) {
		if (sequence.size() != 0) {
			indegree[sequence[0]]; // 初始化 i 的入度
		}
		for (int i = 0; i < sequence.size() - 1; i++) {
			if (graph[sequence[i]].count(sequence[i + 1]) == 0) {
				graph[sequence[i]].insert(sequence[i + 1]);
				indegree[sequence[i + 1]]++;
			}
		}
	}

	// 2.尝试恢复出唯一拓扑排序
	queue<int> q;
	for (const auto& [key, value] : indegree) {
		if (value == 0) {
			q.push(key);
		}
	}
	std::vector<int> super_sequence;
	while (!q.empty()) {
		// 检查 queue 是否只有一个元素
		if (q.size() != 1) {
			return false;
		}
		// 取出元素
		int num = q.front();
		super_sequence.push_back(num);
		q.pop();
		// 更新入度与queue
		for (auto next : graph[num]) {
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	// 3.检查还原的超序列是否和 nums 对应元素相同
	return super_sequence == nums;
}
