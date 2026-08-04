#include "lcof.h"

#include <algorithm>

namespace AlgoCpp::Problem::Algorithm::LCOF45
{

	// Time:  O(NlogN)
	// Space: O(N)
	std::string SolutionO45::minNumber(std::vector<int>& nums)
	{
		std::vector<std::string> stringValues;
		std::string result;

		for (const int value : nums)
		{
			stringValues.push_back(std::to_string(value));
		}

		std::sort(stringValues.begin(), stringValues.end(), [](const std::string& left, const std::string& right) {
			return left + right < right + left;
		});

		for (const std::string& value : stringValues)
		{
			result.append(value);
		}

		return result;
	}

} // namespace AlgoCpp::Problem::Algorithm::LCOF45
