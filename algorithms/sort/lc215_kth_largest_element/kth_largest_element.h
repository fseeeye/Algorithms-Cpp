#pragma once

#include <vector>

namespace AlgoCpp::Problem::Algorithm::LC215
{

	class Solution
	{
	public:
		int findKthLargest(std::vector<int>& nums, int k);

	private:
		int QuickSelect(std::vector<int>& nums, int left, int right);
	};

} // namespace AlgoCpp::Problem::Algorithm::LC215
