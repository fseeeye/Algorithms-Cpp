#include "redundant_connection.h"

// Time:  O()
// Space: O()
std::vector<int> Solution684::findRedundantConnection(std::vector<std::vector<int>>& edges)
{
	int edgesSize = static_cast<int>(edges.size());
	UF uf(edgesSize + 1);

	for (std::vector<int>& e : edges) {
		if (uf.IsUnion(e[0], e[1])) {
			return e;
		}

		uf.Union(e[0], e[1]);
	}

	return {};
}
