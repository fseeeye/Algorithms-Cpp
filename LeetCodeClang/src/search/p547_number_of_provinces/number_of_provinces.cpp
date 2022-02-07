#include "number_of_provinces.h"

// Time:  O(N^2), 需要遍历矩阵中的每一个元素
// Space: O(N), 需要 visited 记录每一个访问过的城市
int Solution547::findCircleNum(std::vector<std::vector<int>>& isConnected)
{
	int circleNum = 0;
	std::vector<bool> visited(isConnected.size(), false);

	for (int k = 0; k < isConnected.size(); ++k)
	{
		if (visited[k] == false)
		{
			findCircleDFS(isConnected, k, visited);
			++circleNum;
		}
	}

	return circleNum;
}

void Solution547::findCircleDFS(std::vector<std::vector<int>>& isConnected, int idx, std::vector<bool>& visited)
{
	visited[idx] = true;

	for (int k = 0; k < isConnected.size(); ++k)
	{
		if (isConnected[idx][k] == 1 && visited[k] == false)
			findCircleDFS(isConnected, k, visited);
	}
}
