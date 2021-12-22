#include "p455_assign_cookies.h"

#include <algorithm>

// Time:  O()
// Space: O()
int Solution455::findContentChildren(std::vector<int>& g, std::vector<int>& s)
{
	// sort g and s
	std::sort(g.begin(), g.end());
	std::sort(s.begin(), s.end());

	int childPos = 0, cookiePos = 0;
	while (childPos < g.size() && cookiePos < s.size())
	{
		// for current child find smallest cookie
		if (s[cookiePos] >= g[childPos])
			childPos++;
		cookiePos++;
	}
	return childPos;
}
