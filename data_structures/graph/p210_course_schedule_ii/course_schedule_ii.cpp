#include "course_schedule_ii.h"

#include <queue>

// Time:  O()
// Space: O()
std::vector<int> Solution210::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
	std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
	std::vector<int> indegree(numCourses, 0), rst;
	for (const std::vector<int>& prerequisite : prerequisites)
	{
		graph[prerequisite[1]].push_back(prerequisite[0]);
		++indegree[prerequisite[0]];
	}

	std::queue<int> q;
	for (int i = 0; i < numCourses; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int current_course = q.front();
		q.pop();
		rst.push_back(current_course);

		for (int next_course : graph[current_course])
		{
			--indegree[next_course];
			if (indegree[next_course] == 0)
				q.push(next_course);
		}
	}
	
	if (rst.size() < numCourses)
		return {};
	return rst;
}
