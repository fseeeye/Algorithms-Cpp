#include "validate_stack_sequences.h"

#include <stack>

// Time:  O()
// Space: O()
bool Solution946::validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped)
{
	std::stack<int> s;
	int popped_ptr = 0;
	int n = static_cast<int>(pushed.size());

	for (int pushed_num : pushed)
	{
		s.push(pushed_num);

		while (s.size() > 0 && popped_ptr < n && s.top() == popped[popped_ptr])
		{
			s.pop();
			popped_ptr++;
		}
	}

	return popped_ptr == n;
}
