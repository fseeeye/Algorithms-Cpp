#include "my_calendar_i.h"

// Time:  O()
// Space: O()
bool MyCalendar::book(int start, int end)
{
	// add flag
	calendar[start]++;
	calendar[end]--;

	// calc concurrent task
	int concurrent = 0;
	for (auto& [k, v] : calendar)
	{
		concurrent += v;

		if (concurrent > 1)
		{
			calendar[start]--;
			calendar[end]++;
			return false;
		}
	}

	return true;
}
