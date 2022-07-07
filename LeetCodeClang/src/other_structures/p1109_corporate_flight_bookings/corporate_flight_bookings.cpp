#include "corporate_flight_bookings.h"

// Time:  O()
// Space: O()
std::vector<int> Solution1109::corpFlightBookings(std::vector<std::vector<int>>& bookings, int n)
{
	// std::vector<int> flights(n, 0);
	std::vector<int> adiff(n, 0);

	// 更新差分
	for (auto& booking : bookings) {
		adiff[booking[0] - 1] += booking[2];
		if (booking[1] < n) {
			adiff[booking[1]] -= booking[2];
		}
	}

	// 由差分数组还原数组
	// flights[0] = adiff[0];
	for (int i = 1; i < adiff.size(); i++) {
		// flights[i] = adiff[i] + flights[i-1];
		adiff[i] += adiff[i - 1];
	}

	return adiff;
}
